#ifndef MEDGE_H
#define MEDGE_H
#include <QPointF>
#include <QDebug>
class medge
{
public:
    medge(int f,int t,QPointF a,QPointF b,float _bph);
    void changeLength(float l);
    void changeLength();
    float Length();
    void changePh(float ph);
    float Pheromon();
    QPointF P1();
    QPointF P2();
    void setP1(QPointF p);
    void setP2(QPointF p);
    bool check(int a,int b);
    bool checkOne(int a);
    bool checkFrom(int a);
    bool checkTo(int a);
    float visibility() const;

private:
    int _to,_from;
    QPointF _p1,_p2;//from p1 to p2
    float _pheromon;
    float _length;
    float _visibility;
};

#endif // MEDGE_H
