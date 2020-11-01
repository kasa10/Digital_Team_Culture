#include "g_arrow.h"
#include <qmath.h>
#include <QPen>
#include <QPainter>
#include "qdebug.h"


G_ARROW::G_ARROW(G_OBJECT *startItem, G_OBJECT *endItem, QGraphicsItem *parent)
{
    myStartItem = startItem;
    myEndItem = endItem;
    this->isWithCaption=false;
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    myColor = QColor::fromRgb(0,0,1);
    setPen(QPen(myColor, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
}

G_ARROW::G_ARROW(G_OBJECT *startItem, G_OBJECT *endItem, QColor color, int size, QString caption, QGraphicsItem *parent)
{
    myStartItem = startItem;
    myEndItem = endItem;
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    myColor = color;
    this->isWithCaption=false;
    mySize=size;
    setPen(QPen(myColor, size, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    this->textSymCount=caption.count();
    if(textSymCount>0){
        isWithCaption=true;
        rect=new QGraphicsRectItem(this);
        rect->setBrush(QBrush(Qt::white));
        rect->setPen(QPen(color, size));

        this->text=new QGraphicsTextItem(this);
        this->text->setPlainText(caption);
    }
}

QRectF G_ARROW::boundingRect() const
{
    qreal extra = (pen().width() + 20) / 2.0;
    return QRectF(line().p1(), QSizeF(line().p2().x() - line().p1().x(),
                                      line().p2().y() - line().p1().y()))
        .normalized()
        .adjusted(-extra, -extra, extra, extra);
}

QPainterPath G_ARROW::shape() const
{
    QPainterPath path = QGraphicsLineItem::shape();
    path.addPolygon(arrowHead);
    return path;
}

void G_ARROW::updatePosition()
{
    QLineF line(mapFromItem(myStartItem, 0, 0), mapFromItem(myEndItem, 0, 0));
        setLine(line);
        if(textSymCount>0)
        {
            qreal pos_x1=((mapFromItem(myStartItem, 0, 0).x()-text->toPlainText().count()*13/2)+mapFromItem(myEndItem,0,0).x())/2;
            qreal pos_y1= (mapFromItem(myStartItem, 0, 0).y()+mapFromItem(myEndItem, 0,0).y())/2;
            this->rect->setPos(pos_x1, pos_y1);
            this->rect->setRect(text->boundingRect());
            this->text->setPos(pos_x1, pos_y1);
        }
}

QString G_ARROW::startId() //Получаем идентификатор стартового элемента
{
    return this->myStartItem->id();
}

QString G_ARROW::endId()
{
    return this->myEndItem->id();
}

QColor G_ARROW::getColor()
{
    return this->myColor;
}

int G_ARROW::getSize()
{
    return this->mySize;
}

QString G_ARROW::getCaption()
{
    if (this->isWithCaption==true){
        return this->text->toPlainText();
    }
    else{
        return "";
    }

}

void G_ARROW::paint(QPainter *painter, const QStyleOptionGraphicsItem *,
          QWidget *)
{
    if (myStartItem->collidesWithItem(myEndItem))
        return;

    //Инициализируем
    QPen myPen = pen();
    myPen.setColor(myColor);
    qreal arrowSize = 7;
    painter->setPen(myPen);
    painter->setBrush(myColor);

    QLineF centerLine(myStartItem->pos(), myEndItem->pos());
    QPolygonF endPolygon = myEndItem->polygon();
    QPolygonF startPolygon = myStartItem->polygon();

    QPointF p1 = endPolygon.first() + myEndItem->pos();
    QPointF p2;

    QPointF p11 = startPolygon.first() + myStartItem->pos();
    QPointF p12;

    QPointF intersectPoint, intersectpoint1;
    QLineF polyLine, polyline1;

    //Первый объект
    for (int i = 1; i < startPolygon.count(); ++i) {
        p12 = startPolygon.at(i) + myStartItem->pos();
        polyline1 = QLineF(p11, p12);
        QLineF::IntersectType intersectType =
            polyline1.intersect(centerLine, &intersectpoint1);
        if (intersectType == QLineF::BoundedIntersection)
            break;
        p11 = p12;
    }

    //Второй объект
    for (int i = 1; i < endPolygon.count(); ++i) {
        p2 = endPolygon.at(i) + myEndItem->pos();
        polyLine = QLineF(p1, p2);
        QLineF::IntersectType intersectType =
            polyLine.intersect(centerLine, &intersectPoint);
        if (intersectType == QLineF::BoundedIntersection)
            break;
        p1 = p2;
    }



    setLine(QLineF(intersectPoint, intersectpoint1));

    double angle = std::atan2(-line().dy(), line().dx());

    QPointF arrowP1 = line().p1() + QPointF(sin(angle + M_PI / 3) * arrowSize,
    cos(angle + M_PI / 3) * arrowSize);
    QPointF arrowP2 = line().p1() + QPointF(sin(angle + M_PI - M_PI / 3) * arrowSize,
    cos(angle + M_PI - M_PI / 3) * arrowSize);

    arrowHead.clear();
    arrowHead << line().p1() << arrowP1 << arrowP2;
    painter->drawLine(line());
    painter->drawPolygon(arrowHead);
    if (isSelected()) {
    painter->setPen(QPen(myColor, 1, Qt::DashLine));
    QLineF myLine = line();
    myLine.translate(0, 4.0);
    painter->drawLine(myLine);
    myLine.translate(0,-8.0);
    painter->drawLine(myLine);
    }
}
