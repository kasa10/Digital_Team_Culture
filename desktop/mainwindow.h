#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "Semanthic/Singleton.h"
#include "Semanthic/datagenerator.h"

#include <GraphController/g_scene.h>
#include <GraphController/sceneview.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_triggered();
    void on_action_2_triggered();
    void on_action_MS_Excel_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QList<ReaderPerson> readers;
    DataGenerator* gen_dt;
    G_SCENE* scene;

};
#endif // MAINWINDOW_H
