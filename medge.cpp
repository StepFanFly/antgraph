#include "medge.h"

float medge::visibility() const
{
    return _visibility;
}

medge::medge(int f, int t,QPointF a,QPointF b,float _bph)
{
    _from=f;_to=t;
    _p1=a;
    _p2=b;
    _pheromon=_bph;
    _length=sqrt(pow(a.x()-b.x(),2)+pow(a.y()-b.y(),2));
    _visibility=1/_length;
}

void medge::changeLength(float l)
{
    _length=l;
    _visibility=1/_length;
}

void medge::changeLength()
{
    _length=sqrt(pow(_p1.x()-_p2.x(),2)+pow(_p1.y()-_p2.y(),2));
    _visibility=1/_length;
}

float medge::Length()
{
    return _length;
}

void medge::changePh(float ph)
{
    _pheromon=ph;
}

float medge::Pheromon()
{
    return _pheromon;
}

QPointF medge::P1()
{
    return _p1;
}

QPointF medge::P2()
{
    return _p2;
}

void medge::setP1(QPointF p)
{
    _p1=p;
}

void medge::setP2(QPointF p)
{
    _p2=p;
}

bool medge::check(int a, int b)
{
    if((a==_to & b==_from)||(b==_to & a==_from)){
        return true;
    }else{
        return false;
    }
}

bool medge::checkOne(int a)
{
    if((a==_to)||(a==_from)){
        return true;
    }else{
        return false;
    }
}

bool medge::checkFrom(int a)
{
    if(a==_from){
        return true;
    }else{
        return false;
    }
}

bool medge::checkTo(int a)
{
    if(a==_to){
        return true;
    }else{
        return false;
    }
}
