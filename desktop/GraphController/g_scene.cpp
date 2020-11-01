#include "g_scene.h"
#include <QDebug>
#include "qdialog.h"
#include "quuid.h"
#include "qgraphicsview.h"
#include "qmessagebox.h"

#include "GraphController/personitem.h"
#include "GraphController/groupitem.h"
#include "quuid.h"



G_SCENE::G_SCENE(QObject *parent)
    : QGraphicsScene(parent)
{
    emit sendCurrentCoordinates(QPointF(0,0));
}

void G_SCENE::addObjectToRegistry(G_OBJECT *obj)
{
    //Проверяем наличие каждого элемента в списке. Если таковой существует, то просто добавляем ему группу.
    //Если отсутствует - то добавляем его в список результатов
    auto itr = std::find_if(this->sceneRegistry.begin(), this->sceneRegistry.end(), [obj](G_OBJECT* item){ return item->id()==obj->id();});

    if(itr == this->sceneRegistry.end())
        { this->sceneRegistry.append(obj); }
}

void G_SCENE::bringToFront(G_OBJECT *item) //На передний план
{
    qreal zValue = 0;
    if (item->zValue() >= zValue)
        zValue = item->zValue() + 0.1;
}

G_OBJECT *G_SCENE::getObjById(QString id) //Получение ссылки на объект по его идентификатору
{
    auto itr = std::find_if(this->sceneRegistry.begin(), this->sceneRegistry.end(), [&id](G_OBJECT* item){ return item->id()==id;});
    if(itr != this->sceneRegistry.end())
        { return (*itr); }
    else
        { return nullptr; }
}

