#ifndef MNODE_H
#define MNODE_H
#include "math.h"
#include <QPointF>

class mnode
{
public:
    mnode(QPointF a,int n);
    double range(mnode &a);
    int n();
    QPointF p();
    void setP(QPointF a);
    void setN(int n);
private:
    int _n;
    QPointF _p;
};

#endif // MNODE_H
