#include "personitem.h"

PersonItem::PersonItem(unsigned long int id, QObject *parent) : QObject(parent)
{
    this->_id = id;
}

void PersonItem::setData(std::string surname, std::string name, PersonItem::Sex sex, bool can_access_closed)
{
    this->_surname = surname;
    this->_name = name;
    this->_sex = sex;
    this->_can_access_closed = can_access_closed;
}

void PersonItem::addGroup(GroupItem *groupItem)
{
    this->_groups.append(groupItem);
}
