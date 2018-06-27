#ifndef MGRAPH_H
#define MGRAPH_H

#include <vector>
#include <mnode.h>
#include <medge.h>
#include <mant.h>
#include <QObject>
#include <QDebug>
#include <random>

class mgraph : public QObject
{
    Q_OBJECT
public:
    explicit mgraph(QObject *parent=nullptr,float bph=20);
    void init(float a,float b,int q, float p);
    void step();
    void addNode(mnode* a);
    void moveNode(QPointF to, int n);
    void delNodeAtN(int n);
    mnode* retNode(int n);
    medge* retEdge(int from,int dest);
    std::vector<medge*> retEdges();
    std::vector<int> bestRoute();
    void updateAnts();

    float bestRouteL();
    ~mgraph();
    int getGnr() const;

public slots:
    void setA(float a);
    void setB(float b);
    void setQ(int Q);
    void setP(float p);
private:
    int findRange(std::vector<float> a);
    float random(float a);
    std::vector<int> nodeList();
    std::vector<mant*> ants;
    std::vector<mnode*> nodes;
    std::vector<medge*> edges;
    std::vector<int> bestWay;
    float bestWayL;
    float _bph;
    float _a,_b;
    int _Q;
    float _p;
    int gnr;
};

#endif // MGRAPH_H
