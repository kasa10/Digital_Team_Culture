#include "datagenerator.h"
#include "QDateTime"
#include "QFile"
#include "qtextstream.h"


DataGenerator::DataGenerator()
{

}

QList<ReaderPerson> DataGenerator::getPersons()
{
    QList<ReaderPerson> result;
    ReaderPerson p1;
        p1.person_id=1072; p1.burth= QDateTime::fromString("23.09.1953", "dd.MM.yyyy");
        p1.books=load_books_for_person(p1.person_id);
        Event ev_1; ev_1.event_id=2836; ev_1.description="Виртуальная экскурсия по старинным русским усадьбам";
        p1.events.append(ev_1);
        result.append(p1);

    ReaderPerson p2;
        p2.person_id=1076; p2.burth= QDateTime::fromString("05.05.1974", "dd.MM.yyyy");
        p2.books=load_books_for_person(p2.person_id);
        Event e1; e1.event_id=69; e1.description="Библиотека №2 им. Ю.В. Трифонова приглашает читателей и гостей вечера на мероприятие, посвященное 140-летию со дня рождения А. Блока. Создатель поэтичного и таинственного образа Прекрасной Дамы, певец революции, автор критических";
        Event e2; e2.event_id=10292; e2.description=" Встреча писателя с приглашенными в формате диалога.";
        p2.events.append(e1); p2.events.append(e2); p2.events.append(ev_1);
        result.append(p2);

    ReaderPerson p3;
        p3.person_id=1120; p3.burth= QDateTime::fromString("09.12.1939", "dd.MM.yyyy");
        p3.books=load_books_for_person(p3.person_id);
        result.append(p3);


    ReaderPerson p4;
        p4.person_id=11521; p4.burth= QDateTime::fromString("15.09.1945", "dd.MM.yyyy");
        p4.books=load_books_for_person(p4.person_id);
        result.append(p4);

    ReaderPerson p5;
        p5.person_id=1162; p5.burth= QDateTime::fromString("10.07.1996", "dd.MM.yyyy");
        p5.books=load_books_for_person(p5.person_id);
        Event e5_1; e5_1.event_id=10902; e5_1.description="Шахматная игра-викторина.";
        Event e5_2; e5_2.event_id=1089; e5_2.description="Цель мероприятия: профилактика детского дорожного травматизма среди школьников. Участие в мероприятии способствует закреплению знаний детей о правилах дорожного движения. Мероприятие будет построено в игровой форме. При помощи презентации ребята побывают";
        Event e5_3; e5_3.event_id=2706; e5_3.description=" Участники квеста обойдут весь жилой район Ясенево и посетят главные его достопримечательности – старинные усадьбы Узкое, Ясенево и Малое Голубино, увидят исторические пруды и зелень Битцевского парка, проспекты, улицы и бульвары, а также";
        p5.events.append(e5_1); p5.events.append(e5_2); p5.events.append(e5_3);
        result.append(p5);

    ReaderPerson p6;
        p6.person_id=12738; p6.burth= QDateTime::fromString("10.06.2012", "dd.MM.yyyy");
        p6.books=load_books_for_person(p6.person_id);
        p6.events.append(e5_2);
        result.append(p6);

        return result;
}

QList<Book> DataGenerator::load_books_for_person(int person_id)
{
    QList<Book> result;
    QFile f("://assets/dataset.db");
    if ((f.exists())&&(f.open(QIODevice::ReadOnly)))
    {
        QTextStream out(&f);
        QStringList lines = out.readAll().split("\n");
        for(auto line: lines)
        {
            auto d = line.split("\t");
            if((d.count()>2) && d[0].toInt()==person_id)
            {
                Book b;
                b.book_id=d[6].toUInt();
                b.author=d[7].toStdString();
                b.caption=d[8].toStdString();
                b.category=d[9].toStdString();
                result.append(b);
            }

        }
        f.close();
    }
    return result;
}
