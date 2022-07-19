#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QLabel>
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置窗口命名
    setWindowTitle("哈希表");

    //进入链地址输入界面
    connect(ui->inputButton, &QPushButton::clicked, this, [=](){
        ChainInput_Scene = new ChainInput;
        this->close();
        ChainInput_Scene->show();
    });

}

void Widget::paintEvent(QPaintEvent *)
{
    //创建画家，指定绘图设备
    QPainter painter(this);
    //创建QPixmap对象
    QPixmap pix;
    //加载图片
    pix.load(":/HashTablePicture/background3.jpg");
    //绘制背景图
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
}

Widget::~Widget()
{
    delete ui;
}
