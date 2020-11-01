#ifndef GROUPITEM_H
#define GROUPITEM_H

#include <QObject>

class GroupItem : public QObject
{
    Q_OBJECT
public:
    explicit GroupItem(unsigned int group_id, QObject *parent = nullptr);
    void setData(std::string name, std::string description);

    unsigned int group_id() const { return _group_id; }
    std::string name() const { return _name; }
    std::string description() const { return _description; }

private:
    unsigned int _group_id;
    std::string _name;
    std::string _description;
};

#endif // GROUPITEM_H
