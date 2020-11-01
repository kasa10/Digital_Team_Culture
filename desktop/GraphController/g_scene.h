#ifndef G_SCENE_H
#define G_SCENE_H

#include "GraphController/g_object.h"
#include "GraphController/g_arrow.h"
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class G_SCENE : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit G_SCENE(QObject *parent = nullptr);
    void addObjectToRegistry(G_OBJECT* obj);
    G_OBJECT* getObjById(QString id);

signals:
    void sendCurrentCoordinates(QPointF coordinates);
    void itemInserted(G_OBJECT *item);

private:
    QPointF startPoint;
    void bringToFront(G_OBJECT *item);
    QGraphicsLineItem *line;
    QList<G_OBJECT*> sceneRegistry;
};

#endif // G_SCENE_H
