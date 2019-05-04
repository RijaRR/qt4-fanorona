#ifndef RULE_H
#define RULE_H

#include <QtGui/QDialog>

namespace Ui {
    class Rule;
}

class Rule : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(Rule)
public:
    explicit Rule(QWidget *parent = 0);
    virtual ~Rule();

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::Rule *m_ui;
};

#endif // RULE_H
