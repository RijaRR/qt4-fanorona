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

    void paintPattern(QPainter *painter,int w, int h);//motif utilisé par la méthode paint

    void initPion();//initialise tout les pions, leurs attribue un coordoné et les places sur le plateau
    void verifyPosition(Pion* p);//méthode appelé lorsque l'utilisateur relâche le souris sur un pions (cf Pion::mouserelease)
    void recordPreviousPionPosition(Pion* p);//méthode appelé lors du click, enregistre les coordonnées du pions

    void initMap();//initialise la correspondance entre l'emplacement absolue et un système de coordonné semblable à une matrice (i ligne, j colonne)


    int setCoord(Pion* p);//attribue un coordonné (i,j) au pion selon sa position p.pos()

    bool isMovePossible(QPair <int,int> prev,QPair <int,int> c,Pion* p);//s'il est possible pour le pion p de se déplacer de "prev" à "c" (le pion p est déjà au dessus de "c")

    QList< QPair <int,int> > adjacentCoord(QPair <int,int> target);//les coordonnées adjacent à target
    QList< QPair <int,int> > possibleMove(Pion* p);//s'il est possible de se déplacer
    QList< QPair <int,int> > strikingMove(QPair <int,int> from,QList< QPair <int,int> > alreadyVisited,int owner);//un coup à partir de "from" du joueur "owner" qui peut supprimer les pions adverses


    bool isAdjacentCoord(QPair <int,int> owner, QPair <int,int> questionned);//si c'est un coordonné adjacent

    QPair <int,int>  pointToCord(QPointF p);//convertit une position absolue en coordonné (i,j), utilise p.pos()

    QList<Pion* > getPion1() const;//a supprimer

    Pion* pionAt(QPair <int,int> c);//retourne le pion de coordoné "c"

    Mode getMode() const;//retourne le mode actuel qui représente la phase du jeu

    bool canPlayerDelete(int numPlayer ,QPair <int,int> previousPosition ,QPair <int,int> currentPosition);//si le joueur "numPlayer" pouvait supprimer en se déplaçant de "previousPosition" à "currentPosition"

    QList<Pion* > _reachedToBeDeleted;//variable de classe représentant les pions adverses à supprimer après qu'on ait avancé

    QList<Pion* > _leavedToBeDeleted;//variable de classe représentant les pions adverses à supprimer après qu'on ait reculé

    void verifyDelete(Pion* p);//methode appelé lors d'un clic sur un pion (cf Pion::mousePressed)

    void testConc();

    void markPionToBeDeleted(int numPlayer);//colore les pions à supprimer

    bool canPionMoveToDelete(Pion* p);//si ce pion peut supprimer
    bool canPionMoveToDelete2(Pion* p);//méthode identique mains n'affecte pas "_reachedToBeDeleted" et "_leavedToBeDeleted"

    bool canPionMove(Pion* p);//si le pion peut se déplacer
    bool canPionMove2(QPair <int,int> pionInitialPosition);
    bool isPionSurrounded(Pion* p);//on prend en compte la position précédente pour pion to move again
    bool isTurnToMove (Pion* p);//si c'est le tour du joueur propriétaire du pion de se déplacer

    void uptadeMove();//met à jour les capacités des pions à se déplacer, il est appelé à chaque changement de mode
    void uptadeMoveHelper(Pion* p);
    bool canPlayerDelete2(int numPlayer ,QPair <int,int> pr ,QPair <int,int> cr);//doesn't affect _reachedToBeDeleted and other
    bool playerMustNotMoveThis(Pion* p);//s'il y a encore d'autre pion gagnant à déplacer
    bool playerMustStrike(Pion* p);//si ce pion doit supprimer un pion adverse

    void setPlayerMustStrike(bool b);//utilisé pour configurer les règles du jeu

    void resetToolTip();//initialise le tool tip
    void setEnableToolTip(bool b);

    int winner();//retourne le numéro du gagnant

    QList<Pion* > _p1;//liste des pions du joueurs n1
    QList<Pion* > _p2;//liste des pions du joueurs n2






private:
    int _width;//longueur du plateau
    int _height;//largeur du plateau
    QList<QPointF > _prev;//position précédents du pions déplacé
    QList<QPair <int,int> > _prevC;//coordonnées déjà visités par le pion selectionné
    Mode _mode;// mode représente la phase du jeu

    //on établit la correspondance entre position absolue (p.pos()) et une coordonné matricielle (i ligne, j colonne), ces deux listes correspondes
    QList<QPointF > _p;//
    QList<QPair <int,int> > _c;
    Pion* _pM; //le pion actuel qui peut notamment supprimer
    Pion* _lastDeleted;
    bool _playerMustStrike;
    bool _showToolTip;



    QList<Pion* > _p1ThatCanStrike;//liste des pions de 1 qui peuvent supprimer
    QList<Pion* > _p2ThatCanStrike;//liste des pions de 2 qui peuvent supprimer

    QGraphicsTextItem* _toolTip;

    void removePionTest();
    
    void configureToolTip();

    int _winner;




};



#endif // PLATEAU_H
