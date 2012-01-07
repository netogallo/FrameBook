// Here we avoid loading the header multiple times
#ifndef Tutorial1_HEADER
#define Tutorial1_HEADER
// We need the Plasma Applet headers
#include <Plasma/Applet>
#include <QObject>
#include <QGraphicsLinearLayout>
#include <plasma/widgets/label.h>
#include <plasma/widgets/pushbutton.h>
#include <QHttp>
#include <QFile>
#include <QWebView>
#include <fbApi.h>
#include <kconfigdialog.h>
#include <qjson/parser.h>
#include <QTimer>
#include <framebookconfig.h>
#include <framebookSettings.h>
 
class QSizeF;
 
// Define our plasma Applet
class FrameBook : public Plasma::Applet
{
  Q_OBJECT
    public:
  // Basic Create/Destroy
  FrameBook(QObject *parent,const QVariantList &args);
  ~FrameBook(); 
  void init();

  public Q_SLOTS:
    void nextImage();
    //void onUrlChanged(QUrl url);
    void setImage(QString * path);
    void updateSettings(QString dialog);
    void setImgSize();

 private:
  QGraphicsLinearLayout * layout;
  FrameBookConfig * config;
  Plasma::Label * image;
  QHttp *http;
  QFile *tmpFile;
  QString tmpLoc;
  FbApi *api;
  //QWebView * fbAuth;
  void createConfigurationInterface(KConfigDialog * parent);  
  QJson::Parser parser;
  Plasma::PushButton * nextBtn;
  QTimer * timer;
  int timeout;
  FrameBookSettings *settings;
};
 
#endif
