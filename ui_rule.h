/********************************************************************************
** Form generated from reading ui file 'rule.ui'
**
** Created: Sat 10. Feb 18:05:19 2018
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_RULE_H
#define UI_RULE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Rule
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;

    void setupUi(QDialog *Rule)
    {
        if (Rule->objectName().isEmpty())
            Rule->setObjectName(QString::fromUtf8("Rule"));
        Rule->resize(509, 320);
        QIcon icon;
        icon.addPixmap(QPixmap(QString::fromUtf8(":/img/lg.png")), QIcon::Normal, QIcon::Off);
        Rule->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(Rule);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textEdit = new QTextEdit(Rule);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setUndoRedoEnabled(false);
        textEdit->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout->addWidget(textEdit);


        retranslateUi(Rule);

        QMetaObject::connectSlotsByName(Rule);
    } // setupUi

    void retranslateUi(QDialog *Rule)
    {
        Rule->setWindowTitle(QApplication::translate("Rule", "R\303\250gles du Fanorona", 0, QApplication::UnicodeUTF8));
        textEdit->setDocumentTitle(QApplication::translate("Rule", "R\303\250gles du fanorona", 0, QApplication::UnicodeUTF8));
        textEdit->setHtml(QApplication::translate("Rule", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><title>R\303\250gles du fanorona</title><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">A propos du Fanorona</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Fanorono est un jeu de plateau traditionnel malgache. Les joeurs tracaient les lignes sur du bois, de la pierre ou \303\240 m\303\252me le sol, et y disposaient les pi\303\250ces. Si le but est bien de d\303\251pouiller l'adversaire de tous ses pi\303\250ces, il n'en reste pas moin"
                        "s que la gourmandise peut parfois mener \303\240 la d\303\251faite. A vous de voir !</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Comment \303\251liminer les pions adverses ?</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Il existe deux possibilit\303\251s pour y arriver.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; text-decoration: underline;\">La premi\303\250re</span><span style=\" font-size:8pt;\">: Il faut les approcher en se d\303\251pla\303\247ant sur une case. "
                        "Tous les pions se trouvant dans cette direction seront supprim\303\251s. Il faut remarquer que votre pion ou une case libre rompt l'effet de suppression sur la ligne.</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/img/tuto.PNG\" /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; text-decoration: underline;\">La seconde:</span><span style=\" font-size:8pt;\"> Cette fois, on \303\251loigne la pi\303\250ce d'un ou plusieurs pi\303\250ces adverse de mani\303\250re \303\240 tracer une ligne rectiligne lors du d\303\251placement. </span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px"
                        "; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/img/tut2.PNG\" /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; text-decoration: underline;\">Exception</span><span style=\" font-size:8pt; font-style:italic;\">:</span><span style=\" font-size:8pt;\"> Apr\303\250s avoir \303\251liminer un pion en reculant d'une position, il n'est pas possible de continuer sur une m\303\252me ligne dans le but de supprimer les pions adverses en les approchant.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Quand-est-ce qu'on passe la main ?</span></p>\n"
"<p style=\" margin-top:0px; margin-bot"
                        "tom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">J'ai mis deux options de gameplay pour cette version. La premi\303\250re demande que le joueur doit toujours \303\251liminer les autres pions quand il en a l'occasion. Tant qu'il peut \303\251liminer avec un pion donn\303\251, il continuera toujours et ne passera la main que s'il ne trouve plus de pi\303\250ce \303\240 \303\251liminer. C'est la r\303\250gle originale, mais il est toujours int\303\251ressant de varier le jeu. Ainsi, avec l'autre option, on peut arr\303\252ter de \"manger\" quand on veut.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Les am\303\251liorations \303\240 faire</span>"
                        "</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Il faudrait pouvoir enregistrer une partie pour la reprendre plus tard. </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">La partie graphique peut \303\252tre am\303\251lior\303\251e tout comme certains aspects du code. Les remarques sont les bienvenus.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">L'intelligence artificielle.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-i"
                        "ndent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Auteur</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">RANDRIAMANAMPY Ravalo Rija</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">rijara8@gmail.com</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Ce logiciel a \303\251t\303\251 r\303\251alis\303\251 avec Qt version 4.5.1. Cette premi\303\250re version a \303\251t\303\251 achev\303\251e le 20 janvier 2018.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0"
                        "px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\"> </span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Rule);
    } // retranslateUi

};

namespace Ui {
    class Rule: public Ui_Rule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RULE_H
