#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "scene.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();


    void setOption(int i);

public slots:
    void showRule();
    void gameEnd();
    void switchRule();


private:
    Ui::MainWindow *ui;
    Scene* _scene;


};

#endif // MAINWINDOW_H
