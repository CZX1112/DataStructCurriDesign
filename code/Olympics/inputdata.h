#pragma once
#ifndef INPUTDATA_H
#define INPUTDATA_H

#include <QWidget>
#include "menu.h"

namespace Ui {
class InputData;
}

class InputData : public QWidget
{
    Q_OBJECT

public:
    explicit InputData(QWidget *parent = nullptr);
    ~InputData();
    void paintEvent(QPaintEvent *);
    Menu * menuscene = NULL;

private:
    Ui::InputData *ui;
};

#endif // INPUTDATA_H
