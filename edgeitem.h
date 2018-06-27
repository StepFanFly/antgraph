#ifndef EDGEITEM_H
#define EDGEITEM_H

#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QDebug>

class edgeitem : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit edgeitem();
    int _from,_to;
    void setP1(QPointF value);
    void setP2(QPointF value);
public slots:
    void setDrawPh(bool value);
    void setDrawLine(bool value);
    void setDrawPath(bool value);
    void setInBestPath(bool value);
    void setPh(float value);
    void del(int from, int to);
private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPointF p1,p2;
    float ph;
    bool drawPh, drawLine,drawPath,inBestPath;
signals:
    void signal1();
};

#endif // EDGEITEM_H
