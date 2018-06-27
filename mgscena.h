#ifndef MGSCENA_H
#define MGSCENA_H

#include <QObject>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QApplication>
#include <QDebug>

class mgscena : public QGraphicsView
{
    Q_OBJECT
public:
    explicit mgscena(QWidget *parent=0);
protected:
    void mousePressEvent(QMouseEvent *event);
signals:
    void newNode(QPointF f);
};

#endif // MGSCENA_H4
