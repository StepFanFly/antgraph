#include "edgeitem.h"

edgeitem::edgeitem()
{

}

void edgeitem::setDrawPh(bool value)
{
    drawPh = value;
}

void edgeitem::setDrawLine(bool value)
{
    drawLine = value;
}

void edgeitem::setDrawPath(bool value)
{
    drawPath = value;
}

void edgeitem::setInBestPath(bool value)
{
    inBestPath = value;
}

void edgeitem::setPh(float value)
{
    ph = value;
}

void edgeitem::del(int from, int to)
{
    if(from==_from && to==_to){
        this->deleteLater();
    }
}

void edgeitem::setP1(QPointF value)
{
    p1 = value;
    emit signal1();
}

void edgeitem::setP2(QPointF value)
{
    p2 = value;
    emit signal1();
}

QRectF edgeitem::boundingRect() const
{
    return QRectF(0,0,1,1);
}

void edgeitem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::HighQualityAntialiasing);
    QPen pen;
    QColor fillC;
    float k=(p2.x()-p1.x())/(p2.y()-p1.y());
    if(drawPh){
        QPointF s=QPointF((p1.x()+p2.x())/2+12,(p1.y()+p2.y())/2+12);
        if(k>0){
            QPointF dp1=QPointF(0,-24);
            s+=dp1;
        }
        QPointF s1=QPointF((p1.x()+p2.x())/2,(p1.y()+p2.y())/2);
        painter->drawLine(s,s1);
        painter->drawText(s,QString::number(ph));
    }
    if(drawPath&inBestPath){
        fillC.setRgb(255,0,0);
        pen.setColor(fillC);
        pen.setWidth(7);
        painter->setPen(pen);
        painter->drawLine(p1,p2);
    }
    if(drawLine){
        fillC.setHsv(0,0,0);
        pen.setColor(fillC);
        pen.setWidth(3);
        painter->setPen(pen);
        painter->drawLine(p1,p2);
    }

}
