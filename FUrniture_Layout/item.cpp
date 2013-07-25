#include "item.h"

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

item::item(QPixmap& pixmap, bool deleteMode)
{
    this->deleteMode = deleteMode;
    pixmapItem = new QGraphicsPixmapItem(pixmap);
    setFlag(QGraphicsItem::ItemIsMovable);
}

QRectF item::boundingRect() const
{
    return pixmapItem->boundingRect();
}

void item::paint(QPainter* painter, const QStyleOptionGraphicsItem* styleGraphicsItem, QWidget* widget)
{
    pixmapItem->paint(painter, styleGraphicsItem, widget);
}

void item::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    if (deleteMode)
    {
        setVisible(false);
        deleteMode = false;
    }
}

void item::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF startingPoint = pos();
    if (event->scenePos().x() >= 50 && event->scenePos().x() <= 450 && event->scenePos().y() >= 50 && event->scenePos().y() <=450)
    {
       QGraphicsItem::mouseMoveEvent(event);
    }
    QList <QGraphicsItem *> i = scene()->collidingItems(this);
    if (!i.isEmpty())
    {
        setPos(startingPoint);
    }
}

void item::setDeleteMode(bool mode)
{
    deleteMode = mode;
}

