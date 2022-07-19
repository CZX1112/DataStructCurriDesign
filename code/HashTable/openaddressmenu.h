#ifndef OPENADDRESSMENU_H
#define OPENADDRESSMENU_H

#include <QWidget>
#include "openaddressoperation.h"

namespace Ui {
class OpenAddressMenu;
}

class OpenAddressMenu : public QWidget
{
    Q_OBJECT

public:
    explicit OpenAddressMenu(int &datanum, int &hashtable_length, char keys[][100], char values[][100], QWidget *parent = nullptr);
    ~OpenAddressMenu();
    OpenAddressOperation * OpenAddressOperation_Scene = NULL;

private:
    Ui::OpenAddressMenu *ui;
};

#endif // OPENADDRESSMENU_H
