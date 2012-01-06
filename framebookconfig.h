#ifndef FRAMEBOOKCONFIG_H
#define FRAMEBOOKCONFIG_H

#include <QWidget>
#include <QProcess>

namespace Ui {
class FrameBookConfig;
}

class FrameBookConfig : public QWidget
{
    Q_OBJECT
    
public:
    explicit FrameBookConfig(QWidget *parent = 0);
    ~FrameBookConfig();
    QString getPass();
    QString getUser();
    void setAttributes(QString user,QString pass);
    void setInstallURL(QString url);
    
    public Q_SLOTS:
    void openBrowser(QString link);
    
 private:
    Ui::FrameBookConfig *ui;
    QProcess cmd;
};

#endif // FRAMEBOOKCONFIG_H
