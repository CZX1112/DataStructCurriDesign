#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置应用图片
    this->setWindowIcon(QPixmap(":/OlympicsPicture/FiveRings2.jfif"));
    ui->inputButton->setIcon(QPixmap(":/OlympicsPicture/FiveRings.jfif"));

    //设置窗口命名
    setWindowTitle("奥运会成绩录入系统");

    //实例化输入数据场景
    inputscene = new InputData;

    //跳转输入界面
    connect(ui->inputButton, &QPushButton::clicked, this, [=](){
        this->close();
        inputscene->show();
    });

}

void Widget::paintEvent(QPaintEvent *)
{
    //创建画家，指定绘图设备
    QPainter painter(this);
    //创建QPixmap对象
    QPixmap pix;
    //加载图片
    pix.load(":/OlympicsPicture/background2.jfif");
    //绘制背景图
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
}

Widget::~Widget()
{
    delete ui;
}
