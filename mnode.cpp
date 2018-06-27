#include "mnode.h"

mnode::mnode(QPointF a,int n)
{
    _n=n;
    _p=a;
}

double mnode::range(mnode &a)
{
    return sqrt(pow(_p.x()-a.p().x(),2)+pow(_p.y()-a.p().y(),2));
}

int mnode::n()
{
    return _n;
}

void mnode::setP(QPointF a)
{
    _p=a;
}

QPointF mnode::p(){
    return _p;
}

void mnode::setN(int n)
{
    _n=n;
}
