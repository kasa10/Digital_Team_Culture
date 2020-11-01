#include "groupitem.h"

GroupItem::GroupItem(unsigned int group_id, QObject *parent) : QObject(parent)
{
    this->_group_id = group_id;
}

void GroupItem::setData(std::string name, std::string description)
{
    this->_name=name;
    this->_description=description;
}
