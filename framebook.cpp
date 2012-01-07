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
#include <framebookconfig.h>
//#include <framebookSettings.h>
 
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
  connect(this,SIGNAL(geometryChanged()),this,SLOT(setImgSize()));
  setImgSize();
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
  layout->setAlignment(image,Qt::AlignHCenter);

  setLayout(layout);
  nextImage();
  api->authenticate();
} 

void FrameBook::nextImage(){

  timer->stop();  
  if(api->nextPicture())
    timer->start(timeout);

}

void FrameBook::setImage(QString * path){
  
  qDebug() << size();
  
  image->setImage(*path);
}

void FrameBook::setImgSize(){

  api->imgWidth=qRound(size().width());
  api->imgHeight=qRound(size().height());
}

void FrameBook::createConfigurationInterface(KConfigDialog * parent){

  //delete config;
  settings = new FrameBookSettings();
  config = new FrameBookConfig(parent);
  config->setInstallURL(api->getLoginUrl().toString());
  //config->setAttributes(*api->user,*api->pass);
  connect(parent,SIGNAL(settingsChanged(QString)),this,SLOT(updateSettings(QString)));
  parent->addPage(config,settings, "Facebook Account","Image");
}

void FrameBook::updateSettings(QString dialog){

  api->saveCredentials(config->getUser(),config->getPass());
  api->authenticate();
}

// This is the command that links your applet to the .desktop file
K_EXPORT_PLASMA_APPLET(framebook, FrameBook)
#include "framebook.moc"
