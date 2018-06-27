#ifndef NODEITEM_H
#define NODEITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QApplication>

class nodeItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit nodeItem(int num,int size=30);
    int num();
private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int _num;
    int _size;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    QPointF m_shiftMouseCoords;
signals:
    void signal1();
    void redraw(QPointF a,int n,bool m);
    void toDelete(int n);
};

#endif // NODEITEM_H
