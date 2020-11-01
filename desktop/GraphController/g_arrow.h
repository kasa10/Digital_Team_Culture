#ifndef G_ARROW_H
#define G_ARROW_H

#include <QGraphicsLineItem>
#include "GraphController/g_object.h"

class QGraphicsPolygonItem;
class QGraphicsLineItem;
class QGraphicsScene;
class QRectF;
class QGraphicsSceneMouseEvent;
class QPainterPath;

class G_ARROW : public QGraphicsLineItem
{

public:
    G_ARROW(G_OBJECT* startItem, G_OBJECT* endItem, QGraphicsItem *parent = 0);
    G_ARROW(G_OBJECT* startItem, G_OBJECT* endItem, QColor color, int size, QString caption, QGraphicsItem *parent = 0);
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void setColor(const QColor &color) { myColor = color; }
    G_OBJECT *startItem() const { return myStartItem; }
    G_OBJECT *endItem() const { return myEndItem; }
    void updatePosition();
    QString startId(); QString endId(); QColor getColor(); int getSize(); QString getCaption();
    QString indicate() {return "g_arrow";}


protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;

private:
    G_OBJECT *myStartItem;
    G_OBJECT *myEndItem;
    QColor myColor;
    int mySize;
    QPolygonF arrowHead;

    int textSymCount;
    QGraphicsTextItem* text;
    QGraphicsRectItem* rect;
    bool isWithCaption;
};

#endif // G_ARROW_H
