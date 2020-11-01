#include "groupobject.h"

GroupObject::GroupObject(GroupItem *p, QGraphicsItem *parent)
    : G_OBJECT(parent)
{
    //Инициализация привязки к объекту
    this->group_obj = p;

    //Инициализация шрифта
    int font_id = QFontDatabase::addApplicationFont(QString(":/assets/fonts/Ubuntu-R.ttf"));
    QString family = QFontDatabase::applicationFontFamilies(font_id).at(0);
    this->font=QFont(family);
    this->font.setLetterSpacing(QFont::AbsoluteSpacing, qreal(0.05));
    this->font.setPointSize(7);

    int font_id2 = QFontDatabase::addApplicationFont(QString(":/assets/fonts/Play Bold.ttf"));
    QString family2 = QFontDatabase::applicationFontFamilies(font_id2).at(0);
    QFont font2(family);
    font2.setLetterSpacing(QFont::AbsoluteSpacing, qreal(0.05));
    font2.setPointSize(13);
    font2.setBold(true);

    //Инициализация группы
    group=new QGraphicsItemGroup;
    group->addToGroup(this);
    this->setAcceptHoverEvents(true);
    const double zoomAlpha=0.2; //Значение масштаба

    //Инициализируем свойства данного объекта
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
    setPen(QPen(Qt::black, 0.5));
    setBrush(Qt::NoBrush);

    //Инициализируем базовый размер фигуры
    this->setPolygonSize(400, 80);

    this->itemPix=new QGraphicsPixmapItem(QString("://assets/img/event.png"), this);
    itemPix->setScale(zoomAlpha);
    itemPix->setPos(-200, -60);

    this->group_id=new QGraphicsTextItem(this);
    this->group_id->setPlainText("ID группы: "+QString::number(this->group_obj->group_id()));
    this->group_id->setPos(-200, 38);

    this->group_name = new QGraphicsTextItem(this);
    this->group_name->setPlainText(QString::fromStdString(this->group_obj->name()).replace("\t"," ").replace("\n"," ").left(30));
    this->group_name->setFont(font2);
    this->group_name->setPos(-90, -40);

    this->group_descr = new QGraphicsTextItem(this);
    this->group_descr->setPlainText(QString::fromStdString(this->group_obj->description()).replace("\t"," ").replace("\n"," ").left(200));
    this->group_descr->setTextWidth(290);
    this->group_descr->setFont(font);
    this->group_descr->setPos(-90, -20);

}

void GroupObject::setPolygonSize(double width, double height)
{
    //  4          3
    //
    //
    //  1          2

    myPolygon.clear();
    myPolygon << QPointF(-1*(width/2), -1*(height/2))                   //1      0
              << QPointF((-1*(width/2))+width, -1*(height/2))           //2      1
              << QPointF((-1*(width/2))+width, (-1*(height/2))+height)  //3      2
              << QPointF(-1*(width/2), (-1*(height/2))+height)          //4      3
              << QPointF(-1*(width/2), -1*(height/2));                  //1      4
    this->setPolygon(myPolygon);
    this->height=this->boundingRect().height();
    this->width=this->boundingRect().width();
}
