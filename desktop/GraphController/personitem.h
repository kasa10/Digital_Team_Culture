#ifndef PERSONITEM_H
#define PERSONITEM_H

#include <QObject>
#include <GraphController/groupitem.h>

class PersonItem : public QObject
{
    Q_OBJECT

public:
    enum Sex {Male, Female};
    explicit PersonItem(unsigned long int id, QObject *parent = nullptr);


    void setData(std::string surname, std::string name, Sex sex, bool can_access_closed);
    unsigned long int id() const { return _id; }
    std::string surname() const { return _surname; }
    std::string name() const { return _name; }
    Sex sex() const { return _sex; }
    bool canAccessClosed() { return _can_access_closed; }

    void addGroup(GroupItem* groupItem);
    QList<GroupItem*> groups() const { return this->_groups; }


private:
    unsigned long int _id; //id вконтакте
    std::string _surname;
    std::string _name;
    Sex _sex;
    bool _can_access_closed;
    QList<GroupItem*> _groups;
};

#endif // PERSONITEM_H
