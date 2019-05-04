#include "pion.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QtDebug>
#include <QStyleOption>
#include "plateau.h"


Pion::Pion(int gamer, QGraphicsItem *parent, QGraphicsScene *scene)
         :QGraphicsItem(parent,scene)
{
   _gamer=gamer;
   setFlag(QGraphicsItem::ItemIsMovable,true);
  setFlag(QGraphicsItem::ItemIsSelectable, true);
  setCursor(Qt::OpenHandCursor);
  setZValue(1);
  _color=QColor();

}

QPair<int,int> Pion::getCord() const
{
    return _cord;
}


void Pion::setCord(QPair<int,int> c)
{
    _cord=c;
}

void Pion::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{

    Plateau* p= (Plateau* )this->parentItem();
    p->recordPreviousPionPosition(this);
    p->verifyDelete(this);


    QGraphicsItem::mousePressEvent(mouseEvent);
}


void Pion::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{

Plateau* p= (Plateau* )this->parentItem();
p->verifyPosition(this);
QGraphicsItem::mouseReleaseEvent(mouseEvent);

}

int Pion::getOwner() const
{
    return _gamer;
}


void Pion::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget)
{

   (_gamer==1)?painter->setBrush(Qt::red):painter->setBrush(Qt::blue);

   if(_color.isValid())
   {
      painter->setBrush(_color);
   }
    painter->drawEllipse(-10, -10, 20, 20);

}

QRectF Pion::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-10 - adjust, -10 - adjust,
                  20 + adjust, 20 + adjust);
}

QPainterPath Pion::shape() const
{
    QPainterPath path;
    path.addRect(-10, -10, 20, 20);

    return path;
}

void Pion::setColor(QColor c)
{
    _color = c;
    this->update();
}

bool Pion::operator==(const Pion &pion) const
{
    if(pion.getCord()==_cord)
        return true;

    return false;
}
