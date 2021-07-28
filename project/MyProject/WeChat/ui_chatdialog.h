/********************************************************************************
** Form generated from reading UI file 'chatdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATDIALOG_H
#define UI_CHATDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *wdg_take;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lb_name;
    QSpacerItem *horizontalSpacer;
    QPushButton *pb_min;
    QPushButton *pb_max;
    QPushButton *pb_close;
    QWidget *wdg_main;
    QHBoxLayout *horizontalLayout;
    QWidget *wdg_left;
    QVBoxLayout *verticalLayout_2;
    QWidget *wdg_chat;
    QGridLayout *gridLayout_2;
    QTextBrowser *tb_chat;
    QWidget *wdg_tool;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pb_tool1;
    QPushButton *pu_tool2;
    QPushButton *pu_tool3;
    QPushButton *pu_tool4;
    QPushButton *pu_tool5;
    QSpacerItem *horizontalSpacer_2;
    QWidget *wdg_send;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *te_send;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pb_send;
    QWidget *wdg_right;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QWidget *tab_2;

    void setupUi(QDialog *ChatDialog)
    {
        if (ChatDialog->objectName().isEmpty())
            ChatDialog->setObjectName(QStringLiteral("ChatDialog"));
        ChatDialog->resize(500, 400);
        ChatDialog->setMinimumSize(QSize(500, 400));
        ChatDialog->setSizeGripEnabled(true);
        verticalLayout = new QVBoxLayout(ChatDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        wdg_take = new QWidget(ChatDialog);
        wdg_take->setObjectName(QStringLiteral("wdg_take"));
        wdg_take->setMinimumSize(QSize(501, 30));
        wdg_take->setMaximumSize(QSize(16777215, 30));
        horizontalLayout_2 = new QHBoxLayout(wdg_take);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        lb_name = new QLabel(wdg_take);
        lb_name->setObjectName(QStringLiteral("lb_name"));
        lb_name->setMinimumSize(QSize(72, 15));
        lb_name->setMaximumSize(QSize(72, 15));

        horizontalLayout_2->addWidget(lb_name);

        horizontalSpacer = new QSpacerItem(336, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pb_min = new QPushButton(wdg_take);
        pb_min->setObjectName(QStringLiteral("pb_min"));
        pb_min->setMinimumSize(QSize(30, 30));
        pb_min->setMaximumSize(QSize(30, 30));

        horizontalLayout_2->addWidget(pb_min);

        pb_max = new QPushButton(wdg_take);
        pb_max->setObjectName(QStringLiteral("pb_max"));
        pb_max->setMinimumSize(QSize(30, 30));
        pb_max->setMaximumSize(QSize(30, 30));

        horizontalLayout_2->addWidget(pb_max);

        pb_close = new QPushButton(wdg_take);
        pb_close->setObjectName(QStringLiteral("pb_close"));
        pb_close->setMinimumSize(QSize(30, 30));
        pb_close->setMaximumSize(QSize(30, 30));

        horizontalLayout_2->addWidget(pb_close);


        verticalLayout->addWidget(wdg_take);

        wdg_main = new QWidget(ChatDialog);
        wdg_main->setObjectName(QStringLiteral("wdg_main"));
        wdg_main->setMinimumSize(QSize(501, 371));
        horizontalLayout = new QHBoxLayout(wdg_main);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        wdg_left = new QWidget(wdg_main);
        wdg_left->setObjectName(QStringLiteral("wdg_left"));
        wdg_left->setMinimumSize(QSize(371, 371));
        verticalLayout_2 = new QVBoxLayout(wdg_left);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        wdg_chat = new QWidget(wdg_left);
        wdg_chat->setObjectName(QStringLiteral("wdg_chat"));
        wdg_chat->setMinimumSize(QSize(371, 241));
        gridLayout_2 = new QGridLayout(wdg_chat);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tb_chat = new QTextBrowser(wdg_chat);
        tb_chat->setObjectName(QStringLiteral("tb_chat"));

        gridLayout_2->addWidget(tb_chat, 0, 0, 1, 1);


        verticalLayout_2->addWidget(wdg_chat);

        wdg_tool = new QWidget(wdg_left);
        wdg_tool->setObjectName(QStringLiteral("wdg_tool"));
        wdg_tool->setMinimumSize(QSize(371, 30));
        wdg_tool->setMaximumSize(QSize(16777215, 30));
        horizontalLayout_3 = new QHBoxLayout(wdg_tool);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pb_tool1 = new QPushButton(wdg_tool);
        pb_tool1->setObjectName(QStringLiteral("pb_tool1"));
        pb_tool1->setMinimumSize(QSize(30, 30));
        pb_tool1->setMaximumSize(QSize(30, 30));
        QIcon icon;
        icon.addFile(QStringLiteral(":/bq/000.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_tool1->setIcon(icon);
        pb_tool1->setIconSize(QSize(26, 26));

        horizontalLayout_3->addWidget(pb_tool1);

        pu_tool2 = new QPushButton(wdg_tool);
        pu_tool2->setObjectName(QStringLiteral("pu_tool2"));
        pu_tool2->setMinimumSize(QSize(30, 30));
        pu_tool2->setMaximumSize(QSize(30, 30));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        pu_tool2->setIcon(icon1);
        pu_tool2->setIconSize(QSize(26, 26));

        horizontalLayout_3->addWidget(pu_tool2);

        pu_tool3 = new QPushButton(wdg_tool);
        pu_tool3->setObjectName(QStringLiteral("pu_tool3"));
        pu_tool3->setMinimumSize(QSize(30, 30));
        pu_tool3->setMaximumSize(QSize(30, 30));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/bq/001.png"), QSize(), QIcon::Normal, QIcon::Off);
        pu_tool3->setIcon(icon2);
        pu_tool3->setIconSize(QSize(26, 26));

        horizontalLayout_3->addWidget(pu_tool3);

        pu_tool4 = new QPushButton(wdg_tool);
        pu_tool4->setObjectName(QStringLiteral("pu_tool4"));
        pu_tool4->setMinimumSize(QSize(30, 30));
        pu_tool4->setMaximumSize(QSize(30, 30));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/tuer.png"), QSize(), QIcon::Normal, QIcon::Off);
        pu_tool4->setIcon(icon3);
        pu_tool4->setIconSize(QSize(26, 26));

        horizontalLayout_3->addWidget(pu_tool4);

        pu_tool5 = new QPushButton(wdg_tool);
        pu_tool5->setObjectName(QStringLiteral("pu_tool5"));
        pu_tool5->setMinimumSize(QSize(30, 30));
        pu_tool5->setMaximumSize(QSize(30, 30));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/share.png"), QSize(), QIcon::Normal, QIcon::Off);
        pu_tool5->setIcon(icon4);
        pu_tool5->setIconSize(QSize(26, 26));

        horizontalLayout_3->addWidget(pu_tool5);

        horizontalSpacer_2 = new QSpacerItem(218, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(wdg_tool);

        wdg_send = new QWidget(wdg_left);
        wdg_send->setObjectName(QStringLiteral("wdg_send"));
        wdg_send->setMinimumSize(QSize(371, 101));
        verticalLayout_3 = new QVBoxLayout(wdg_send);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        te_send = new QTextEdit(wdg_send);
        te_send->setObjectName(QStringLiteral("te_send"));

        verticalLayout_3->addWidget(te_send);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        pb_send = new QPushButton(wdg_send);
        pb_send->setObjectName(QStringLiteral("pb_send"));
        pb_send->setMinimumSize(QSize(91, 30));
        pb_send->setMaximumSize(QSize(91, 30));

        horizontalLayout_4->addWidget(pb_send);


        verticalLayout_3->addLayout(horizontalLayout_4);


        verticalLayout_2->addWidget(wdg_send);


        horizontalLayout->addWidget(wdg_left);

        wdg_right = new QWidget(wdg_main);
        wdg_right->setObjectName(QStringLiteral("wdg_right"));
        wdg_right->setMinimumSize(QSize(131, 371));
        gridLayout = new QGridLayout(wdg_right);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(wdg_right);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_1 = new QWidget();
        tab_1->setObjectName(QStringLiteral("tab_1"));
        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        horizontalLayout->addWidget(wdg_right);


        verticalLayout->addWidget(wdg_main);


        retranslateUi(ChatDialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ChatDialog);
    } // setupUi

    void retranslateUi(QDialog *ChatDialog)
    {
        ChatDialog->setWindowTitle(QApplication::translate("ChatDialog", "Dialog", 0));
        lb_name->setText(QApplication::translate("ChatDialog", "\344\270\216[]\347\232\204\350\201\212\345\244\251", 0));
        pb_min->setText(QApplication::translate("ChatDialog", "-", 0));
        pb_max->setText(QApplication::translate("ChatDialog", "\345\217\243", 0));
        pb_close->setText(QApplication::translate("ChatDialog", "\303\227", 0));
        pb_tool1->setText(QString());
        pu_tool2->setText(QString());
        pu_tool3->setText(QString());
        pu_tool4->setText(QString());
        pu_tool5->setText(QString());
        pb_send->setText(QApplication::translate("ChatDialog", "\345\217\221\351\200\201", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("ChatDialog", "1", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ChatDialog", "2", 0));
    } // retranslateUi

};

namespace Ui {
    class ChatDialog: public Ui_ChatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATDIALOG_H
