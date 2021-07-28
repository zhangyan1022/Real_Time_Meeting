#include "bqform.h"
#include "ui_bqform.h"


bqForm::bqForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bqForm)
{

    ui->setupUi(this);
    setWindowFlags(/*Qt::FramelessWindowHint*/Qt::CustomizeWindowHint/*| Qt::WindowStaysOnTopHint*/);
    ui->stackedWidget->setCurrentIndex(0);

    for( qint32 i = 0 ; i < 92 ; i++)
    {
        QString str = QString("%1").arg(i);
        QString btnStr = QString("p%1").arg(str,3,QChar('0'));
        lstBtn.append(btnStr);
    }
    for( int i = 0 ; i < 92 ; i++)
    {
       QPushButton* p = ui->stackedWidget->findChild<QPushButton *>( lstBtn.at(i));

       m_listBtn.append(p);

       QString str = QString("%1").arg(i);

       QString btnStr = QString(":/bq/%1.png").arg(str,3,QChar('0'));
       p->setIcon(QIcon(btnStr));

       connect(p,SIGNAL(clicked(bool)),this,SLOT(on_Click()));
    }
//    QWidget::installEventFilter(this);//为这个窗口安装过滤器

    setWindowFlags(Qt::Popup) ;
    ui->stackedWidget->setCurrentIndex(0);
}

bqForm::~bqForm()
{
    delete ui;
}

void bqForm::on_quitBtn_clicked()
{
    this->close();
}

void bqForm::on_BackBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}



void bqForm::on_ForwardBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void bqForm::on_Click()
{
    QPushButton * Btn = (QPushButton *)sender();

    this->hide();
   for( int i = 0;i < m_listBtn.size() ; i++)
   {
       if( Btn == m_listBtn.at( i ) )
       {
           emit SIG_BQID(i);
       }
   }
//    emit SIG_BQID(Btn->icon());
}

