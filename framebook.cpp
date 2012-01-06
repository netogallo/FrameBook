#include "framebook.h"
#include <QPainter>
#include <QFontMetrics>
#include <QSizeF>
#include <QPushButton>
#include <QGraphicsLinearLayout>
#include <QObject>
#include <Plasma/Applet>
#include <plasma/widgets/pushbutton.h>
#include <QHttp>
#include <stdio.h>
#include <QWebView>
#include <kconfigdialog.h>
#include <QList>
#include <QPair>
#include <QString>
#include <qjson/parser.h>
#include <QDebug>
#include <QSizePolicy>
#include <QTimer>
 
FrameBook::FrameBook(QObject *parent,const QVariantList &args)
  : Plasma::Applet(parent, args)
{
  //init();
  //setApplet(applet);
}

FrameBook::~FrameBook()
{
  
}
 
void FrameBook::init()
{

  api=new FbApi(this);
  api->id="317511414947451";  
  connect(api,SIGNAL(picsLoaded()),this,SLOT(nextImage()));
  connect(api,SIGNAL(picLoaded(QString*)),this,SLOT(setImage(QString*)));
  layout=new QGraphicsLinearLayout(Qt::Vertical,this);

  nextBtn = new Plasma::PushButton(this);
  nextBtn->setMaximumHeight(25);
  timer=new QTimer(this);
  timeout=5000;
  connect(timer,SIGNAL(timeout()),this,SLOT(nextImage()));

  nextBtn->setText("Next Image");
  image=new Plasma::Label(this);

  connect(nextBtn,SIGNAL(clicked()),this,SLOT(nextImage()));  
  
  layout->addItem(image);
  layout->addItem(nextBtn);

  setLayout(layout);
  nextImage();
} 

void FrameBook::nextImage(){

  timer->stop();  
  if(api->nextPicture())
    timer->start(timeout);

}

void FrameBook::setImage(QString * path){
    image->setImage(*path);
}

void FrameBook::createConfigurationInterface(KConfigDialog * parent){

  fbAuth=new QWebView();
  connect(fbAuth,SIGNAL(urlChanged(QUrl)),this,SLOT(onUrlChanged(QUrl)));
  fbAuth->load(api->getLoginUrl());
  parent->addPage(fbAuth, "Facebook Account");
}

void FrameBook::onUrlChanged(QUrl url){
  
  url=QUrl(url.toString().replace("#","?"));
  printf(qPrintable(url.toString()));

  printf("\n\n");
  if(url.hasQueryItem("access_token")){

    printf("Yei: ");
    printf(qPrintable(url.queryItemValue("access_token")));
    api->token=url.queryItemValue("access_token");    
    api->getPicsId();
    
  }else{
    printf("Nay: ");
    printf(qPrintable(url.queryItemValue("api_key")));
  }
	         
}

// This is the command that links your applet to the .desktop file
K_EXPORT_PLASMA_APPLET(framebook, FrameBook)
#include "framebook.moc"
