//#include "wechatdialog.h"
#include <QApplication>
#include<ckernel.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // 加载样式表
    QFile file(":/res/psblack.css");
    if (file.open(QFile::ReadOnly))
    {
        QString qss = QLatin1String(file.readAll());
        QString paletterColor = qss.mid(20, 7);
        // 设置颜色
        qApp->setPalette(QPalette(QColor(paletterColor)));
        // 应用样式表
        qApp->setStyleSheet(qss);
        file.close();
    }
    CKernel::GetInstance();
    return a.exec();
}
