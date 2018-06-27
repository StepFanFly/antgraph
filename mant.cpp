#include "mant.h"

mant::mant(int start, std::vector<int> a)
{
    firstNodeEvar=start;
    node=start;
    way.push_back(start);
    toVisit=a;
    for(int i=0;i<toVisit.size();i++){
        if(node==toVisit.at(i)){
            toVisit.erase(toVisit.begin()+i);
        }
    }
    waylength=0;
}

void mant::findWay(std::vector<medge *> a)
{
    while(toVisit.size()>1){
        std::vector<float> vis;
        std::vector<float> ph;
        foreach (int q, toVisit) {
            foreach (medge* g, a) {
                if(g->check(node,q)){
                    vis.push_back(g->visibility());
                    ph.push_back(g->Pheromon());
                }
            }
        }
        std::vector<float> t;
        for(uint i=0;i<toVisit.size();i++){
            t.push_back(pow(ph[i],_a)*pow(vis[i],_b));
        }
        int d=findRange(t);
        float r;
        foreach (medge* g, a) {
            if(g->check(node,toVisit[d])){
                r=g->Length();
            }
        }
        goToNode(toVisit[d],r);
    }
    int u1=way.at(way.size()-1);
    int u2=toVisit.at(0);
    way.push_back(u2);
    float r=0;
    foreach (medge* z, a) {
        if(z->check(u1,u2)){
            r=z->Length();
        }
    }
    waylength+=r;
    int v1=way.at(way.size()-1);
    int v2=firstNodeEvar;
    r=0;
    foreach (medge* z, a) {
        if(z->check(v1,v2)){
            r=z->Length();
        }
    }
    way.push_back(v2);
    waylength+=r;
}

void mant::reset( std::vector<int> a)
{
    node=firstNodeEvar;
    way.clear();
    toVisit.clear();
    way.push_back(node);
    toVisit=a;
    for(int i=0;i<toVisit.size();i++){
        if(node==toVisit.at(i)){
            toVisit.erase(toVisit.begin()+i);
        }
    }
    waylength=0;
}

void mant::goToNode(int a, int ln)
{
    way.push_back(a);
    node=a;
    waylength+=ln;
    for(int i=0;i<toVisit.size();i++){
        if(a==toVisit.at(i)){
            toVisit.erase(toVisit.begin()+i);
        }
    }
}

std::vector<int> mant::getWay()
{
    return way;
}

float mant::getWayLength()
{
    return waylength;
}

int mant::findRange(std::vector<float> a)
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

float mant::random(float a)
{
    return((float)(rand()+1)/(RAND_MAX+2))*a;
}

int mant::getFirstNodeEvar() const
{
    return firstNodeEvar;
}

void mant::setP(float p)
{
    _p = p;
}

void mant::setB(float b)
{
    _b = b;
}

void mant::setA(float a)
{
    _a = a;
}
