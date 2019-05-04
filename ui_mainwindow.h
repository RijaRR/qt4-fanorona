/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Sun 21. Jan 16:06:40 2018
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNouveau;
    QAction *actionRule;
    QAction *desacAction;
    QAction *actionSwitch;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menuOptions;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 400);
        QIcon icon;
        icon.addPixmap(QPixmap(QString::fromUtf8(":/img/lg.png")), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionNouveau = new QAction(MainWindow);
        actionNouveau->setObjectName(QString::fromUtf8("actionNouveau"));
        actionRule = new QAction(MainWindow);
        actionRule->setObjectName(QString::fromUtf8("actionRule"));
        desacAction = new QAction(MainWindow);
        desacAction->setObjectName(QString::fromUtf8("desacAction"));
        desacAction->setCheckable(true);
        actionSwitch = new QAction(MainWindow);
        actionSwitch->setObjectName(QString::fromUtf8("actionSwitch"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setMargin(11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        horizontalLayout->addWidget(graphicsView);


        horizontalLayout_2->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 22));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuOptions->menuAction());
        menuOptions->addAction(actionNouveau);
        menuOptions->addAction(desacAction);
        menuOptions->addAction(actionRule);
        menuOptions->addAction(actionSwitch);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Fanorona", 0, QApplication::UnicodeUTF8));
        actionNouveau->setText(QApplication::translate("MainWindow", "Nouveau", 0, QApplication::UnicodeUTF8));
        actionRule->setText(QApplication::translate("MainWindow", "A propos", 0, QApplication::UnicodeUTF8));
        desacAction->setText(QApplication::translate("MainWindow", "D\303\251sactiver les commentaires", 0, QApplication::UnicodeUTF8));
        actionSwitch->setText(QApplication::translate("MainWindow", "Jouer avec un autre r\303\250gle", 0, QApplication::UnicodeUTF8));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
