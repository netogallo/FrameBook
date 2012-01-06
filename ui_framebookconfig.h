/********************************************************************************
** Form generated from reading UI file 'framebookconfig.ui'
**
** Created: Fri Jan 6 22:19:16 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMEBOOKCONFIG_H
#define UI_FRAMEBOOKCONFIG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrameBookConfig
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *title;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *kcfg_user;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *kcfg_pass;
    QSpacerItem *horizontalSpacer;
    QLabel *installLabel;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *FrameBookConfig)
    {
        if (FrameBookConfig->objectName().isEmpty())
            FrameBookConfig->setObjectName(QString::fromUtf8("FrameBookConfig"));
        FrameBookConfig->resize(400, 300);
        FrameBookConfig->setStyleSheet(QString::fromUtf8("#title{\n"
"	color: #4378d9;\n"
"	font-size:22px;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(FrameBookConfig);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        title = new QLabel(FrameBookConfig);
        title->setObjectName(QString::fromUtf8("title"));

        verticalLayout_2->addWidget(title);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FrameBookConfig);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        kcfg_user = new QLineEdit(FrameBookConfig);
        kcfg_user->setObjectName(QString::fromUtf8("kcfg_user"));

        horizontalLayout->addWidget(kcfg_user);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(FrameBookConfig);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        kcfg_pass = new QLineEdit(FrameBookConfig);
        kcfg_pass->setObjectName(QString::fromUtf8("kcfg_pass"));

        horizontalLayout_2->addWidget(kcfg_pass);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_3);

        installLabel = new QLabel(FrameBookConfig);
        installLabel->setObjectName(QString::fromUtf8("installLabel"));

        verticalLayout_2->addWidget(installLabel);

        verticalSpacer = new QSpacerItem(20, 182, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        retranslateUi(FrameBookConfig);

        QMetaObject::connectSlotsByName(FrameBookConfig);
    } // setupUi

    void retranslateUi(QWidget *FrameBookConfig)
    {
        FrameBookConfig->setWindowTitle(QApplication::translate("FrameBookConfig", "Form", 0, QApplication::UnicodeUTF8));
        title->setText(QApplication::translate("FrameBookConfig", "Facebook Account: ", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FrameBookConfig", "Username: ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("FrameBookConfig", "Password: ", 0, QApplication::UnicodeUTF8));
        installLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FrameBookConfig: public Ui_FrameBookConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMEBOOKCONFIG_H
