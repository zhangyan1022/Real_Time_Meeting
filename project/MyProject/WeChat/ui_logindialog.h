/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QLabel *lb_icon;
    QTabWidget *tw_page;
    QWidget *tab_1;
    QLabel *lb_tel;
    QLineEdit *le_tel;
    QLineEdit *le_password;
    QLabel *lb_password;
    QPushButton *pb_clear;
    QPushButton *pb_login;
    QWidget *tab_2;
    QLabel *lb_tel_register;
    QPushButton *pb_clear_register;
    QLabel *lb_password_register;
    QPushButton *pb_register;
    QLineEdit *le_tel_register;
    QLineEdit *le_password_register;
    QLineEdit *le_confirm_register;
    QLabel *lb_confirm_register;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(601, 279);
        LoginDialog->setMinimumSize(QSize(601, 279));
        LoginDialog->setMaximumSize(QSize(601, 279));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        LoginDialog->setFont(font);
        lb_icon = new QLabel(LoginDialog);
        lb_icon->setObjectName(QStringLiteral("lb_icon"));
        lb_icon->setGeometry(QRect(0, 0, 161, 111));
        lb_icon->setPixmap(QPixmap(QString::fromUtf8(":/images/100.png")));
        lb_icon->setScaledContents(true);
        lb_icon->setAlignment(Qt::AlignCenter);
        tw_page = new QTabWidget(LoginDialog);
        tw_page->setObjectName(QStringLiteral("tw_page"));
        tw_page->setGeometry(QRect(190, 10, 401, 261));
        tab_1 = new QWidget();
        tab_1->setObjectName(QStringLiteral("tab_1"));
        lb_tel = new QLabel(tab_1);
        lb_tel->setObjectName(QStringLiteral("lb_tel"));
        lb_tel->setGeometry(QRect(30, 40, 54, 30));
        le_tel = new QLineEdit(tab_1);
        le_tel->setObjectName(QStringLiteral("le_tel"));
        le_tel->setGeometry(QRect(120, 40, 241, 30));
        le_password = new QLineEdit(tab_1);
        le_password->setObjectName(QStringLiteral("le_password"));
        le_password->setGeometry(QRect(120, 90, 241, 30));
        le_password->setEchoMode(QLineEdit::Password);
        lb_password = new QLabel(tab_1);
        lb_password->setObjectName(QStringLiteral("lb_password"));
        lb_password->setGeometry(QRect(30, 90, 54, 30));
        pb_clear = new QPushButton(tab_1);
        pb_clear->setObjectName(QStringLiteral("pb_clear"));
        pb_clear->setGeometry(QRect(190, 180, 70, 30));
        pb_login = new QPushButton(tab_1);
        pb_login->setObjectName(QStringLiteral("pb_login"));
        pb_login->setGeometry(QRect(290, 180, 70, 30));
        tw_page->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        lb_tel_register = new QLabel(tab_2);
        lb_tel_register->setObjectName(QStringLiteral("lb_tel_register"));
        lb_tel_register->setGeometry(QRect(40, 30, 54, 30));
        pb_clear_register = new QPushButton(tab_2);
        pb_clear_register->setObjectName(QStringLiteral("pb_clear_register"));
        pb_clear_register->setGeometry(QRect(200, 180, 70, 30));
        lb_password_register = new QLabel(tab_2);
        lb_password_register->setObjectName(QStringLiteral("lb_password_register"));
        lb_password_register->setGeometry(QRect(40, 80, 54, 30));
        pb_register = new QPushButton(tab_2);
        pb_register->setObjectName(QStringLiteral("pb_register"));
        pb_register->setGeometry(QRect(300, 180, 70, 30));
        le_tel_register = new QLineEdit(tab_2);
        le_tel_register->setObjectName(QStringLiteral("le_tel_register"));
        le_tel_register->setGeometry(QRect(130, 30, 241, 30));
        le_password_register = new QLineEdit(tab_2);
        le_password_register->setObjectName(QStringLiteral("le_password_register"));
        le_password_register->setGeometry(QRect(130, 80, 241, 30));
        le_password_register->setEchoMode(QLineEdit::Password);
        le_confirm_register = new QLineEdit(tab_2);
        le_confirm_register->setObjectName(QStringLiteral("le_confirm_register"));
        le_confirm_register->setGeometry(QRect(130, 130, 241, 30));
        le_confirm_register->setEchoMode(QLineEdit::Password);
        lb_confirm_register = new QLabel(tab_2);
        lb_confirm_register->setObjectName(QStringLiteral("lb_confirm_register"));
        lb_confirm_register->setGeometry(QRect(40, 130, 54, 30));
        tw_page->addTab(tab_2, QString());
        QWidget::setTabOrder(tw_page, le_tel);
        QWidget::setTabOrder(le_tel, le_password);
        QWidget::setTabOrder(le_password, pb_login);
        QWidget::setTabOrder(pb_login, pb_clear);
        QWidget::setTabOrder(pb_clear, le_tel_register);
        QWidget::setTabOrder(le_tel_register, le_password_register);
        QWidget::setTabOrder(le_password_register, le_confirm_register);
        QWidget::setTabOrder(le_confirm_register, pb_register);
        QWidget::setTabOrder(pb_register, pb_clear_register);

        retranslateUi(LoginDialog);

        tw_page->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "Dialog", 0));
        lb_icon->setText(QString());
        lb_tel->setText(QApplication::translate("LoginDialog", "\346\211\213\346\234\272\345\217\267", 0));
        le_tel->setText(QApplication::translate("LoginDialog", "13252523396", 0));
        le_password->setText(QApplication::translate("LoginDialog", "1", 0));
        lb_password->setText(QApplication::translate("LoginDialog", "\345\257\206\347\240\201", 0));
        pb_clear->setText(QApplication::translate("LoginDialog", "\346\270\205\347\251\272", 0));
        pb_login->setText(QApplication::translate("LoginDialog", "\347\231\273\345\275\225", 0));
        tw_page->setTabText(tw_page->indexOf(tab_1), QApplication::translate("LoginDialog", "  \347\231\273\345\275\225  ", 0));
        lb_tel_register->setText(QApplication::translate("LoginDialog", "\346\211\213\346\234\272\345\217\267", 0));
        pb_clear_register->setText(QApplication::translate("LoginDialog", "\346\270\205\347\251\272", 0));
        lb_password_register->setText(QApplication::translate("LoginDialog", "\345\257\206\347\240\201", 0));
        pb_register->setText(QApplication::translate("LoginDialog", "\346\263\250\345\206\214", 0));
#ifndef QT_NO_TOOLTIP
        le_tel_register->setToolTip(QApplication::translate("LoginDialog", "\350\276\223\345\205\2458-11 \344\275\215 \346\211\213\346\234\272\345\217\267", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        le_password_register->setToolTip(QApplication::translate("LoginDialog", "\350\276\223\345\205\24510\344\275\215\344\273\245\345\206\205 \345\257\206\347\240\201", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        le_confirm_register->setToolTip(QApplication::translate("LoginDialog", "\345\206\215\346\254\241 \347\241\256\350\256\244 \345\257\206\347\240\201", 0));
#endif // QT_NO_TOOLTIP
        lb_confirm_register->setText(QApplication::translate("LoginDialog", "\347\241\256\350\256\244", 0));
        tw_page->setTabText(tw_page->indexOf(tab_2), QApplication::translate("LoginDialog", "  \346\263\250\345\206\214  ", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
