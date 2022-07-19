#include "chainmenu.h"
#include "ui_chainmenu.h"
#include <QPushButton>
#include <QDebug>
#include <QPainter>

int chain_number;

ChainMenu::ChainMenu(int &datanum, int &hashtable_length, char keys[][100], char values[][100], QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChainMenu)
{
    ui->setupUi(this);

    //设置窗口命名
    setWindowTitle("链地址法目录");

    //执行哈希表的建立操作
    connect(ui->BuildButton, &QPushButton::clicked, this, [=, &datanum, &hashtable_length](){
        chain_number = 1;
        ChainOperation_Scene = new ChainOperation(datanum, hashtable_length, keys, values, chain_number);
        this->hide();
        ChainOperation_Scene->show();

        //返回目录界面
        connect(ChainOperation_Scene, &ChainOperation::SceneBack, this, [=](){
            ChainOperation_Scene->hide();
            this->show();
        });
    });

    //执行哈希表的查找操作
    connect(ui->SearchButton, &QPushButton::clicked, this, [=, &datanum, &hashtable_length](){
        chain_number = 2;
        ChainOperation_Scene = new ChainOperation(datanum, hashtable_length, keys, values, chain_number);
        this->hide();
        ChainOperation_Scene->show();

        //返回目录界面
        connect(ChainOperation_Scene, &ChainOperation::SceneBack, this, [=](){
            ChainOperation_Scene->hide();
            this->show();
        });
    });

    //执行哈希表的插入操作
    connect(ui->InsertButton, &QPushButton::clicked, this, [=, &datanum, &hashtable_length](){
        chain_number = 3;
        ChainOperation_Scene = new ChainOperation(datanum, hashtable_length, keys, values, chain_number);
        this->hide();
        ChainOperation_Scene->show();

        //返回目录界面
        connect(ChainOperation_Scene, &ChainOperation::SceneBack, this, [=](){
            ChainOperation_Scene->hide();
            this->show();
        });
    });

    //执行哈希表的删除操作
    connect(ui->DeleteButton, &QPushButton::clicked, this, [=, &datanum, &hashtable_length](){
        chain_number = 4;
        ChainOperation_Scene = new ChainOperation(datanum, hashtable_length, keys, values, chain_number);
        this->hide();
        ChainOperation_Scene->show();

        //返回目录界面
        connect(ChainOperation_Scene, &ChainOperation::SceneBack, this, [=](){
            ChainOperation_Scene->hide();
            this->show();
        });
    });

    //按下退出程序按钮退出程序
    connect(ui->exitButton, &QPushButton::clicked, this, [=](){
        qDebug() << "进入CHAINMENU调试界面：";
        qDebug() <<"datanum =" << datanum;
        qDebug() <<"hashtable_length =" << hashtable_length;
        for (int i = 0; i < datanum; i++)
        {
            qDebug() << "keys[" << i << "] =" << keys[i];
            qDebug() << "values[" << i << "] =" << values[i];
        }
        this->close();
    });
}

void ChainMenu::paintEvent(QPaintEvent *)
{
    //创建画家，指定绘图设备
    QPainter painter(this);
    //创建QPixmap对象
    QPixmap pix;
    //加载图片
    pix.load(":/HashTablePicture/background5.jpg");
    //绘制背景图
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
}

ChainMenu::~ChainMenu()
{
    delete ui;
}
