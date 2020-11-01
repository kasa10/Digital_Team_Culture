#ifndef DATAGENERATOR_H
#define DATAGENERATOR_H
#include "Singleton.h"

class DataGenerator
{
public:
    DataGenerator();
    QList<ReaderPerson> getPersons();
    QList<Book> load_books_for_person(int person_id);
};

#endif // DATAGENERATOR_H
