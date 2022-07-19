#include "output.h"
#include "ui_output.h"

OutPut::OutPut(headnode *h, int &country_num, int &eventnum_man, int &eventnum_woman, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OutPut)
{
    ui->setupUi(this);

    //固定窗口大小
    resize(500, 400);

    //设置窗口命名
    setWindowTitle("输出信息");


}

OutPut::~OutPut()
{
    delete ui;
}
