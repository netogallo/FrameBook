#include <QString>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <qjson/parser.h>
#include <QFile>
#include <KConfig>
#include <KConfigGroup>
//#include <QJson>
#include <QWebPage>
#define fbUrl "https://www.facebook.com/dialog/oauth?client_id=YOUR_APP_ID&response_type=token&redirect_uri=https://www.facebook.com/connect/login_success.html&scope=user_photos,friends_photos"
#define getTagPics "https://graph.facebook.com/fql?q=SELECT+src_big+FROM+photo+WHERE+pid+IN+(SELECT+pid+FROM+photo_tag+WHERE+subject=me())&access_token=ACCESS_TOKEN"

class FbApi : public QObject{

  Q_OBJECT
 public:
  FbApi(QObject *parent=0);
  QUrl getLoginUrl();
  QString token;
  void getPicsId();
  QString id;
  QList <QString> *picList;
  bool nextPicture();
  void authenticate();
  QString * user;
  QString * pass;
  void saveCredentials(QString myUser,QString myPass);
 private:  
  QNetworkAccessManager * net;
  QNetworkReply * resp;
  QNetworkReply * picResp;
  QJson::Parser parser;
  QFile *pic;
  bool img;
  KConfig config;
  QWebPage * page;  

 signals:
  void picsLoaded();
  void picLoaded(QString* pic);  
  void loginResult(bool res);

  public Q_SLOTS:
  void loadPicList();
  void setPicture();
  void doAuthentication(bool stat);
};



