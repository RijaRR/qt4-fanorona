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

    void paintPattern(QPainter *painter,int w, int h);//motif utilis� par la m�thode paint

    void initPion();//initialise tout les pions, leurs attribue un coordon� et les places sur le plateau
    void verifyPosition(Pion* p);//m�thode appel� lorsque l'utilisateur rel�che le souris sur un pions (cf Pion::mouserelease)
    void recordPreviousPionPosition(Pion* p);//m�thode appel� lors du click, enregistre les coordonn�es du pions

    void initMap();//initialise la correspondance entre l'emplacement absolue et un syst�me de coordonn� semblable � une matrice (i ligne, j colonne)


    int setCoord(Pion* p);//attribue un coordonn� (i,j) au pion selon sa position p.pos()

    bool isMovePossible(QPair <int,int> prev,QPair <int,int> c,Pion* p);//s'il est possible pour le pion p de se d�placer de "prev" � "c" (le pion p est d�j� au dessus de "c")

    QList< QPair <int,int> > adjacentCoord(QPair <int,int> target);//les coordonn�es adjacent � target
    QList< QPair <int,int> > possibleMove(Pion* p);//s'il est possible de se d�placer
    QList< QPair <int,int> > strikingMove(QPair <int,int> from,QList< QPair <int,int> > alreadyVisited,int owner);//un coup � partir de "from" du joueur "owner" qui peut supprimer les pions adverses


    bool isAdjacentCoord(QPair <int,int> owner, QPair <int,int> questionned);//si c'est un coordonn� adjacent

    QPair <int,int>  pointToCord(QPointF p);//convertit une position absolue en coordonn� (i,j), utilise p.pos()

    QList<Pion* > getPion1() const;//a supprimer

    Pion* pionAt(QPair <int,int> c);//retourne le pion de coordon� "c"

    Mode getMode() const;//retourne le mode actuel qui repr�sente la phase du jeu

    bool canPlayerDelete(int numPlayer ,QPair <int,int> previousPosition ,QPair <int,int> currentPosition);//si le joueur "numPlayer" pouvait supprimer en se d�pla�ant de "previousPosition" � "currentPosition"

    QList<Pion* > _reachedToBeDeleted;//variable de classe repr�sentant les pions adverses � supprimer apr�s qu'on ait avanc�

    QList<Pion* > _leavedToBeDeleted;//variable de classe repr�sentant les pions adverses � supprimer apr�s qu'on ait recul�

    void verifyDelete(Pion* p);//methode appel� lors d'un clic sur un pion (cf Pion::mousePressed)

    void testConc();

    void markPionToBeDeleted(int numPlayer);//colore les pions � supprimer

    bool canPionMoveToDelete(Pion* p);//si ce pion peut supprimer
    bool canPionMoveToDelete2(Pion* p);//m�thode identique mains n'affecte pas "_reachedToBeDeleted" et "_leavedToBeDeleted"

    bool canPionMove(Pion* p);//si le pion peut se d�placer
    bool canPionMove2(QPair <int,int> pionInitialPosition);
    bool isPionSurrounded(Pion* p);//on prend en compte la position pr�c�dente pour pion to move again
    bool isTurnToMove (Pion* p);//si c'est le tour du joueur propri�taire du pion de se d�placer

    void uptadeMove();//met � jour les capacit�s des pions � se d�placer, il est appel� � chaque changement de mode
    void uptadeMoveHelper(Pion* p);
    bool canPlayerDelete2(int numPlayer ,QPair <int,int> pr ,QPair <int,int> cr);//doesn't affect _reachedToBeDeleted and other
    bool playerMustNotMoveThis(Pion* p);//s'il y a encore d'autre pion gagnant � d�placer
    bool playerMustStrike(Pion* p);//si ce pion doit supprimer un pion adverse

    void setPlayerMustStrike(bool b);//utilis� pour configurer les r�gles du jeu

    void resetToolTip();//initialise le tool tip
    void setEnableToolTip(bool b);

    int winner();//retourne le num�ro du gagnant

    QList<Pion* > _p1;//liste des pions du joueurs n1
    QList<Pion* > _p2;//liste des pions du joueurs n2






private:
    int _width;//longueur du plateau
    int _height;//largeur du plateau
    QList<QPointF > _prev;//position pr�c�dents du pions d�plac�
    QList<QPair <int,int> > _prevC;//coordonn�es d�j� visit�s par le pion selectionn�
    Mode _mode;// mode repr�sente la phase du jeu

    //on �tablit la correspondance entre position absolue (p.pos()) et une coordonn� matricielle (i ligne, j colonne), ces deux listes correspondes
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
