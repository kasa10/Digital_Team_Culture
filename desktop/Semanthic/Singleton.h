#ifndef SingletonLibrary_H
#define SingletonLibrary_H

#include <QObject>
#include "qdebug.h"
#include "qdatetime.h"

struct Book
{
    unsigned long long book_id;
    std::string author;
    std::string caption;
    std::string city;
    std::string publishment;
    std::string category;
};

struct Order {
    unsigned long long order_id;

};

struct Event{
    unsigned long long event_id;
    QString description;
};

struct ReaderPerson
{
    unsigned long long person_id;
    QDateTime burth;
    QList<Book> books;
    QList<Event> events;
};

class SingletonLibrary;  // опережающее объявление

class SingletonLibraryDestroyer
{
  private:
    SingletonLibrary* p_instance;
  public:
    ~SingletonLibraryDestroyer();
    void initialize( SingletonLibrary* p );
};


class SingletonLibrary : public QObject
{
    Q_OBJECT

private:
    static SingletonLibrary* p_instance;
    static SingletonLibraryDestroyer destroyer;
protected:
    explicit SingletonLibrary(QObject *parent = nullptr);
    SingletonLibrary( const SingletonLibrary& );
    SingletonLibrary& operator=( SingletonLibrary& );
    ~SingletonLibrary() { }
    friend class SingletonLibraryDestroyer;

public:
    static SingletonLibrary& getInstance();

    //Специальные параметры
    struct ReactConstants
    {
        std::string person_reader_filename = "D:/Документы/Лидеры цифровой трансформации/data_set/readers.csv";

    } react_constants;
};

#endif // SingletonLibrary_H
