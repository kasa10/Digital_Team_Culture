#ifndef HUMANOBJECT_H
#define HUMANOBJECT_H
#include "GraphController/g_object.h"
#include "GraphController/personitem.h"



class HumanObject : public G_OBJECT
{
public:
    explicit HumanObject(PersonItem* p, QGraphicsItem *parent = nullptr);
    ~HumanObject() override{}
    PersonItem* personItem() { return this->person; }

private:
    QGraphicsItemGroup* group;
    QPolygonF myPolygon;
    QFont font;

    QGraphicsSvgItem* itemPix; //Элемент картинки пользователя
    QGraphicsTextItem* text_id; //отображение id
    QGraphicsTextItem* surname_name; //имя, фамилия
    QList<G_ARROW*> arrows;
    void setPolygonSize(double width, double height);
    double width, height;
    PersonItem* person; //Ссылка на объект персоны
};

#endif // HUMANOBJECT_H
