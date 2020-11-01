#ifndef BookItem_H
#define BookItem_H
#include "GraphController/g_object.h"
#include "../Semanthic/Singleton.h"



class BookItem : public G_OBJECT
{
public:
    explicit BookItem(Book* p, QGraphicsItem *parent = nullptr);
    ~BookItem() override{}
    Book* groupItem() { return this->book_obj; }

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
    Book* book_obj; //Ссылка на объект группы
};

#endif // BookItem_H
