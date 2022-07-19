#ifndef OPENADDRESSINPUT_H
#define OPENADDRESSINPUT_H

#include <QWidget>
#include "openaddressmenu.h"

namespace Ui {
class OpenAddressInput;
}

class OpenAddressInput : public QWidget
{
    Q_OBJECT

public:
    explicit OpenAddressInput(QWidget *parent = nullptr);
    ~OpenAddressInput();
    OpenAddressMenu * OpenAddressMenu_Scene = NULL;

private:
    Ui::OpenAddressInput *ui;
};

#endif // OPENADDRESSINPUT_H
