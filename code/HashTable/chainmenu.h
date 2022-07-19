#ifndef CHAINMENU_H
#define CHAINMENU_H

#include <QWidget>
#include "chainoperation.h"

namespace Ui {
class ChainMenu;
}

class ChainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit ChainMenu(int &datanum, int &hashtable_length, char keys[][100], char values[][100], QWidget *parent = nullptr);
    ~ChainMenu();
    void paintEvent(QPaintEvent *);

    ChainOperation * ChainOperation_Scene = NULL;


private:
    Ui::ChainMenu *ui;
};

#endif // CHAINMENU_H
