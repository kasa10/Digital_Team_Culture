#ifndef SCENEVIEW_H
#define SCENEVIEW_H

#include <QGraphicsView>
#include <QWheelEvent>
#include <QObject>

class SceneView : public QGraphicsView
{
    Q_OBJECT
public:
    SceneView(QWidget *parent = nullptr);

protected:
    void wheelEvent(QWheelEvent *event);
};

#endif // SCENEVIEW_H
