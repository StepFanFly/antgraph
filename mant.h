#ifndef MANT_H
#define MANT_H
#include <vector>
#include <medge.h>
#include <math.h>

class mant
{
public:
    mant(int start, std::vector<int> a);
    void findWay(std::vector<medge*> a);
    void reset(std::vector<int> a);
    std::vector<int> getWay();
    float getWayLength();

    void setA(float a);
    void setB(float b);
    void setP(float p);

    int getFirstNodeEvar() const;

private:
    void goToNode(int a, int ln);
    int findRange(std::vector<float> a);
    float random(float a);
    std::vector<int> toVisit;
    std::vector<int> way;
    int node;
    int firstNodeEvar;
    float waylength;
    float _a;
    float _b;
    float _p;
};

#endif // MANT_H
