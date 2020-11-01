#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtXLSX/xlsxdocument.h"
#include <QInputDialog>
#include <QDebug>
#include <thread>
#include <future>
#include <QFile>

#include "GraphController/humanobject.h"
#include "GraphController/groupobject.h"
#include "GraphController/bookitem.h"
#include "GraphController/g_arrow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->gen_dt=new DataGenerator();
    this->readers = this->gen_dt->getPersons();
    ui->quickWidget->setSource(QUrl("qrc:/MapReducer.qml"));
    for (auto p: this->readers ) {
        ui->comboBox->addItem(QIcon("://assets/img/user64.png"), "Читатель: "+QString::number(p.person_id));
    }

    scene = new G_SCENE(); ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_triggered() //проанализировать пользователя
{
    ui->stackedWidget->setCurrentWidget(ui->pgAnalize);
}

void MainWindow::on_action_2_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->pgMap); //Показать карту предпочтений
    this->setWindowTitle("Предпочтения ");

}

void MainWindow::on_action_MS_Excel_triggered() //Загрузить данные из Excel
{
    //Создать собственный датасет с читателями

}

void MainWindow::on_pushButton_clicked() //Кнопка "Проанализировать"
{

    if(ui->checkBox->isChecked())
    {
        for(auto person: this->readers)
        {
            PersonItem* p = new PersonItem(person.person_id);
            p->setData("Фамилия, ", "Имя", PersonItem::Male, true);
            HumanObject* obj1 = new HumanObject(p);
            obj1->setId("human"+QString::number(p->id()));
            scene->addObjectToRegistry(obj1);
            scene->addItem(obj1);

            if(ui->checkBox_2->isChecked())
            {
                for(auto book: person.books)
                {
                    //Сначала книги
                    auto check=scene->getObjById("book"+QString::number(book.book_id));
                    if(check==nullptr)
                    {
                        BookItem* obj_book1 = new BookItem(&book);
                        obj_book1->setId("book"+QString::number(book.book_id));
                        scene->addObjectToRegistry(obj_book1);
                        scene->addItem(obj_book1);

                        if(scene->items().count()<100)
                            obj_book1->setPos(qrand()%1000, qrand()%1000);
                        else
                            obj_book1->setPos(qrand()%(scene->items().count()*30), qrand()%(scene->items().count()*30));

                        G_ARROW* arr = new G_ARROW(
                                scene->getObjById("human"+QString::number(p->id())),
                                scene->getObjById("book"+QString::number(book.book_id))
                                    );
                        scene->addItem(arr);
                    }
                    else
                    {
                        G_ARROW* arr = new G_ARROW(
                                scene->getObjById("human"+QString::number(p->id())),
                                scene->getObjById("book"+QString::number(book.book_id))
                                    );
                        scene->addItem(arr);
                    }
                }
            }

            if(ui->checkBox_3->isChecked())
            {
                for(auto event: person.events)
                {
                    //Затем события
                    auto check=scene->getObjById("event"+QString::number(event.event_id));
                    if(check==nullptr)
                    {
                        GroupItem* g = new GroupItem(event.event_id);
                        g->setData("Событие:", event.description.toStdString());
                        GroupObject* obj2 = new GroupObject(g);
                        obj2->setId("event"+QString::number(g->group_id()));
                        scene->addObjectToRegistry(obj2);
                        scene->addItem(obj2);

                        if(scene->items().count()<100)
                            obj2->setPos(qrand()%1000, qrand()%1000);
                        else
                            obj2->setPos(qrand()%(scene->items().count()*30), qrand()%(scene->items().count()*30));

                        G_ARROW* arr = new G_ARROW(scene->getObjById("human"+QString::number(p->id())),
                                                   scene->getObjById("event"+QString::number(event.event_id)));
                        scene->addItem(arr);
                    }
                    else {
                        G_ARROW* arr = new G_ARROW(scene->getObjById("human"+QString::number(p->id())),
                                                   scene->getObjById("event"+QString::number(event.event_id)));
                        scene->addItem(arr);
                    }
                }
            }
        }
    }

    else
    {
        for(auto person: this->readers)
        {
            if(person.person_id==this->readers[ui->comboBox->currentIndex()].person_id)
            {
                PersonItem* p = new PersonItem(person.person_id);
                p->setData("Фамилия, ", "Имя", PersonItem::Male, true);
                HumanObject* obj1 = new HumanObject(p);
                obj1->setId("human"+QString::number(p->id()));
                scene->addObjectToRegistry(obj1);
                scene->addItem(obj1);

                if(ui->checkBox_2->isChecked())
                {
                    for(auto book: person.books)
                    {
                        //Сначала книги
                        auto check=scene->getObjById("book"+QString::number(book.book_id));
                        if(check==nullptr)
                        {
                            BookItem* obj_book1 = new BookItem(&book);
                            obj_book1->setId("book"+QString::number(book.book_id));
                            scene->addObjectToRegistry(obj_book1);
                            scene->addItem(obj_book1);

                            if(scene->items().count()<100)
                                obj_book1->setPos(qrand()%1000, qrand()%1000);
                            else
                                obj_book1->setPos(qrand()%(scene->items().count()*30), qrand()%(scene->items().count()*30));

                            G_ARROW* arr = new G_ARROW(
                                    scene->getObjById("human"+QString::number(p->id())),
                                    scene->getObjById("book"+QString::number(book.book_id))
                                        );
                            scene->addItem(arr);
                        }
                        else
                        {
                            G_ARROW* arr = new G_ARROW(
                                    scene->getObjById("human"+QString::number(p->id())),
                                    scene->getObjById("book"+QString::number(book.book_id))
                                        );
                            scene->addItem(arr);
                        }
                    }
                }

                if(ui->checkBox_3->isChecked())
                {
                    for(auto event: person.events)
                    {
                        //Затем события
                        auto check=scene->getObjById("event"+QString::number(event.event_id));
                        if(check==nullptr)
                        {
                            GroupItem* g = new GroupItem(event.event_id);
                            g->setData("Событие:", event.description.toStdString());
                            GroupObject* obj2 = new GroupObject(g);
                            obj2->setId("event"+QString::number(g->group_id()));
                            scene->addObjectToRegistry(obj2);
                            scene->addItem(obj2);

                            if(scene->items().count()<100)
                                obj2->setPos(qrand()%1000, qrand()%1000);
                            else
                                obj2->setPos(qrand()%(scene->items().count()*30), qrand()%(scene->items().count()*30));

                            G_ARROW* arr = new G_ARROW(scene->getObjById("human"+QString::number(p->id())),
                                                       scene->getObjById("event"+QString::number(event.event_id)));
                            scene->addItem(arr);
                        }
                        else {
                            G_ARROW* arr = new G_ARROW(scene->getObjById("human"+QString::number(p->id())),
                                                       scene->getObjById("event"+QString::number(event.event_id)));
                            scene->addItem(arr);
                        }
                    }
                }
            }
        }
    }

}
