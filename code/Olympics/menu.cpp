#include "menu.h"
#include "ui_menu.h"
#include <QDebug>
#include <QPainter>

Menu::Menu(headnode *h, int &country_num, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);

    //设置窗口命名
    this->setWindowIcon(QPixmap(":/OlympicsPicture/picture2.jfif"));
    setWindowTitle("目录");

    //按输入信息按钮返回输入界面
    connect(ui->inputButton, &QPushButton::clicked, this, [=](){
        emit this->SceneBack();
    });

    //按输出信息按钮进入输出界面
    connect(ui->outputButton, &QPushButton::clicked, this, [=, &country_num](){
        outputsearchscene = new OutPut_Search(h, country_num);
        this->hide();
        outputsearchscene->show();

        connect(outputsearchscene, &OutPut_Search::SceneBack, this, [=](){
            outputsearchscene->hide();
            this->show();
        });
    });

    //按查询信息按钮进入查询界面
    connect(ui->searchButton, &QPushButton::clicked, this, [=, &country_num](){
        outputsearchscene = new OutPut_Search(h, country_num);
        this->close();
        outputsearchscene->show();

        connect(outputsearchscene, &OutPut_Search::SceneBack, this, [=](){
            outputsearchscene->hide();
            this->show();
        });
    });


    //按退出按钮退出
    connect(ui->exitButton, &QPushButton::clicked, this, &QWidget::close);

}

void Menu::paintEvent(QPaintEvent *)
{
    //创建画家，指定绘图设备
    QPainter painter(this);
    //创建QPixmap对象
    QPixmap pix;
    //加载图片
    pix.load(":/OlympicsPicture/background4.jfif");
    //绘制背景图
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
}

Menu::~Menu()
{
    delete ui;
}
