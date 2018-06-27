#include "mgscena.h"

void mgscena::mousePressEvent(QMouseEvent *event)
{
    event->ignore();
    if (event->buttons() & Qt::LeftButton)
    {
        event->accept();
        QPointF f=QGraphicsView::mapToScene(event->pos());
        emit newNode(f);
    }
    QGraphicsView::mousePressEvent(event);
}

mgscena::mgscena(QWidget *parent):QGraphicsView(parent)
{

}
