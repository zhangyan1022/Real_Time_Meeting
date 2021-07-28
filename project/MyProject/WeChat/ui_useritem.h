/********************************************************************************
** Form generated from reading UI file 'useritem.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERITEM_H
#define UI_USERITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserItem
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *wdg_1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pb_icon;
    QWidget *wdg_2;
    QVBoxLayout *verticalLayout;
    QLabel *lb_name;
    QLabel *lb_feeling;

    void setupUi(QWidget *UserItem)
    {
        if (UserItem->objectName().isEmpty())
            UserItem->setObjectName(QStringLiteral("UserItem"));
        UserItem->resize(260, 60);
        UserItem->setMinimumSize(QSize(260, 60));
        UserItem->setMaximumSize(QSize(16777215, 60));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        UserItem->setFont(font);
        horizontalLayout = new QHBoxLayout(UserItem);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        wdg_1 = new QWidget(UserItem);
        wdg_1->setObjectName(QStringLiteral("wdg_1"));
        wdg_1->setStyleSheet(QLatin1String("QWidget:hover{ background-color: rgb(214, 214, 214);}\n"
""));
        horizontalLayout_2 = new QHBoxLayout(wdg_1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 5, -1, 5);
        pb_icon = new QPushButton(wdg_1);
        pb_icon->setObjectName(QStringLiteral("pb_icon"));
        pb_icon->setMinimumSize(QSize(40, 40));
        pb_icon->setMaximumSize(QSize(40, 40));
        QIcon icon;
        icon.addFile(QStringLiteral(":/tx/9.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_icon->setIcon(icon);
        pb_icon->setIconSize(QSize(40, 40));
        pb_icon->setFlat(true);

        horizontalLayout_2->addWidget(pb_icon);

        wdg_2 = new QWidget(wdg_1);
        wdg_2->setObjectName(QStringLiteral("wdg_2"));
        verticalLayout = new QVBoxLayout(wdg_2);
        verticalLayout->setSpacing(3);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lb_name = new QLabel(wdg_2);
        lb_name->setObjectName(QStringLiteral("lb_name"));

        verticalLayout->addWidget(lb_name);

        lb_feeling = new QLabel(wdg_2);
        lb_feeling->setObjectName(QStringLiteral("lb_feeling"));

        verticalLayout->addWidget(lb_feeling);


        horizontalLayout_2->addWidget(wdg_2);


        horizontalLayout->addWidget(wdg_1);


        retranslateUi(UserItem);

        QMetaObject::connectSlotsByName(UserItem);
    } // setupUi

    void retranslateUi(QWidget *UserItem)
    {
        UserItem->setWindowTitle(QApplication::translate("UserItem", "Form", 0));
        pb_icon->setText(QString());
        lb_name->setText(QApplication::translate("UserItem", "\351\232\224\345\243\201\350\200\201\347\216\213", 0));
        lb_feeling->setText(QApplication::translate("UserItem", "\346\210\221\345\277\203\351\243\236\346\211\254", 0));
    } // retranslateUi

};

namespace Ui {
    class UserItem: public Ui_UserItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERITEM_H
