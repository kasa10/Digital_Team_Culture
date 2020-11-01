#include "Singleton.h"

SingletonLibrary * SingletonLibrary::p_instance = 0;
SingletonLibraryDestroyer SingletonLibrary::destroyer;

SingletonLibraryDestroyer::~SingletonLibraryDestroyer() {
    delete p_instance;
}

void SingletonLibraryDestroyer::initialize( SingletonLibrary* p ) {
    p_instance = p;
}

SingletonLibrary& SingletonLibrary::getInstance() {
    if(!p_instance)     {
        p_instance = new SingletonLibrary();
        destroyer.initialize( p_instance);
    }
    return *p_instance;
}

SingletonLibrary::SingletonLibrary(QObject *parent) : QObject(parent)
{

}
