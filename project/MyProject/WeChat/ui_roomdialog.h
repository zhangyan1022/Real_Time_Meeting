/********************************************************************************
** Form generated from reading UI file 'roomdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMDIALOG_H
#define UI_ROOMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <videoform.h>
#include "imtoolbox.h"

QT_BEGIN_NAMESPACE

class Ui_RoomDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *wdg_top;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lb_roomName;
    QSpacerItem *horizontalSpacer;
    QPushButton *pb_min;
    QPushButton *pb_max;
    QPushButton *pb_close;
    QWidget *wdg_medial;
    QHBoxLayout *horizontalLayout;
    QWidget *wdg_TV;
    QVBoxLayout *verticalLayout_2;
    VideoForm *widget;
    IMToolBox *wdg_friendList;
    QWidget *wdg_down;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pb_openVideo;
    QPushButton *pb_openSound;
    QComboBox *cb_photo;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pu_leaveroom;

    void setupUi(QDialog *RoomDialog)
    {
        if (RoomDialog->objectName().isEmpty())
            RoomDialog->setObjectName(QStringLiteral("RoomDialog"));
        RoomDialog->resize(800, 600);
        RoomDialog->setMinimumSize(QSize(800, 600));
        RoomDialog->setSizeGripEnabled(true);
        verticalLayout = new QVBoxLayout(RoomDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        wdg_top = new QWidget(RoomDialog);
        wdg_top->setObjectName(QStringLiteral("wdg_top"));
        wdg_top->setMinimumSize(QSize(801, 30));
        wdg_top->setMaximumSize(QSize(16777215, 30));
        horizontalLayout_2 = new QHBoxLayout(wdg_top);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        lb_roomName = new QLabel(wdg_top);
        lb_roomName->setObjectName(QStringLiteral("lb_roomName"));
        lb_roomName->setMinimumSize(QSize(150, 30));
        lb_roomName->setMaximumSize(QSize(150, 30));

        horizontalLayout_2->addWidget(lb_roomName);

        horizontalSpacer = new QSpacerItem(598, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pb_min = new QPushButton(wdg_top);
        pb_min->setObjectName(QStringLiteral("pb_min"));
        pb_min->setMinimumSize(QSize(30, 30));
        pb_min->setMaximumSize(QSize(30, 30));

        horizontalLayout_2->addWidget(pb_min);

        pb_max = new QPushButton(wdg_top);
        pb_max->setObjectName(QStringLiteral("pb_max"));
        pb_max->setMinimumSize(QSize(30, 30));
        pb_max->setMaximumSize(QSize(30, 30));

        horizontalLayout_2->addWidget(pb_max);

        pb_close = new QPushButton(wdg_top);
        pb_close->setObjectName(QStringLiteral("pb_close"));
        pb_close->setMinimumSize(QSize(30, 30));
        pb_close->setMaximumSize(QSize(30, 30));

        horizontalLayout_2->addWidget(pb_close);


        verticalLayout->addWidget(wdg_top);

        wdg_medial = new QWidget(RoomDialog);
        wdg_medial->setObjectName(QStringLiteral("wdg_medial"));
        horizontalLayout = new QHBoxLayout(wdg_medial);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        wdg_TV = new QWidget(wdg_medial);
        wdg_TV->setObjectName(QStringLiteral("wdg_TV"));
        verticalLayout_2 = new QVBoxLayout(wdg_TV);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        widget = new VideoForm(wdg_TV);
        widget->setObjectName(QStringLiteral("widget"));

        verticalLayout_2->addWidget(widget);


        horizontalLayout->addWidget(wdg_TV);

        wdg_friendList = new IMToolBox(wdg_medial);
        wdg_friendList->setObjectName(QStringLiteral("wdg_friendList"));
        wdg_friendList->setMinimumSize(QSize(191, 521));
        wdg_friendList->setMaximumSize(QSize(191, 521));

        horizontalLayout->addWidget(wdg_friendList);


        verticalLayout->addWidget(wdg_medial);

        wdg_down = new QWidget(RoomDialog);
        wdg_down->setObjectName(QStringLiteral("wdg_down"));
        wdg_down->setMinimumSize(QSize(801, 30));
        wdg_down->setMaximumSize(QSize(16777215, 30));
        horizontalLayout_3 = new QHBoxLayout(wdg_down);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(9, 0, 9, 0);
        pb_openVideo = new QPushButton(wdg_down);
        pb_openVideo->setObjectName(QStringLiteral("pb_openVideo"));
        pb_openVideo->setMinimumSize(QSize(131, 28));
        pb_openVideo->setMaximumSize(QSize(131, 28));

        horizontalLayout_3->addWidget(pb_openVideo);

        pb_openSound = new QPushButton(wdg_down);
        pb_openSound->setObjectName(QStringLiteral("pb_openSound"));
        pb_openSound->setMinimumSize(QSize(131, 28));
        pb_openSound->setMaximumSize(QSize(131, 28));

        horizontalLayout_3->addWidget(pb_openSound);

        cb_photo = new QComboBox(wdg_down);
        cb_photo->setObjectName(QStringLiteral("cb_photo"));
        cb_photo->setMinimumSize(QSize(131, 28));
        cb_photo->setMaximumSize(QSize(131, 28));

        horizontalLayout_3->addWidget(cb_photo);

        horizontalSpacer_2 = new QSpacerItem(256, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pu_leaveroom = new QPushButton(wdg_down);
        pu_leaveroom->setObjectName(QStringLiteral("pu_leaveroom"));
        pu_leaveroom->setMinimumSize(QSize(131, 28));
        pu_leaveroom->setMaximumSize(QSize(131, 28));

        horizontalLayout_3->addWidget(pu_leaveroom);


        verticalLayout->addWidget(wdg_down);


        retranslateUi(RoomDialog);

        QMetaObject::connectSlotsByName(RoomDialog);
    } // setupUi

    void retranslateUi(QDialog *RoomDialog)
    {
        RoomDialog->setWindowTitle(QApplication::translate("RoomDialog", "Dialog", 0));
        lb_roomName->setText(QApplication::translate("RoomDialog", "\346\210\277\351\227\264\345\217\267\357\274\2320000", 0));
        pb_min->setText(QString());
        pb_max->setText(QString());
        pb_close->setText(QString());
        pb_openVideo->setText(QApplication::translate("RoomDialog", "\346\211\223\345\274\200\350\247\206\351\242\221\350\256\276\345\244\207", 0));
        pb_openSound->setText(QApplication::translate("RoomDialog", "\346\211\223\345\274\200\351\237\263\351\242\221\350\256\276\345\244\207", 0));
        cb_photo->clear();
        cb_photo->insertItems(0, QStringList()
         << QApplication::translate("RoomDialog", "\346\227\240\346\273\244\351\225\234", 0)
         << QApplication::translate("RoomDialog", "\345\205\224\345\255\220\350\200\263\346\234\265", 0)
         << QApplication::translate("RoomDialog", "\345\234\243\350\257\236\345\270\275\345\255\220", 0)
        );
        pu_leaveroom->setText(QApplication::translate("RoomDialog", "\347\246\273\345\274\200\346\210\277\351\227\264", 0));
    } // retranslateUi

};

namespace Ui {
    class RoomDialog: public Ui_RoomDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMDIALOG_H
