#ifndef G_OBJECT_H
#define G_OBJECT_H

#include <QList>
#include <QString>
#include <QPixmap>
#include <QPolygonF>
#include "QGraphicsPixmapItem"
#include "qgraphicssvgitem.h"
#include <QBrush>
#include <QPen>
#include <QDate>
#include <QFontDatabase>
#include <QFont>
#include <QResource>
#include <QList>
#include <QString>
#include <QBrush>
#include <QDate>

class G_ARROW;

class G_OBJECT: public QGraphicsPolygonItem
{

public:
    enum { Type = UserType + 15 };
    G_OBJECT(QGraphicsItem* parent=nullptr); //Инициализация объекта


    //Виртуальные функции, обязательные в любо объекте
    virtual ~G_OBJECT() override{}


    //Функции возврата
    QString id(){ return this->identificator; } //Функция, предоставляющая id объекта на схеме
    void setId(QString id) {this->identificator=id;}

    //Функции и процедуры графики
    void addArrow(G_ARROW *arrow); //Процедура, добавляющая стрелку в объект
    void removeArrow(G_ARROW *arrow);
    void removeArrows();
    int type() const override { return Type;}




protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;



    //Приватные экспортируемые невидимые функции объекта на схеме
private:
    QString identificator;
    QList<G_ARROW*> arrows;


};

#endif // G_OBJECT_H
