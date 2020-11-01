#include "sceneview.h"

SceneView::SceneView(QWidget *parent)
    :QGraphicsView(parent)
{

}

void SceneView::wheelEvent(QWheelEvent *event)
{
    const double scaleFactor = 1.15;
    if(event->delta()>0)
    {
        scale(scaleFactor, scaleFactor);
    }else{
        scale(1.0/scaleFactor, 1.0/scaleFactor);
    }
}
