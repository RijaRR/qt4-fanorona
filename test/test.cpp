 #include <QtTest/QtTest>
#include <QtGui>
#include "plateau.h"
#include "pion.h"


 class Test: public QObject
 {
     Q_OBJECT
 private slots:
     void toUpper();
     void pointAdjacent();
     void verifyCoord();
     void canPlayerDelete();


private:
     bool hasTheSameValue(QList<QPair <int,int> > list,QList<QPair <int,int> > li);
     void retainAtPosition( QList<QPair <int,int> > list,Plateau* p);


 };


void retainAtPosition( QList<QPair <int,int> > list,Plateau* p)
{
    QList<Pion* > p1= p->_p1;
    QList<Pion* > p2= p->_p2;
    for(int i=0;i<p1.length();i++)
    {
        if(!list.contains(p1.at(i)->getCord()))
        {
           p->_p1.removeOne(p1.at(i));
        }
    }
    for(int i=0;i<p2.length();i++)
    {
        if(!list.contains(p2.at(i)->getCord()))
        {
           p->_p2.removeOne(p2.at(i));
        }
    }
}




 void Test::canPlayerDelete()
 {
     Plateau* p= new Plateau();
     QPair <int,int> a(3,5);
      QPair <int,int> b(3,4);
     bool l=p->canPlayerDelete(1,a,b);

     QCOMPARE(true, l);

      QPair <int,int> _a(2,4);
      QPair <int,int> _b(3,4);
      bool _l=p->canPlayerDelete(1,_a,_b);

      QCOMPARE(true, _l);
      QCOMPARE(3, p->_reachedToBeDeleted.length());

      QPair <int,int> aa(3,5);
      QPair <int,int> bb(2,4);
      bool ll=p->canPlayerDelete(1,aa,bb);

      QCOMPARE(true, ll);
      QCOMPARE(3, p->_leavedToBeDeleted.length());

      QPair <int,int> s(2,2);
      QPair <int,int> d(3,1);
      bool ss=p->canPlayerDelete(1,s,d);

      QCOMPARE(true, ss);
      QCOMPARE(1, p->_reachedToBeDeleted.length());





 }


 void Test::verifyCoord()
 {
     /*
   Plateau* p= new Plateau();

   QList<Pion* > p1= p->getPion1();

   for(int i=0; i<p1.length();i++)
   {
    qDebug()<<p1.at(i)->getCord();
   }
*/
     //OK
 }

 void Test::toUpper()
 {
     QString str = "Hello";
     QCOMPARE(str.toUpper(), QString("HELLO"));
 }

 void Test::pointAdjacent()
 {

     Plateau* p= new Plateau();

      QPair <int,int> target(3,2);
     QPair <int,int> b(2,2);
     QPair <int,int> c (3,1);
     QPair <int,int>  d(4,2);
     QPair <int,int> e(3,3);
     QList<QPair <int,int> > res1;
     res1<<b<<c<<d<<e;

     QPair <int,int> target2(4,6);
     QPair <int,int> j(5,5);
     QPair <int,int>  k(4,5);
     QPair <int,int>  l(3,5);
     QPair <int,int> f(3,6);
     QPair <int,int> g(3,7);
     QPair <int,int> h(4,7);
     QPair <int,int> i(5,6);
     QPair <int,int> m(5,7);
      QList<QPair <int,int> > res2;
      res2<<f<<g<<h<<i<<j<<k<<l<<m;

      QPair <int,int> target3(3,0);
      QPair <int,int> _j(2,0);
     QPair <int,int>  _k(4,0);
     QPair <int,int>  _l(3,1);
     QList<QPair <int,int> > res3;
     res3<<_j<<_k<<_l;

      QPair <int,int> target4(0,8);
       QPair <int,int> _h(0,7);
     QPair <int,int> _i(1,7);
     QPair <int,int> _m(1,8);
     QList<QPair <int,int> > res4;
     res4<<_h<<_i<<_m;

     QPair <int,int> target5(6,0);
      QPair <int,int> aa1(5,0);
     QPair <int,int> bb1(5,1);
     QPair <int,int> cc1(6,1);
     QList<QPair <int,int> > res5;
     res5<<aa1<<bb1<<cc1;

       QPair <int,int> target6(6,6);
      QPair <int,int> t(6,5);
     QPair <int,int> tt(5,6);
     QPair <int,int> ttt(5,7);
     QPair <int,int> t2(5,5);
     QPair <int,int> tttt(6,7);
     QList<QPair <int,int> > res6;
     res6<<tt<<ttt<<tttt<<t<<t2;





    QList<QPair <int,int> > p1 = p->adjacentCoord(target);
    QList<QPair <int,int> > p2 = p->adjacentCoord(target2);
    QList<QPair <int,int> > p3 = p->adjacentCoord(target3);
    QList<QPair <int,int> > p4 = p->adjacentCoord(target4);
    QList<QPair <int,int> > p5 = p->adjacentCoord(target5);




    QList<QPair <int,int> > p6 = p->adjacentCoord(target6);

/*
    for(int i=0; i<p6.length();i++)
        {
        qDebug()<<p6.at(i);
        }
    qDebug(".......");
    for(int i=0; i<res6.length();i++)
        {
        qDebug()<<res6.at(i);
        }
*/

     QCOMPARE(true,hasTheSameValue(p1,res1) );
     QCOMPARE(true,hasTheSameValue(p2,res2) );
     QCOMPARE(true,hasTheSameValue(p3,res3) );
     QCOMPARE(true,hasTheSameValue(p4,res4) );
     QCOMPARE(true,hasTheSameValue(p5,res5) );
     QCOMPARE(true,hasTheSameValue(p6,res6) );


 }

bool Test::hasTheSameValue(QList<QPair <int,int> > list,QList<QPair <int,int> > li)
{
    if(list.length() != li.length())
        return false;

    for(int i=0; i<li.length();i++)
        {
        if(!list.contains(li.at(i)))
            return false;
        }
   return true;
}









 QTEST_MAIN(Test)
 #include "test.moc"
