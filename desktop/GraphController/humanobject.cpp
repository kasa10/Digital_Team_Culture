#include "humanobject.h"

HumanObject::HumanObject(PersonItem *p, QGraphicsItem *parent)
    : G_OBJECT(parent)
{
    //Инициализация привязки к объекту
    this->person = p;

    //Инициализация шрифта
    int font_id = QFontDatabase::addApplicationFont(QString(":/assets/fonts/Ubuntu-R.ttf"));
    QString family = QFontDatabase::applicationFontFamilies(font_id).at(0);
    this->font=QFont(family);
    this->font.setLetterSpacing(QFont::AbsoluteSpacing, qreal(0.05));
    this->font.setPointSize(8);

    int font_id2 = QFontDatabase::addApplicationFont(QString(":/assets/fonts/Play Bold.ttf"));
    QString family2 = QFontDatabase::applicationFontFamilies(font_id2).at(0);
    QFont font2(family);
    font2.setLetterSpacing(QFont::AbsoluteSpacing, qreal(0.05));
    font2.setPointSize(12);
    font2.setBold(true);

    //Инициализация группы
    group=new QGraphicsItemGroup;
    group->addToGroup(this);
    this->setAcceptHoverEvents(true);
    const int zoomAlpha=2; //Значение масштаба

    //Инициализируем свойства данного объекта
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
    setPen(Qt::NoPen);
    setBrush(Qt::NoBrush);

    //Инициализируем базовый размер фигуры
    this->setPolygonSize(200, 120);

    //определение пола
    if(this->person->sex()==PersonItem::Sex::Male)
        this->itemPix=new QGraphicsSvgItem(QString(":/assets/img/male.svg"), this);
    else
        this->itemPix=new QGraphicsSvgItem(QString(":/assets/img/female.svg"), this);

    itemPix->setScale(zoomAlpha);
    itemPix->setPos(-50, -60);

    this->text_id=new QGraphicsTextItem(this);
    this->text_id->setPlainText("Читатель: "+QString::number(this->person->id()));
    this->text_id->setFont(this->font);
    this->text_id->setDefaultTextColor(QColor(Qt::blue));
    this->text_id->setPos(-100, 17);

    this->surname_name = new QGraphicsTextItem(this);
    this->surname_name->setPlainText(QString::fromStdString(this->person->name())+" "+QString::fromStdString(this->person->surname()));
    this->surname_name->setFont(font2);
    this->surname_name->setPos(-100, 30);
}

void HumanObject::setPolygonSize(double width, double height)
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
