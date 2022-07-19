#ifndef CHAININPUT_H
#define CHAININPUT_H

#include <QWidget>
#include "chainmenu.h"

namespace Ui {
class ChainInput;
}

class ChainInput : public QWidget
{
    Q_OBJECT

public:
    explicit ChainInput(QWidget *parent = nullptr);
    ~ChainInput();
    void paintEvent(QPaintEvent *);

    ChainMenu * ChainMenu_Scene = NULL;

private:
    Ui::ChainInput *ui;
};

#endif // CHAININPUT_H
