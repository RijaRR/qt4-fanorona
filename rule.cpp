#include "rule.h"
#include "ui_rule.h"

Rule::Rule(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::Rule)
{
    m_ui->setupUi(this);
}

Rule::~Rule()
{
    delete m_ui;
}

void Rule::changeEvent(QEvent *e)
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
