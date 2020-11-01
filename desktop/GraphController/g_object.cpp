#include "g_object.h"
#include "GraphController/g_arrow.h"
#include "QGraphicsScene"
#include "qdebug.h"
#include "quuid.h"



G_OBJECT::G_OBJECT(QGraphicsItem *parent)
    : QGraphicsPolygonItem (parent)
{

}

void G_OBJECT::addArrow(G_ARROW *arrow)
{
    arrows.append(arrow);
}


void G_OBJECT::removeArrow(G_ARROW *arrow)
{
    int index = arrows.indexOf(arrow);
    if (index != -1)
        arrows.removeAt(index);
}

void G_OBJECT::removeArrows()
{
    foreach (G_ARROW *arrow, arrows) {
        arrow->startItem()->removeArrow(arrow);
        arrow->endItem()->removeArrow(arrow);
        scene()->removeItem(arrow);
        delete arrow;
    }
}


QVariant G_OBJECT::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    if(change==QGraphicsItem::ItemPositionChange)
       {
           foreach (G_ARROW* arrow, arrows) {
               arrow->updatePosition();
           }
       }
       return value;
}

void G_OBJECT::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
     qDebug() << "double click";
}
