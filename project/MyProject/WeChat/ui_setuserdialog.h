/********************************************************************************
** Form generated from reading UI file 'setuserdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETUSERDIALOG_H
#define UI_SETUSERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetUserDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *wdg_1;
    QHBoxLayout *horizontalLayout;
    QLabel *lb_icon;
    QComboBox *cbx_icon;
    QWidget *wdg_2;
    QGridLayout *gridLayout;
    QLabel *lb_name;
    QLineEdit *le_name;
    QLabel *lb_feeling;
    QLineEdit *le_feeling;
    QSpacerItem *verticalSpacer;
    QPushButton *pb_set;

    void setupUi(QDialog *SetUserDialog)
    {
        if (SetUserDialog->objectName().isEmpty())
            SetUserDialog->setObjectName(QStringLiteral("SetUserDialog"));
        SetUserDialog->resize(261, 350);
        SetUserDialog->setMinimumSize(QSize(261, 350));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        SetUserDialog->setFont(font);
        verticalLayout = new QVBoxLayout(SetUserDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, -1);
        wdg_1 = new QWidget(SetUserDialog);
        wdg_1->setObjectName(QStringLiteral("wdg_1"));
        wdg_1->setMinimumSize(QSize(261, 71));
        wdg_1->setMaximumSize(QSize(16777215, 71));
        horizontalLayout = new QHBoxLayout(wdg_1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lb_icon = new QLabel(wdg_1);
        lb_icon->setObjectName(QStringLiteral("lb_icon"));

        horizontalLayout->addWidget(lb_icon);

        cbx_icon = new QComboBox(wdg_1);
        cbx_icon->setObjectName(QStringLiteral("cbx_icon"));
        cbx_icon->setMinimumSize(QSize(70, 50));
        cbx_icon->setMaximumSize(QSize(70, 50));
        cbx_icon->setMaxVisibleItems(6);

        horizontalLayout->addWidget(cbx_icon);


        verticalLayout->addWidget(wdg_1);

        wdg_2 = new QWidget(SetUserDialog);
        wdg_2->setObjectName(QStringLiteral("wdg_2"));
        wdg_2->setMinimumSize(QSize(261, 120));
        wdg_2->setMaximumSize(QSize(16777215, 120));
        gridLayout = new QGridLayout(wdg_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lb_name = new QLabel(wdg_2);
        lb_name->setObjectName(QStringLiteral("lb_name"));

        gridLayout->addWidget(lb_name, 0, 0, 1, 1);

        le_name = new QLineEdit(wdg_2);
        le_name->setObjectName(QStringLiteral("le_name"));
        le_name->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(le_name, 0, 1, 1, 1);

        lb_feeling = new QLabel(wdg_2);
        lb_feeling->setObjectName(QStringLiteral("lb_feeling"));

        gridLayout->addWidget(lb_feeling, 1, 0, 1, 1);

        le_feeling = new QLineEdit(wdg_2);
        le_feeling->setObjectName(QStringLiteral("le_feeling"));
        le_feeling->setMinimumSize(QSize(0, 30));
        le_feeling->setClearButtonEnabled(true);

        gridLayout->addWidget(le_feeling, 1, 1, 1, 1);


        verticalLayout->addWidget(wdg_2);

        verticalSpacer = new QSpacerItem(20, 117, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pb_set = new QPushButton(SetUserDialog);
        pb_set->setObjectName(QStringLiteral("pb_set"));
        pb_set->setMinimumSize(QSize(75, 30));
        pb_set->setMaximumSize(QSize(10000, 10000));

        verticalLayout->addWidget(pb_set);


        retranslateUi(SetUserDialog);

        QMetaObject::connectSlotsByName(SetUserDialog);
    } // setupUi

    void retranslateUi(QDialog *SetUserDialog)
    {
        SetUserDialog->setWindowTitle(QApplication::translate("SetUserDialog", "Dialog", 0));
        lb_icon->setText(QApplication::translate("SetUserDialog", "\345\244\264\345\203\217", 0));
        lb_name->setText(QApplication::translate("SetUserDialog", "\346\230\265\347\247\260", 0));
        lb_feeling->setText(QApplication::translate("SetUserDialog", "\344\270\252\346\200\247\347\255\276\345\220\215", 0));
        le_feeling->setText(QApplication::translate("SetUserDialog", "\346\257\224\350\276\203\346\207\222,\344\273\200\344\271\210\344\271\237\346\262\241\345\206\231", 0));
        pb_set->setText(QApplication::translate("SetUserDialog", "\350\256\276\347\275\256", 0));
    } // retranslateUi

};

namespace Ui {
    class SetUserDialog: public Ui_SetUserDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUSERDIALOG_H
