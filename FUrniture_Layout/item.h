#pragma once
#include <QGraphicsObject>

class item: public QGraphicsObject
{
    Q_OBJECT

public:
    item(QPixmap& pix, bool mode);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *styleGraphicsItem, QWidget *widget);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void setDeleteMode(bool mode);

private:
       QGraphicsPixmapItem *pixmapItem;
       bool deleteMode;

};


