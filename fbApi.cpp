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

FbApi::FbApi(QObject * parent):QObject(parent){

  id="";
  token="";
  net=new QNetworkAccessManager(this);
  KConfigGroup imgConfig(&config,"Images");
  picList = new QList <QString> (imgConfig.readEntry("images",QList<QString>()));
  
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
  emit picLoaded(path);
  qDebug() << (*path);
}
