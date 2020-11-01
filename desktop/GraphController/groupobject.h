#ifndef GROUPOBJECT_H
#define GROUPOBJECT_H
#include "GraphController/g_object.h"
#include "GraphController/groupitem.h"



class GroupObject : public G_OBJECT
{
public:
    explicit GroupObject(GroupItem* p, QGraphicsItem *parent = nullptr);
    ~GroupObject() override{}
    GroupItem* groupItem() { return this->group_obj; }

private:
    QGraphicsItemGroup* group;
    QPolygonF myPolygon;
    QFont font;

    QGraphicsPixmapItem* itemPix; //Элемент картинки пользователя
    QGraphicsTextItem* group_id; //отображение id
    QGraphicsTextItem* group_name; //Название группы
    QGraphicsTextItem* group_descr; //Название группы

    QList<G_ARROW*> arrows;
    void setPolygonSize(double width, double height);
    double width, height;
    GroupItem* group_obj; //Ссылка на объект группы
};

#endif // GROUPOBJECT_H
