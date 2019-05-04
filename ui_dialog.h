/********************************************************************************
** Form generated from reading ui file 'dialog.ui'
**
** Created: Sun 21. Jan 08:38:19 2018
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QRadioButton>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_3;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton;
    QTextEdit *textEdit_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->setWindowModality(Qt::ApplicationModal);
        Dialog->resize(240, 320);
        QIcon icon;
        icon.addPixmap(QPixmap(QString::fromUtf8(":/img/lg.png")), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
        Dialog->setModal(true);
        verticalLayout = new QVBoxLayout(Dialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioButton_3 = new QRadioButton(Dialog);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setChecked(true);

        horizontalLayout->addWidget(radioButton_3);

        textEdit = new QTextEdit(Dialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout->addWidget(textEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        radioButton = new QRadioButton(Dialog);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        horizontalLayout_2->addWidget(radioButton);

        textEdit_2 = new QTextEdit(Dialog);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setUndoRedoEnabled(false);
        textEdit_2->setReadOnly(true);
        textEdit_2->setAcceptRichText(false);
        textEdit_2->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout_2->addWidget(textEdit_2);


        verticalLayout->addLayout(horizontalLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(Dialog);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMaxLength(10);

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMaxLength(10);

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Options", 0, QApplication::UnicodeUTF8));
        Dialog->setStyleSheet(QApplication::translate("Dialog", "background-color: rgb(252, 252, 252)", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QString());
        textEdit->setStyleSheet(QApplication::translate("Dialog", "background-color:rgb(255, 255, 255)", 0, QApplication::UnicodeUTF8));
        textEdit->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Avec cette option, il faut toujours supprimer les pions de son adversaire lorsque l'occasion se pr\303\251sente. S'il n'est pas possible d'\303\264ter le pion de son opposant, les d\303\251placements se feront selon les possibilit\303\251s.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QString());
        textEdit_2->setStyleSheet(QApplication::translate("Dialog", "background-color:rgb(255, 255, 255)", 0, QApplication::UnicodeUTF8));
        textEdit_2->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Celle-ci autorise le joueur \303\240 ne pas supprimer les pions de son adversaire. Cette option donne un autre approche au jeu. </span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "Joueur1", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog", "Joueur 2", 0, QApplication::UnicodeUTF8));
        lineEdit_2->setText(QApplication::translate("Dialog", "2", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("Dialog", "1", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Dialog);
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
