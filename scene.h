#ifndef SCENE_H
#define SCENE_H
#include <QGraphicsScene>
#include "plateau.h"


class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    Scene(QObject *parent);


protected:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);

signals:
    void gameWonBy(int i);

public slots:
    void newGame();
    void setOption(int i);
    void disableToolTip(bool b);




private:
     Plateau* _plate;
     bool _end;

};

#endif // SCENE_H
