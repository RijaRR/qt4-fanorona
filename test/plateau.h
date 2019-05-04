#ifndef PLATEAU_H
#define PLATEAU_H
#include <QGraphicsItem>
#include <QList>
#include <QPair>
#include <QMap>
#include "pion.h"

#include <QGraphicsTextItem>


class Plateau : public QGraphicsItem
{


public:
    enum { Type = UserType + 4 };

    enum Mode { player1Turn, player2Turn, player1CanDelete, player2CanDelete };

    Plateau(QGraphicsItem *parent = 0, QGraphicsScene *scene = 0);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    QRectF boundingRect() const;
    QPainterPath shape() const;

    void paintPattern(QPainter *painter,int w, int h);

    void initPion();
    void verifyPosition(Pion* p);
    void recordPreviousPionPosition(Pion* p);

    void initMap();


    int setCoord(Pion* p);

    bool isMovePossible(QPair <int,int> prev,QPair <int,int> c,Pion* p);

    QList< QPair <int,int> > adjacentCoord(QPair <int,int> target);
    QList< QPair <int,int> > possibleMove(Pion* p);
    QList< QPair <int,int> > strikingMove(QPair <int,int> from,QList< QPair <int,int> > alreadyVisited,int owner);

    bool isAdjacentCoord(QPair <int,int> owner, QPair <int,int> questionned);

    QPair <int,int>  pointToCord(QPointF p);

    QList<Pion* > getPion1() const;//a supprimer

    Pion* pionAt(QPair <int,int> c);

    Mode getMode() const;

    bool canPlayerDelete(int numPlayer ,QPair <int,int> previousPosition ,QPair <int,int> currentPosition);

    QList<Pion* > _reachedToBeDeleted;

    QList<Pion* > _leavedToBeDeleted;

    void verifyDelete(Pion* p);

    void testConc();

    void markPionToBeDeleted(int numPlayer);

    bool canPionMoveToDelete(Pion* p);
    bool canPionMoveToDelete2(Pion* p);

    bool canPionMove(Pion* p);
    bool canPionMove2(QPair <int,int> pionInitialPosition);
    bool isPionSurrounded(Pion* p);//on prend en compte la position précédente pour pion to move again
    bool isTurnToMove (Pion* p);

    void uptadeMove();
    void uptadeMoveHelper(Pion* p);
    bool canPlayerDelete2(int numPlayer ,QPair <int,int> pr ,QPair <int,int> cr);//doesn't affect _reachedToBeDeleted and other
    bool playerMustNotMoveThis(Pion* p);
    bool playerMustStrike(Pion* p);

    void setPlayerMustStrike(bool b);

    void resetToolTip();   
    void setEnableToolTip(bool b);

    int winner();//return the winner

    QList<Pion* > _p1;//list pion of player 1
    QList<Pion* > _p2;






private:
    int _width;
    int _height;
    QList<QPointF > _prev;
    QList<QPair <int,int> > _prevC;
    Mode _mode;

    //dico
    QList<QPointF > _p;
    QList<QPair <int,int> > _c;
    Pion* _pM; //pion to move again
    bool _playerMustStrike;
    bool _showToolTip;



    QList<Pion* > _p1ThatCanStrike;
    QList<Pion* > _p2ThatCanStrike;

    QGraphicsTextItem* _toolTip;


    
    void configureToolTip();

    int _winner;




};



#endif // PLATEAU_H
