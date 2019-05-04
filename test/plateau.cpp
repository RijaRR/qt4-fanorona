#include "plateau.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QtDebug>
#include <QPair>
#include <QStyleOption>
#include <QVector>
 #include <QThread>
 #include <qtconcurrentrun.h>
#include <qtconcurrentmap.h>
#include "scene.h"



 using namespace QtConcurrent;


Plateau::Plateau(QGraphicsItem *parent, QGraphicsScene *scene)
    :QGraphicsItem(parent,scene)
{
     _width=400;
     _height=200;
      _pM=0;
     _playerMustStrike= true;
     _mode= player1Turn;
     initMap();
     initPion();
     uptadeMove();
     _p1ThatCanStrike.clear();
     _p2ThatCanStrike.clear();
     _showToolTip=true;
     _toolTip = new QGraphicsTextItem(this);
     configureToolTip();
     _winner=-1;

}

int Plateau::winner()
{
    return _winner;
}


void Plateau::configureToolTip()
{
    _toolTip->setHtml(QString("<p style='color:red;'>Le joueur 1 commence<p>"));
    _toolTip->setPos(-_width/2+3,_height/2+9);
    _toolTip->show();

}

void Plateau::resetToolTip()
{
    if(_showToolTip)
      _toolTip->setHtml("");

}

void Plateau::setEnableToolTip(bool b)
{
   if(b)
    {
     _toolTip->hide();
   }else
   {
      _toolTip->show();
   }
}

void Plateau::testConc()
{
    QPair <int,int> e(3,4);
     QPair <int,int> f(3,5);
    QFuture<bool > f1 = run(this, &Plateau::canPlayerDelete, 1, e, f);
}



 void Plateau::uptadeMove()
 {
     if(_playerMustStrike)
     {
         _p1ThatCanStrike.clear();
         _p2ThatCanStrike.clear();

     }
     if(!_p1.isEmpty())
     {
         for(int i=0;i<_p1.length();i++)
         {
             Pion* p1= _p1.at(i);
             uptadeMoveHelper(p1);
             if(_playerMustStrike)
             {

                 if(canPionMoveToDelete2(p1))
                 {
                   _p1ThatCanStrike.append(p1);
                 }else
                 {
                     /*
                     if(!_p1ThatCanStrike.isEmpty())
                    p1->setFlag(QGraphicsItem::ItemIsMovable,false);
                    */
                 }
             }

         }
     }else
     {//_p1 empty 2 has won
         _winner=2;
     }
      if(!_p2.isEmpty())
     {
         for(int i=0;i<_p2.length();i++)
         {
             Pion* p2= _p2.at(i);
             uptadeMoveHelper(p2);
             if(_playerMustStrike)
             {
                 if(canPionMoveToDelete2(p2))
                 {
                     _p2ThatCanStrike.append(p2);
                 }else
                 {
                     /*
                     if(!_p2ThatCanStrike.isEmpty())
                     p2->setFlag(QGraphicsItem::ItemIsMovable,false);
                     */
                 }
             }
         }
     }else
      {
         _winner=1;
     }

 }

 void Plateau::uptadeMoveHelper(Pion* p)
 {
     if(!canPionMove(p))
     {
         p->setFlag(QGraphicsItem::ItemIsMovable,false);

     }else{
         p->setFlag(QGraphicsItem::ItemIsMovable,true);
     }

 }

 bool Plateau::playerMustNotMoveThis(Pion* p)
 {

     if(p->getOwner()==1)
     {
         if(_p1ThatCanStrike.isEmpty())
             return false;

         if(!_p1ThatCanStrike.contains(p))
             return true;
     }

     if(p->getOwner()==2)
     {
         if(_p2ThatCanStrike.isEmpty())
             return false;

         if(!_p2ThatCanStrike.contains(p))
             return true;
     }

    return false;

 }




bool Plateau::isTurnToMove (Pion* p)
{
    int o= p->getOwner();
    if((o==1 && _mode==player1Turn && _pM==0) || (o==2 && _mode==player2Turn && _pM==0) )
        return true;

    if(_pM==p )
        return true;

    return false;
}


 bool Plateau::isPionSurrounded(Pion* p)
 {
     QList< QPair <int,int> > l= adjacentCoord(p->getCord());
     for(int i=0;i<l.length();i++)
     {
         Pion* pi= pionAt(l.at(i));
         if(p==_pM)
         {
             if(!_prevC.isEmpty())
             {
             if(pi==0 && !_prevC.contains(l.at(i)))//on ne l'a pas encore parcouru
                 return false;
         }
         }else{
             if(pi==0)
             return false;
         }
     }
     return true;

 }


bool Plateau::canPionMove(Pion* p)
{

    if(isTurnToMove(p) && !isPionSurrounded(p))
    {
           return true;
    }

    return false;

}

// without affecting _reachedToBeDeleted and _leavedToBeDeleted
 bool Plateau::canPlayerDelete2(int numPlayer ,QPair <int,int> pr ,QPair <int,int> cr)
 {
       if((numPlayer==1 && _mode==player2Turn) || (numPlayer==2 && _mode==player1Turn))
    {
        return false;
    }
    int dX= cr.first - pr.first;
    int dY= cr.second - pr.second;
    QPointF d(dX,dY);
    QPair <int,int> k= cr;
    QList<Pion* > reachedToBeDeleted;
    QList<Pion* > leavedToBeDeleted;
    reachedToBeDeleted.clear();
    leavedToBeDeleted.clear();
    int i=0;
    while(k.first>=0 && k.second>=0 && k.first<7 && k.second<9 && i<39)
    {
              k.first=k.first+dX;
              k.second= k.second + dY;
              Pion* pi= pionAt(k);
              if(pi)
              {
                  if(pi->getOwner()!=numPlayer)
                  {
                      reachedToBeDeleted.append(pi);
                  }else{
                      break;
                  }
              }else
              {
                  break;
              }
                    if(i==38)
                  i++;
}
  i=0;
  k=pr;
  while(k.first>=0 && k.second>=0 && k.first<7 && k.second<9 && i<39)
    {
              k.first=k.first-dX;
              k.second= k.second - dY;
              Pion* pi= pionAt(k);
              if(pi)
              {
                  if(pi->getOwner()!=numPlayer)
                  {
                      leavedToBeDeleted.append(pi);
                  }else{
                      break;
                  }
              }else
              {
                  break;
              }
                    if(i==38)
                  i++;
}

  if(leavedToBeDeleted.isEmpty() && reachedToBeDeleted.isEmpty())
      return false;
  return true;
 }


//move is already possible::
bool Plateau::canPlayerDelete(int numPlayer ,QPair <int,int> pr ,QPair <int,int> cr)
{
    if((numPlayer==1 && _mode==player2Turn) || (numPlayer==2 && _mode==player1Turn))
    {
        qDebug()<<"Erreur Plateau::canPlayerDelete!!!!";
        return false;
    }

    int dX= cr.first - pr.first;
    int dY= cr.second - pr.second;
    QPointF d(dX,dY);


    QPair <int,int> k= cr;
    _reachedToBeDeleted.clear();
    _leavedToBeDeleted.clear();

    int i=0;

    while(k.first>=0 && k.second>=0 && k.first<7 && k.second<9 && i<39)
    {
              k.first=k.first+dX;
              k.second= k.second + dY;

              Pion* pi= pionAt(k);

              if(pi)
              {

                  if(pi->getOwner()!=numPlayer)
                  {
                      _reachedToBeDeleted.append(pi);
                  }else{
                      break;
                  }
              }else
              {
                  break;
              }

                    if(i==38)
                      qDebug("Boucle Erreur Plateau::");

                  i++;
}

  i=0;
  k=pr;

  while(k.first>=0 && k.second>=0 && k.first<7 && k.second<9 && i<39)
    {
              k.first=k.first-dX;
              k.second= k.second - dY;

              Pion* pi= pionAt(k);
              if(pi)
              {
                  if(pi->getOwner()!=numPlayer)
                  {
                      _leavedToBeDeleted.append(pi);
                  }else{
                      break;
                  }
              }else
              {
                  break;
              }

                    if(i==38)
                      qDebug("Boucle Erreur Plateau::");

                  i++;
}

  if(_leavedToBeDeleted.isEmpty() && _reachedToBeDeleted.isEmpty())
      return false;

  return true;

}

bool Plateau::canPionMoveToDelete(Pion* p)
 {
     if(!canPionMove(p))
         return false;

     QList< QPair <int,int> > posM=possibleMove(p);

     for(int i=0;i<posM.length();i++)
     {
          if(canPlayerDelete(p->getOwner(),p->getCord(),posM.at(i)))
              return true;
     }
     return false;
 }


//method whithout affecting _leavedToBeDeleted and reached
 bool Plateau::canPionMoveToDelete2(Pion* p)
 {
    if(!canPionMove(p))
         return false;

     QList< QPair <int,int> > posM=possibleMove(p);

     for(int i=0;i<posM.length();i++)
     {
          if(canPlayerDelete2(p->getOwner(),p->getCord(),posM.at(i)))
         {
              return true;
          }

     }
     return false;
 }



QList< QPair <int,int> > Plateau::possibleMove(Pion* p)
{
    QList< QPair <int,int> > posM;
    QList< QPair <int,int> > adj= adjacentCoord(p->getCord());

    for(int i=0;i<adj.length();i++)
     {
         Pion* pi= pionAt(adj.at(i));
         QPair <int,int> cd= adj.at(i);
         if(p==_pM)
         {
             if(pi==0 && !_prevC.contains(cd))
                 posM.append(cd);
         }else{
             if(pi==0)
                posM.append(cd);
         }
     }
    return posM;
}


void Plateau::markPionToBeDeleted(int numPlayer)
{
QColor c;
   QColor di;

  if(numPlayer==2)
  {
          c.setRgb(255,183,183);
          di.setRgb(235,191,226);
  }else
  {
      c.setRgb(198,198,255);
      di.setRgb(10,187,245);
  }

  for(int i=0; i<_leavedToBeDeleted.length();i++)
  {
      _leavedToBeDeleted.at(i)->setColor(c);
  }
  for(int i=0; i<_reachedToBeDeleted.length();i++)
  {
      _reachedToBeDeleted.at(i)->setColor(di);
  }

}


QList< QPair <int,int> > Plateau::adjacentCoord(QPair <int,int> target)
{
    QList< QPair <int,int> > res;
    res.clear();
    //i ligne
    //j colonne
    int i= target.first;
    int j= target.second;

    if(0<i && i<6 && 0<j && j<8)
    {
        if((i%2==1 && j%2==1) || (i%2==0 && j%2==0))
        {
            QPair <int,int> a(i+1,j);
             QPair <int,int> b(i+1,j+1);
              QPair <int,int> c(i,j+1);
               QPair <int,int> d(i-1,j-1);
                QPair <int,int> e(i-1,j);
                 QPair <int,int> f(i,j-1);
                  QPair <int,int> g(i+1,j-1);
                   QPair <int,int> h(i-1,j+1);
                   res<<a<<b<<c<<d<<e<<f<<g<<h;
                   return res;
        }else
        {
            QPair <int,int> e(i-1,j);
            QPair <int,int> a(i+1,j);
            QPair <int,int> f(i,j-1);
             QPair <int,int> c(i,j+1);
             res<<e<<a<<f<<c;
             return res;
        }
    }
    //first line
    if(i==0)
    {
        if(j!=0 && j!=8)
        {
            if(j%2==1)
            {
                QPair <int,int> f(i,j-1);
                QPair <int,int> c(i,j+1);
                QPair <int,int> a(i+1,j);
                res<<f<<c<<a;
                return res;
            }else
            {
                QPair <int,int> f(i,j-1);
                QPair <int,int> c(i,j+1);
                QPair <int,int> a(i+1,j);
                QPair <int,int> g(i+1,j-1);
                QPair <int,int> b(i+1,j+1);
                res<<f<<c<<a<<g<<b;
                return res;
            }
        }

         if(j==0)
            {
               QPair <int,int> c(i,j+1);
               QPair <int,int> b(i+1,j+1);
               QPair <int,int> a(i+1,j);
               res<<c<<b<<a;
               return res;
            }

            if(j==8)
            {
                 QPair <int,int> f(i,j-1);
                 QPair <int,int> g(i+1,j-1);
                 QPair <int,int> a(i+1,j);
                 res<<f<<g<<a;
                 return res;
            }
    }

    //last line
    if(i==6)
    {
        if(j!=0 && j!=8)
        {
            if(j%2==1)
            {
                QPair <int,int> e(i-1,j);
                 QPair <int,int> f(i,j-1);
                  QPair <int,int> c(i,j+1);
                  res<<e<<f<<c;
                  return res;
            }else{
                QPair <int,int> f(i,j-1);
                QPair <int,int> e(i-1,j);
                QPair <int,int> c(i,j+1);
                res<<f<<e<<c;
                return res;
            }
        }

        if(j==0)
        {
            QPair <int,int> e(i-1,j);
            QPair <int,int> c(i,j+1);
            QPair <int,int> h(i-1,j+1);
            res<<e<<c<<h;
            return res;
        }
        if(j==8)
        {
            QPair <int,int> f(i,j-1);
            QPair <int,int> h(i-1,j-1);
             QPair <int,int> e(i-1,j);
             res<<f<<h<<e;
             return res;
        }
    }

//first column
    if(j==0 && i!=0 && i!=6)
    {
        if(i%2==1)
        {
           QPair <int,int> e(i-1,j);
           QPair <int,int> f(i+1,j);
           QPair <int,int> c(i,j+1);
           res<<e<<f<<c;
           return res;
        }else
        {
           QPair <int,int> e(i-1,j);
           QPair <int,int> f(i+1,j);
           QPair <int,int> c(i,j+1);
           QPair <int,int> d(i-1,j+1);
           QPair <int,int> a(i+1,j+1);
           res<<e<<f<<c<<d<<a;
           return res;
        }
    }

//last column
    if(j==8 && i!=0 && i!=6)
    {
         if(i%2==1)
        {
           QPair <int,int> e(i-1,j);
           QPair <int,int> f(i+1,j);
           QPair <int,int> c(i,j-1);
           res<<e<<f<<c;
           return res;
        }else
        {
           QPair <int,int> e(i-1,j);
           QPair <int,int> f(i+1,j);
           QPair <int,int> c(i,j-1);
           QPair <int,int> d(i-1,j-1);
           QPair <int,int> a(i+1,j-1);
           res<<e<<f<<c<<d<<a;
           return res;
        }
    }

return res;
}

int Plateau::setCoord(Pion* p)
{
     QRectF rec(p->pos().x()-10,p->pos().y()-10,20,20);
    for(int i=0;i<_p.length();i++)
     {
        if(rec.contains(_p.at(i)))
        {
          p->setCord(_c.at(i));
          return i;
        }
    }
    return -1;
}

 bool Plateau::canPionMove2(QPair <int,int> pionInitialPosition)
 {
     Pion* p= pionAt(pionInitialPosition);
     if(p!=0)
        return canPionMove(pionAt(pionInitialPosition));
     return false;
 }

QList< QPair <int,int> > Plateau::strikingMove(QPair <int,int> from,QList< QPair <int,int> > v,int ow)
{
    QList< QPair <int,int> > adj= adjacentCoord(from);
      QList< QPair <int,int> > res;


      if(!v.isEmpty())
      {
for(int i=v.length()-1;0<=i;i--)
        {
}
}


        for(int i=adj.length()-1;0<=i;i--)
        {
        QPair <int,int> pair= adj.at(i);
        if(!v.isEmpty())
        {
        if(v.contains(pair) || pionAt(pair)!=0)
            adj.removeOne(pair);
        }else
        {
         if(pionAt(pair)!=0)
             adj.removeOne(pair);
        }
        }

if(adj.isEmpty())
    return res;


for(int i=0;i<adj.length();i++)
    {
        QPair <int,int> pair= adj.at(i);
        int di = pair.first-from.first;
        int dj = pair.second-from.second;
        QPair <int,int> a(pair.first+di,pair.second+dj);
        QPair <int,int> b(from.first-di,from.second-dj);
        Pion* p1= pionAt(a);
        Pion* p2= pionAt(b);

            if(p1!=0){
                if(p1->getOwner()!=ow)
                {
                    res.append(pair);

                }
            }
                   if(p2!=0)
            {
                       if(p2->getOwner()!=ow)
                       {
                           if(!res.contains(pair))
                               res.append(pair);
                       }

                   }

        }


return res;
}



 bool Plateau::isMovePossible(QPair <int,int> prev,QPair <int,int> c,Pion* p)
 {
        if(isAdjacentCoord(prev,c))
     {//position occupé par un pion déjà fait en début de meth appelante
            if(!_prevC.isEmpty())
            {
                if(_prevC.contains(c) && p==_pM)
                {
                    _toolTip->setHtml("<p>Vous êtes déjà passé par ce point</p>");

                     return false;
                }

            }
            return true;
        }


        return false;
 }

 bool Plateau::isAdjacentCoord(QPair <int,int> o, QPair <int,int> qst)
 {
     QList< QPair <int,int> > adj =  adjacentCoord(o);

     if(adj.length()==0)
         qDebug()<<"Erreur !!!!!!!!!!! Plateau::isadjacentCoord";

    if(adj.contains(qst))
        return true;

    return false;
 }





void Plateau::verifyPosition(Pion* p)
{

if(_mode!=player1CanDelete && _mode!=player2CanDelete)
    {
    int own= p->getOwner();
    QPair<int,int> prevC= p->getCord();
    if(p->collidingItems().length()==2 ||
       (_mode==player1Turn && own==2) ||(_mode==player2Turn && own==1)
           || (_playerMustStrike && isTurnToMove(p) && playerMustNotMoveThis(p)))

    {
        if(!isTurnToMove(p))
        {
            _toolTip->setHtml("<i>Ce n'est pas votre tour</i>");
        }


        if(playerMustNotMoveThis(p))
        {
             _toolTip->setHtml("<p>Il y a encore un coup pour lequel il est possible de gagner un point.Jouez le</p>");
        }


        if(!_prev.isEmpty() && isTurnToMove(p) )
        p->setPos(_prev.last());

        return;
    }
int c= setCoord(p);
if(c != -1)
{
    if(isMovePossible(prevC,_c.at(c),p))
    {

        if(canPlayerDelete(p->getOwner(),prevC,_c.at(c)))
        {
            _mode= (p->getOwner()==1)?player1CanDelete:player2CanDelete;
            _pM=p;
            _prevC.append(prevC);

            if(_leavedToBeDeleted.isEmpty()^_reachedToBeDeleted.isEmpty())
            {
                if(!_leavedToBeDeleted.isEmpty())
                {
                    verifyDelete(_leavedToBeDeleted.first());
                }else
                {
                    verifyDelete(_reachedToBeDeleted.first());
                }

            }else
            {
        _toolTip->setHtml("Cliquez sur le groupe de pion que vous préfériez supprimer");
            markPionToBeDeleted(p->getOwner());
             uptadeMove();
            }


        }else
        {//il n"y a rien à supprimer passer son tour
            //on vérifie que le joueur aurait du jouer le coup dans l'autre option du jeu

            if( _playerMustStrike && playerMustStrike(p))
            {
                _toolTip->setHtml("<p>Il faut supprimer le pion de son adversaire</p>");
                 p->setCord(prevC);
                 p->setPos(_prev.last());

                     if(!_prevC.isEmpty())
                       _prevC.removeLast();

                       if(!_prev.isEmpty())
                        _prev.removeLast();

                        return;

            }

            _pM=0;
        _leavedToBeDeleted.clear();
        _reachedToBeDeleted.clear();
        _prev.clear();
        _prevC.clear();
            _mode= (p->getOwner()==1)?player2Turn:player1Turn;

            _toolTip->setHtml("<p>La main passe</p>");

            this->uptadeMove();
        }
       p->setPos(_p.at(c));

    }else
    {// une position pas valide ne passe pas son tour
        _toolTip->setHtml("<i>Position invalide, essayer une autre</i>");

       p->setCord(prevC);
       p->setPos(_prev.last());

       if(!_prevC.isEmpty())
       _prevC.removeLast();

       if(!_prev.isEmpty())
           _prev.removeLast();
       /*
       _pM=0;
       _prevC.clear();
       _prev.clear();
       */
       return;
    }

}else
{// une position pas valide ne passe pas son tour
    _toolTip->setHtml("<i>Position invalide</i>");

    /*
        _pM=0;
       _prevC.clear();
       _prev.clear();
       */
    p->setCord(prevC);
    p->setPos(_prev.last());

     if(!_prevC.isEmpty())
       _prevC.removeLast();

       if(!_prev.isEmpty())
           _prev.removeLast();




    return;
}
}
}



void Plateau::setPlayerMustStrike(bool b)
{
    _playerMustStrike= b;
}

bool Plateau::playerMustStrike(Pion* p)
{
    if(p->getOwner()==1)
    {
        if(_p1ThatCanStrike.isEmpty())
            return false;

        if(_p1ThatCanStrike.contains(p))
            return true;
    }

    if(p->getOwner()==2)
    {
        if(_p2ThatCanStrike.isEmpty())
            return false;

        if(_p2ThatCanStrike.contains(p))
            return true;
    }

    return false;
}

void Plateau::initMap()
{
    int pX= _width/8;
    int pY= _height/3;
     int x1= -(_width/2);
     int y1= -(_height/2);

    for(int i=0;i<9;i++)
    {

        for(int j=0;j<7;j++)
        {
             _p.append(QPointF(x1+i*pX,y1+j*pY/2));

             //g(j,i) j: ligne , i colonne
            QPair<int,int> g(j,i);
            _c.append(g);


        }
    }


}


void Plateau::initPion()
{
    int pX= _width/8;
    int pY= _height/3;
    int y1= -(_height/2);


   for(int i=0; i<6;i++)
   {
           int num;
           if(i==0)
           {
              num=1;
           }
           if(i==3)
           {
              y1= pY*0.5;
              num=2;
           }
               int x1= -(_width/2);


           for(int k=0;k<9;k++)
           {
               Pion* p= new Pion(num);
               p->setParentItem(this);
               p->setPos(x1,y1);
               p->setCord(pointToCord(QPointF(x1,y1)));
               //this->scene()->addItem(p);
               if(i<3)
               _p1.append(p);
               if(3 <= i)
                _p2.append(p);

                x1= x1+pX;
           }
           y1= y1+pY*0.5;
    }

       y1=0;

       for(int i=0;i<9;i++)
       {
            int x1= -(_width/2);
              if(i!=4)
           {
                  if((i%2==0 && i<4) || (i%2==1 && 4<=i) )
                  {
                      Pion* p= new Pion(1);
                        p->setParentItem(this);
                        p->setPos(x1+i*pX,0);
                         p->setCord(pointToCord(p->pos()));
                        _p1.append(p);
                       // this->scene()->addItem(p);
                  }else
                  {
                     Pion* p= new Pion(2);
                        p->setParentItem(this);
                        p->setPos(x1+i*pX,0);
                        p->setCord(pointToCord(p->pos()));
                        _p2.append(p);
                       // this->scene()->addItem(p);

                  }

              }

       }


 }









void Plateau::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget)
{

    int w =_width;
    int h= _height;

 painter->setPen(Qt::green);
 painter->drawRect(-w/2,-h/2,w,h);



    int pX= w/8;
    int pY= h/3;
int transX= 0;




for(int i=0;i<4;i++)
{
 if(transX!=0)
    {
    painter->translate(transX,0);
 }

paintPattern(painter,w,h);

painter->save();
for( int k=0; k<2;k++)
{
    painter->translate(0,pY);
    paintPattern(painter,w,h);
}
painter->restore();

transX = 2*pX;
}



}


void Plateau::paintPattern(QPainter *painter,int w, int h)
{
    painter->setPen(Qt::black);

int x1= -w/2;
int y1= -h/2;
int pX= w/8;
int pY= h/3;

painter->drawRect(x1,y1,w/4,h/3);

    QVector<QLineF> lines;
lines.append(QLineF(QPointF(x1,y1),QPointF(x1+2*pX,y1+pY)));
lines.append(QLineF(QPointF(x1,y1+pY),QPointF(x1+2*pX,y1)));
lines.append(QLineF(QPointF(x1+pX,y1),QPointF(x1+pX,y1+pY)));
lines.append(QLineF(QPointF(x1,y1+0.5*pY),QPointF(x1+2*pX,y1+0.5*pY)));

painter->drawLines(lines);

}

void Plateau::recordPreviousPionPosition(Pion* p)
{
//player turn et can move
    int gamer= p->getOwner();
    if((gamer==1 && _mode==player1Turn)|| (gamer==2 && _mode==player2Turn))
    {
    _prev.append(p->pos());
    _prevC.append(p->getCord());
}

}


QRectF Plateau::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-_width/2 - adjust, -_height/2 - adjust,
                  36 + _width, 60 + _height);
}

QPainterPath Plateau::shape() const
{
    QPainterPath path;
     qreal adjust = 0.5;
    path.addRect(-_width/2 - adjust, -_height/2 - adjust,
                  36 + _width, 60 + _height);

    return path;
}

QPair <int,int>  Plateau::pointToCord(QPointF p)
{
     if(_p.length()==0 || _c.length()==0)
    {
         qDebug()<<"Erreur Plateau::pointToCord !!!!!!!!!!!!!!!! ";
         return QPair<int,int>();
     }

     for(int i=0; i<_p.length();i++)
     {
                  QPointF pt = _p.at(i);
         if(qAbs(pt.x()-p.x())<2 && qAbs(pt.y()-p.y())<2)
         {
             return _c.at(i);
         }

     }

return QPair<int,int>();

}

QList<Pion* > Plateau::getPion1() const
{
    return _p1;
}

Pion* Plateau::pionAt(QPair <int,int> c)
{
    Pion* res=0;
     for(int i=0; i<_p1.length();i++)
    {
         Pion* pi = _p1.at(i);
         if(c== pi->getCord())
             return pi;
     }
     for(int i=0; i<_p2.length();i++)
    {
         Pion* pi = _p2.at(i);
         if(c== pi->getCord())
             return pi;
     }

return res;
}

Plateau::Mode Plateau::getMode() const
{
    return _mode;
}



//quand le pion destitiné à être supprimé est cliqué
void Plateau::verifyDelete(Pion* p)
{

     if(_mode != player1CanDelete && _mode != player2CanDelete)
         return;
     int target= p->getOwner();

int choix=0;

     if((_mode == player1CanDelete && target==2) || (_mode == player2CanDelete && target==1))
     {
         int length1= _p1.length();
            int length2= _p2.length();
         if(_reachedToBeDeleted.contains(p))
         {
             choix=1;

              if(target==1)
             {

                   for(int i=_reachedToBeDeleted.length()-1;0<=i;i--)
                 {
                     if(!_p1.removeOne(_reachedToBeDeleted.at(i)))
                     {
              }else{
                  Pion* p5= _reachedToBeDeleted.at(i);
                  p5->hide();
              }
          }
              }else
              {
                     for(int i=_reachedToBeDeleted.length()-1;0<=i;i--)
                 {
                     if(!_p2.removeOne(_reachedToBeDeleted.at(i)))
                     {
              }else{
                  Pion* p5= _reachedToBeDeleted.at(i);
                  p5->hide();
              }
          }
              }


             }


if(p){
         if(_leavedToBeDeleted.contains(p))
         {
             choix=2;
              QList<Pion* > list;
              if(target==1)
             {
                    for(int i=_leavedToBeDeleted.length()-1;0<=i;i--)
                 {
                     if(!_p1.removeOne(_leavedToBeDeleted.at(i)))
                     {
              }else{
                 _leavedToBeDeleted.at(i)->hide();

              }
             }

              }else
              {
                    for(int i=_leavedToBeDeleted.length()-1;0<=i;i--)
                 {
                     if(!_p2.removeOne(_leavedToBeDeleted.at(i)))
                     {
                  qDebug()<<"Erreur Plateau::verifyDelete 1  !!!!!!!!!!!!!!!! ";
              }else{
                 _leavedToBeDeleted.at(i)->hide();

              }
             }
              }

         }
     }
//didn't suppress anything
if((length1==_p1.length() && target==1) || (length2==_p2.length() && target==2))
{
    return;
}




     update();
if(choix==2)
     {
     for(int i=_leavedToBeDeleted.length()-1;0<=i;i--)
     {
         this->scene()->removeItem(_leavedToBeDeleted.at(i));
         //delete _leavedToBeDeleted.at(i);
     }
     for(int i=_reachedToBeDeleted.length()-1;0<=i;i--)
     {
         _reachedToBeDeleted.at(i)->setColor(QColor());
     }
 }else if(choix==1)
{
     for(int i=_reachedToBeDeleted.length()-1;0<=i;i--)
     {
         Pion* s= _reachedToBeDeleted.at(i);
         this->scene()->removeItem(s);
     }
      for(int i=_leavedToBeDeleted.length()-1;0<=i;i--)
     {
         _leavedToBeDeleted.at(i)->setColor(QColor());
     }
 }

if(_pM==0)
{
}else
{
    if(!canPionMoveToDelete(_pM)){
        _pM=0;
        _leavedToBeDeleted.clear();
        _reachedToBeDeleted.clear();
        _prev.clear();
        _prevC.clear();
        _mode=(target==1)?player1Turn:player2Turn;
        _toolTip->setHtml("<i>La main passe</i>");
       this->uptadeMove();
    }else{
        _mode=(target==1)?player2Turn:player1Turn;
        _toolTip->setHtml("<p>C'est toujours votre tour</p>");
        this->uptadeMove();
    }
}




  //_leavedToBeDeleted.clear();
  // _reachedToBeDeleted.clear();

}

}

