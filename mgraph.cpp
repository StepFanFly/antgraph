#include "mgraph.h"

mgraph::mgraph(QObject *parent,float bph)
    :QObject(parent)
{
    _bph=bph;

}

void mgraph::init(float a, float b, int q, float p)
{
    _a=a;_b=b;
    _Q=q;_p=p;
    gnr=0;
    bestWay.clear();
    if(ants.size()>0){
        foreach (mant* g, ants) {
            delete g;
        }
        ants.clear();
    }
    for(uint i=0;i<nodes.size();i++){
        mant* t=new mant(nodes[i]->n(),nodeList());
        t->setA(_a);
        t->setB(_b);
        t->setP(_p);
        ants.push_back(t);
    }
    bestWayL=q*100;
}

void mgraph::step()
{
    foreach (mant* g, ants) {
        g->findWay(edges);
        if(bestWayL>=g->getWayLength()){
            bestWayL=g->getWayLength();
            bestWay.clear();
            bestWay=g->getWay();
        }
    }
    foreach (medge* g, edges) {
        g->changePh(g->Pheromon()*(1-_p));
    }
    foreach (mant* g, ants) {
        for(uint i=1;i<g->getWay().size();i++){
            foreach (medge* d, edges) {
                if(d->check(g->getWay().at(i-1),g->getWay().at(i))){
                    d->changePh(d->Pheromon()+(float)_Q/g->getWayLength());
                }
            }
        }
    }
    updateAnts();
    gnr++;
}

mgraph::~mgraph(){

}

void mgraph::setA(float a)
{
    _a=a;
    foreach (mant* g, ants) {
        g->setA(a);
    }
}

void mgraph::setB(float b)
{
    _b=b;
    foreach (mant* g, ants) {
        g->setB(b);
    }
}

void mgraph::setQ(int Q)
{
    _Q=Q;
}

void mgraph::setP(float p)
{
    _p=p;
    foreach (mant* g, ants) {
        g->setP(p);
    }
}

int mgraph::findRange(std::vector<float> a)
{
    float sum=0;
    foreach (auto q, a) {
        sum+=q;
    }
    float r=random(sum);
    int res=a.size()-1;
    float t=0;
    for(uint i=0;i<a.size();i++){
        if(r>t&&r<=t+a[i]){
            return i;
        }
        t+=a[i];
    }
    return res;
}

float mgraph::random(float a)
{
    return((float)(rand()+1)/(RAND_MAX+2))*a;
}

std::vector<int> mgraph::nodeList()
{
    std::vector<int> res;
    foreach (auto a, nodes) {
        res.push_back(a->n());
    }
    return res;
}

int mgraph::getGnr() const
{
    return gnr;
}

void mgraph::addNode(mnode *a)
{
    foreach (mnode* g, nodes) {
        medge* t=new medge(a->n(),g->n(),a->p(),g->p(),_bph);
        edges.push_back(t);
    }
    nodes.push_back(a);
    mant* t=new mant(nodes[nodes.size()-1]->n(),nodeList());
    t->setA(_a);
    t->setB(_b);
    t->setP(_p);
    ants.push_back(t);
    updateAnts();
    bestWayL=_Q*100;
}

void mgraph::moveNode(QPointF to, int n)
{
    foreach (mnode* a, nodes) {
        if(a->n()==n){
            a->setP(to);
        }
    }
    foreach (medge* a, edges) {
        if(a->checkTo(n)){
            a->setP2(to);
            a->changeLength();
        }
        if(a->checkFrom(n)){
            a->setP1(to);
            a->changeLength();
        }
    }
    bestWayL=0;
    for(uint i=1;i<bestRoute().size();i++){
        foreach (medge* z, edges) {
            if(z->check(bestWay.at(i-1),bestWay.at(i))){
                bestWayL+=z->Length();
            }
        }
    }
}

void mgraph::delNodeAtN(int n)
{
    for(uint i=0;i<nodes.size();i++) {
        if(n==nodes.at(i)->n()){
            nodes.erase(nodes.begin()+i);
        }
    }
    for(uint i=0;i<edges.size();i++) {
        if(edges.at(i)->checkOne(n)){
            edges.erase(edges.begin()+i);
            i--;
        }
    }
    for(uint i=0;i<ants.size();i++){
        if(ants.at(i)->getFirstNodeEvar()==n){
            ants.erase(ants.begin()+i);
        }
    }
    updateAnts();
    bestWayL=_Q*100;
}

mnode *mgraph::retNode(int n)
{
    foreach (mnode* a, nodes) {
        if(n==a->n())return a;
    }
    return nullptr;
}

medge *mgraph::retEdge(int from, int dest)
{
    foreach (medge* a, edges) {
        if(a->check(from,dest))return a;
    }
    return nullptr;
}

std::vector<medge *> mgraph::retEdges()
{
    return edges;
}

std::vector<int> mgraph::bestRoute()
{

    return bestWay;
}

void mgraph::updateAnts()
{
    foreach (mant* t, ants) {
        t->reset(nodeList());
        t->setA(_a);
        t->setB(_b);
        t->setP(_p);
    }
}

float mgraph::bestRouteL()
{
    return bestWayL;
}
