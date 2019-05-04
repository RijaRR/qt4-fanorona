#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::Dialog)
{
    m_ui->setupUi(this);

    connect(this,SIGNAL(accepted()),this,SLOT(giveOption()));


}

Dialog::~Dialog()
{
    delete m_ui;
}

void Dialog::giveOption()
{
    if(m_ui->radioButton_3->isChecked())
        emit option(1);

    if(m_ui->radioButton->isChecked())
        emit option(2);

    QString p1= m_ui->lineEdit->text();
    QString p2= m_ui->lineEdit_2->text();
    QPair<QString,QString> p(p1,p2);

    //emit gamerName(p);
}


void Dialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
