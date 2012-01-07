#include "fbApi.h"
#include <QString>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>
#include <QVariantMap>
#include <stdio.h>
#include <qjson/parser.h>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <KConfig>
#include <KConfigGroup>
#include <QWebPage>
#include <QWebFrame>
#include <QWebElement>
#include <Magick++.h> 

FbApi::FbApi(QObject * parent):QObject(parent){

  id="";
  token="";
  net=new QNetworkAccessManager(this);
  KConfigGroup imgConfig(&config,"Images");
  picList = new QList <QString> (imgConfig.readEntry("images",QList<QString>()));
  user=new QString(imgConfig.readEntry("user",QString()));
  pass=new QString(imgConfig.readEntry("pass",QString()));
  page = new QWebPage(this);  
  imgWidth=320;
  imgHeight=240;
  connect(page,SIGNAL(loadFinished(bool)),this,SLOT(doAuthentication(bool)));
}

void FbApi::authenticate(){
  
  page->mainFrame()->load(QUrl(getLoginUrl()));
}

void FbApi::doAuthentication(bool stat){

  if(stat){
    qDebug() << page->mainFrame()->url();

    QUrl url=QUrl(page->mainFrame()->url().toString().replace("#access_token","?access_token"));

    if(url.hasQueryItem("access_token")){
      qDebug() << "Yei: \n\n";
      qDebug() << url.queryItemValue("access_token");
      //qDebug() << *pass;
  
      token=url.queryItemValue("access_token");    
      getPicsId();
    }
    else if(url.hasQueryItem("login_attempt")){
      qDebug()<<"Wrong user/password";
    }
    else{
      page->mainFrame()->findFirstElement("input#email").setAttribute("value",*user);
      page->mainFrame()->findFirstElement("input#pass").setAttribute("value",*pass);
      page->mainFrame()->evaluateJavaScript("document.getElementById(\"login_form\").submit()");   
    }
  }
}

QUrl FbApi::getLoginUrl(){

  QString * url=new QString(fbUrl);
  return QUrl(url->replace("YOUR_APP_ID",id,Qt::CaseSensitive));
}

void FbApi::getPicsId(){

  QString * url=new QString(getTagPics);
  resp=net->get(QNetworkRequest(QUrl(url->replace("ACCESS_TOKEN",token,Qt::CaseSensitive))));
  connect(resp,SIGNAL(finished()),this,SLOT(loadPicList()));
}

void FbApi::saveCredentials(QString myUser,QString myPass){

  user=new QString(myUser);
  pass=new QString(myPass);

  KConfigGroup credentials(&config,"Images");
  credentials.writeEntry("user",*user);
  credentials.writeEntry("pass",*pass);
  credentials.config()->sync();
  
}

void FbApi::loadPicList(){

  bool ok;
  delete picList;
  picList = new QList<QString> ();

  foreach(QVariant pic,(parser.parse(resp->readAll(), &ok).toMap()["data"].toList()))
    (*picList).append(pic.toMap()["src_big"].toString());

  qDebug() << (*picList);
  KConfigGroup imgConfig(&config,"Images");
  imgConfig.writeEntry("images",(*picList));
  imgConfig.config()->sync();
  resp->close();
  delete resp;
  //delete picList;
  //picList=&result["data"].toList();
  emit picsLoaded();
  
}

bool FbApi::nextPicture(){

  if((*picList).size()>0){
    picResp = net->get(QNetworkRequest(QUrl((*picList).at(qrand()%((*picList).size())))));
    connect(picResp,SIGNAL(finished()),this,SLOT(setPicture()));
    return true;
  }
  return false;
}

void FbApi::setPicture(){
  QString * path;

  if(picResp->size()>1){
    if(img){
      path=new QString(QDir::tempPath().append("/framebook.jpg"));
      img=false;
    }else{
      path=new QString(QDir::tempPath().append("/framebook2.jpg"));
      img=true;
    }
    pic=new QFile(*path);
    pic->open(QIODevice::WriteOnly);
    pic->write(picResp->readAll());
    pic->close();
    Magick::Image image(qPrintable(*path));
    //image.read(qPrintable(*path));
    image.scale(Magick::Geometry(imgWidth,imgHeight,0,0));
    //image.zoom("320x240");
    image.write(qPrintable(path->replace(".jpg","r.jpg")));
    //image.write("/home/neto/testjgp.jpg");
    emit picLoaded(path);
    qDebug() << (*path);
    
  }
}
