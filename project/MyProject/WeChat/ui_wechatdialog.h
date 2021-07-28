/********************************************************************************
** Form generated from reading UI file 'wechatdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WECHATDIALOG_H
#define UI_WECHATDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WeChatDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *wdg_tittle;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lb_tittle;
    QPushButton *pb_ui;
    QPushButton *pb_min;
    QPushButton *pb_close;
    QWidget *wdg_top;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pb_icon;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_3;
    QLabel *lb_name;
    QLabel *lb_feeling;
    QWidget *wdg_search;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pb_search;
    QLineEdit *le_search;
    QWidget *wdg_mid;
    QVBoxLayout *verticalLayout_4;
    QWidget *wdg_page;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pb_friend;
    QPushButton *pb_group;
    QPushButton *pb_space;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QWidget *wdg_userList;
    QSpacerItem *verticalSpacer;
    QWidget *wdg_bottom;
    QHBoxLayout *horizontalLayout;
    QPushButton *pb_menu;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;

    void setupUi(QDialog *WeChatDialog)
    {
        if (WeChatDialog->objectName().isEmpty())
            WeChatDialog->setObjectName(QStringLiteral("WeChatDialog"));
        WeChatDialog->resize(300, 600);
        WeChatDialog->setMinimumSize(QSize(300, 600));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        WeChatDialog->setFont(font);
        WeChatDialog->setSizeGripEnabled(true);
        verticalLayout = new QVBoxLayout(WeChatDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        wdg_tittle = new QWidget(WeChatDialog);
        wdg_tittle->setObjectName(QStringLiteral("wdg_tittle"));
        wdg_tittle->setMinimumSize(QSize(301, 41));
        wdg_tittle->setMaximumSize(QSize(16777215, 41));
        horizontalLayout_2 = new QHBoxLayout(wdg_tittle);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 5, -1, -1);
        lb_tittle = new QLabel(wdg_tittle);
        lb_tittle->setObjectName(QStringLiteral("lb_tittle"));
        lb_tittle->setMinimumSize(QSize(0, 30));
        lb_tittle->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_2->addWidget(lb_tittle);

        pb_ui = new QPushButton(wdg_tittle);
        pb_ui->setObjectName(QStringLiteral("pb_ui"));
        pb_ui->setMinimumSize(QSize(30, 30));
        pb_ui->setMaximumSize(QSize(30, 30));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/style.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_ui->setIcon(icon);
        pb_ui->setIconSize(QSize(24, 24));
        pb_ui->setFlat(true);

        horizontalLayout_2->addWidget(pb_ui);

        pb_min = new QPushButton(wdg_tittle);
        pb_min->setObjectName(QStringLiteral("pb_min"));
        pb_min->setMinimumSize(QSize(30, 30));
        pb_min->setMaximumSize(QSize(30, 30));
        pb_min->setIconSize(QSize(30, 30));
        pb_min->setFlat(true);

        horizontalLayout_2->addWidget(pb_min);

        pb_close = new QPushButton(wdg_tittle);
        pb_close->setObjectName(QStringLiteral("pb_close"));
        pb_close->setMinimumSize(QSize(30, 30));
        pb_close->setMaximumSize(QSize(30, 30));
        pb_close->setIconSize(QSize(30, 30));
        pb_close->setFlat(true);

        horizontalLayout_2->addWidget(pb_close);


        verticalLayout->addWidget(wdg_tittle);

        wdg_top = new QWidget(WeChatDialog);
        wdg_top->setObjectName(QStringLiteral("wdg_top"));
        wdg_top->setMinimumSize(QSize(301, 81));
        wdg_top->setMaximumSize(QSize(16777215, 81));
        horizontalLayout_3 = new QHBoxLayout(wdg_top);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pb_icon = new QPushButton(wdg_top);
        pb_icon->setObjectName(QStringLiteral("pb_icon"));
        pb_icon->setMinimumSize(QSize(60, 60));
        pb_icon->setMaximumSize(QSize(60, 60));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/tx/1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_icon->setIcon(icon1);
        pb_icon->setIconSize(QSize(60, 60));
        pb_icon->setFlat(true);

        horizontalLayout_3->addWidget(pb_icon);

        widget_6 = new QWidget(wdg_top);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        verticalLayout_3 = new QVBoxLayout(widget_6);
        verticalLayout_3->setSpacing(3);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        lb_name = new QLabel(widget_6);
        lb_name->setObjectName(QStringLiteral("lb_name"));

        verticalLayout_3->addWidget(lb_name);

        lb_feeling = new QLabel(widget_6);
        lb_feeling->setObjectName(QStringLiteral("lb_feeling"));

        verticalLayout_3->addWidget(lb_feeling);


        horizontalLayout_3->addWidget(widget_6);


        verticalLayout->addWidget(wdg_top);

        wdg_search = new QWidget(WeChatDialog);
        wdg_search->setObjectName(QStringLiteral("wdg_search"));
        wdg_search->setMinimumSize(QSize(301, 30));
        wdg_search->setMaximumSize(QSize(16777215, 30));
        horizontalLayout_4 = new QHBoxLayout(wdg_search);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(9, 0, 9, 0);
        pb_search = new QPushButton(wdg_search);
        pb_search->setObjectName(QStringLiteral("pb_search"));
        pb_search->setMinimumSize(QSize(30, 30));
        pb_search->setMaximumSize(QSize(30, 30));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/searchbox_button.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_search->setIcon(icon2);
        pb_search->setIconSize(QSize(30, 30));
        pb_search->setFlat(false);

        horizontalLayout_4->addWidget(pb_search);

        le_search = new QLineEdit(wdg_search);
        le_search->setObjectName(QStringLiteral("le_search"));
        le_search->setMinimumSize(QSize(0, 30));

        horizontalLayout_4->addWidget(le_search);


        verticalLayout->addWidget(wdg_search);

        wdg_mid = new QWidget(WeChatDialog);
        wdg_mid->setObjectName(QStringLiteral("wdg_mid"));
        wdg_mid->setMinimumSize(QSize(301, 391));
        verticalLayout_4 = new QVBoxLayout(wdg_mid);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, 5, -1, 0);
        wdg_page = new QWidget(wdg_mid);
        wdg_page->setObjectName(QStringLiteral("wdg_page"));
        wdg_page->setMinimumSize(QSize(281, 30));
        wdg_page->setMaximumSize(QSize(16777215, 30));
        horizontalLayout_5 = new QHBoxLayout(wdg_page);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        pb_friend = new QPushButton(wdg_page);
        pb_friend->setObjectName(QStringLiteral("pb_friend"));

        horizontalLayout_5->addWidget(pb_friend);

        pb_group = new QPushButton(wdg_page);
        pb_group->setObjectName(QStringLiteral("pb_group"));

        horizontalLayout_5->addWidget(pb_group);

        pb_space = new QPushButton(wdg_page);
        pb_space->setObjectName(QStringLiteral("pb_space"));

        horizontalLayout_5->addWidget(pb_space);


        verticalLayout_4->addWidget(wdg_page);

        scrollArea = new QScrollArea(wdg_mid);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 281, 371));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 0, -1, 0);
        wdg_userList = new QWidget(scrollAreaWidgetContents);
        wdg_userList->setObjectName(QStringLiteral("wdg_userList"));

        verticalLayout_2->addWidget(wdg_userList);

        verticalSpacer = new QSpacerItem(20, 358, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_4->addWidget(scrollArea);


        verticalLayout->addWidget(wdg_mid);

        wdg_bottom = new QWidget(WeChatDialog);
        wdg_bottom->setObjectName(QStringLiteral("wdg_bottom"));
        wdg_bottom->setMinimumSize(QSize(301, 40));
        wdg_bottom->setMaximumSize(QSize(16777215, 40));
        horizontalLayout = new QHBoxLayout(wdg_bottom);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 5, -1, -1);
        pb_menu = new QPushButton(wdg_bottom);
        pb_menu->setObjectName(QStringLiteral("pb_menu"));
        pb_menu->setMinimumSize(QSize(30, 30));
        pb_menu->setMaximumSize(QSize(30, 30));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/message.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_menu->setIcon(icon3);
        pb_menu->setIconSize(QSize(30, 30));
        pb_menu->setFlat(true);

        horizontalLayout->addWidget(pb_menu);

        horizontalSpacer = new QSpacerItem(136, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_8 = new QPushButton(wdg_bottom);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(30, 30));
        pushButton_8->setMaximumSize(QSize(30, 30));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/color.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon4);
        pushButton_8->setIconSize(QSize(30, 30));
        pushButton_8->setFlat(true);

        horizontalLayout->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(wdg_bottom);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setMinimumSize(QSize(30, 30));
        pushButton_9->setMaximumSize(QSize(30, 30));
        pushButton_9->setIcon(icon4);
        pushButton_9->setIconSize(QSize(30, 30));
        pushButton_9->setFlat(true);

        horizontalLayout->addWidget(pushButton_9);

        pushButton_10 = new QPushButton(wdg_bottom);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setMinimumSize(QSize(30, 30));
        pushButton_10->setMaximumSize(QSize(30, 30));
        pushButton_10->setIcon(icon4);
        pushButton_10->setIconSize(QSize(30, 30));
        pushButton_10->setFlat(true);

        horizontalLayout->addWidget(pushButton_10);


        verticalLayout->addWidget(wdg_bottom);


        retranslateUi(WeChatDialog);

        QMetaObject::connectSlotsByName(WeChatDialog);
    } // setupUi

    void retranslateUi(QDialog *WeChatDialog)
    {
        WeChatDialog->setWindowTitle(QApplication::translate("WeChatDialog", "WeChatDialog", 0));
        lb_tittle->setText(QApplication::translate("WeChatDialog", "MYQQ", 0));
        pb_ui->setText(QString());
        pb_min->setText(QApplication::translate("WeChatDialog", "\344\270\200", 0));
        pb_close->setText(QApplication::translate("WeChatDialog", "X", 0));
        pb_icon->setText(QString());
        lb_name->setText(QApplication::translate("WeChatDialog", "\346\211\223\346\255\273\345\260\217\346\227\245\346\234\254", 0));
        lb_feeling->setText(QApplication::translate("WeChatDialog", "\344\270\200\345\210\207\351\232\217\347\274\230", 0));
        pb_search->setText(QString());
        pb_friend->setText(QApplication::translate("WeChatDialog", "\345\245\275\345\217\213", 0));
        pb_group->setText(QApplication::translate("WeChatDialog", "\347\276\244\347\273\204", 0));
        pb_space->setText(QApplication::translate("WeChatDialog", "\347\251\272\351\227\264", 0));
        pb_menu->setText(QString());
        pushButton_8->setText(QString());
        pushButton_9->setText(QString());
        pushButton_10->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WeChatDialog: public Ui_WeChatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WECHATDIALOG_H
