#include "scene.h"
#include "pion.h"
#include <QtDebug>


Scene::Scene(QObject *parent): QGraphicsScene(parent)
{
_plate= new Plateau();

this->addItem(_plate);
_plate->setPos(0,0);
_end=false;
}


void Scene::setOption(int i)
{
    qDebug("appel set option");
    if(i==1)
        _plate->setPlayerMustStrike(true);
    if(i==2)
        _plate->setPlayerMustStrike(false);

}

void Scene::disableToolTip(bool b)
{
    _plate->setEnableToolTip(b);
}


void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
if(_plate->winner()!=-1 && _end==false)
    {
    _end=true;
    emit gameWonBy(_plate->winner());
    }

QGraphicsScene::mouseReleaseEvent(mouseEvent);

}

void Scene::newGame()
{
    this->removeItem(_plate);
    Plateau* p= _plate;
    _plate=0;
    delete p;
    _plate= new Plateau();
    this->addItem(_plate);
    _plate->setPos(0,0);
   _end=false;
}



