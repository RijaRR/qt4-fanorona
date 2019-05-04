#ifndef PION_H
#define PION_H
#include <QGraphicsItem>



class Pion : public QGraphicsItem
{


public:
    enum { Type = UserType + 6 };

    Pion(int gamer, QGraphicsItem *parent = 0, QGraphicsScene *scene = 0);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    QRectF boundingRect() const;
    QPainterPath shape() const;

    void setCord(QPair<int,int> c);
    QPair<int,int> getCord() const;
    int getOwner() const;
    void setColor(QColor c);
    bool operator==(const Pion &pio) const;

protected:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);






private:
    int _gamer;
    QPair<int,int> _cord;
    QColor _color;

};

#endif // PION_H
