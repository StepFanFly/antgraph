#include "nodeitem.h"

nodeItem::nodeItem(int num, int size)
{
    _size=size;
    _num=num;
}

int nodeItem::num()
{
    return _num;
}

QRectF nodeItem::boundingRect() const
{
    return QRectF(-_size/2,-_size/2,_size,_size);
}

void nodeItem::paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::HighQualityAntialiasing);
    QColor fillC;
    fillC.setHsv(0,0,0);
    QBrush n;
    n.setColor(Qt::white);
    n.setStyle(Qt::SolidPattern);
    painter->setPen(fillC);
    painter->setBrush(n);
    QPointF p(0,0);
    painter->drawEllipse(p,_size/2,_size/2);
    QString a=QString::number(_num);
    painter->drawText(boundingRect(),Qt::AlignCenter,a);

    emit signal1();
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void nodeItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (QApplication::mouseButtons() == Qt::RightButton)
    {
        emit toDelete(_num);
        this->deleteLater();
    }
    m_shiftMouseCoords = this->pos() - mapToScene(event->pos());
    Q_UNUSED(event);
}

void nodeItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->setPos(mapToScene(event->pos() + m_shiftMouseCoords));
    emit redraw(this->pos(),_num,true);
}
