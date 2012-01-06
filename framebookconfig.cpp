#include "framebookconfig.h"
#include "ui_framebookconfig.h"
#include <QProcess>
#include <QDebug>

FrameBookConfig::FrameBookConfig(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FrameBookConfig)
{
    ui->setupUi(this);
    ui->kcfg_pass->setEchoMode(QLineEdit::Password);
    connect(ui->installLabel,SIGNAL(linkActivated(QString)),this,SLOT(openBrowser(QString)));
    
}

FrameBookConfig::~FrameBookConfig()
{
    delete ui;
}

void FrameBookConfig::openBrowser(QString link){

  qDebug() << link;
  cmd.start("xdg-open",QStringList() << link);
}

void FrameBookConfig::setAttributes(QString user,QString pass){

  ui->kcfg_user->setText(user);
  ui->kcfg_pass->setText(pass);
}

QString FrameBookConfig::getUser(){

  return ui->kcfg_user->text();
}

QString FrameBookConfig::getPass(){

  return ui->kcfg_pass->text();
}

void FrameBookConfig::setInstallURL(QString url){

  ui->installLabel->setText((QString("You must add the FrameBook application to your Facebook account by clicking <a href=\"").append(url)).append("\">here.</a>"));
}
