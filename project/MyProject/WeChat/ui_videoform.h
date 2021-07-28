/********************************************************************************
** Form generated from reading UI file 'videoform.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOFORM_H
#define UI_VIDEOFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoForm
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lb_name;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *VideoForm)
    {
        if (VideoForm->objectName().isEmpty())
            VideoForm->setObjectName(QStringLiteral("VideoForm"));
        VideoForm->resize(190, 150);
        VideoForm->setMinimumSize(QSize(190, 150));
        VideoForm->setStyleSheet(QLatin1String("QWidget:hover{ background-color: rgb(214, 214, 214);}\n"
""));
        verticalLayout = new QVBoxLayout(VideoForm);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lb_name = new QLabel(VideoForm);
        lb_name->setObjectName(QStringLiteral("lb_name"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        lb_name->setFont(font);
        lb_name->setFocusPolicy(Qt::NoFocus);
        lb_name->setContextMenuPolicy(Qt::DefaultContextMenu);

        verticalLayout->addWidget(lb_name);

        verticalSpacer = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(VideoForm);

        QMetaObject::connectSlotsByName(VideoForm);
    } // setupUi

    void retranslateUi(QWidget *VideoForm)
    {
        VideoForm->setWindowTitle(QApplication::translate("VideoForm", "Form", 0));
        lb_name->setText(QApplication::translate("VideoForm", "\347\224\250\346\210\267\345\220\215\345\255\227\357\274\232---", 0));
    } // retranslateUi

};

namespace Ui {
    class VideoForm: public Ui_VideoForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOFORM_H
