#pragma once
#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include "output_search.h"

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(headnode *h, int &country_num, QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    ~Menu();

    OutPut_Search * outputsearchscene = NULL;

signals:
    void SceneBack();

private:
    Ui::Menu *ui;
};

#endif // MENU_H
