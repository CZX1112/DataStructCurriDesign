#include "chaininput.h"
#include "ui_chaininput.h"
#include <QPushButton>
#include <QSpinBox>
#include <QDebug>
#include <QString>
#include <QLabel>
#include <QFont>
#include <QPainter>
#include <QLineEdit>

//定义数据量、哈希表长度
int datanum;
int hashtable_length;
char keys[100][100];
char values[100][100];

int count;

ChainInput::ChainInput(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChainInput)
{
    ui->setupUi(this);

    //设置窗口命名
    setWindowTitle("链地址法");

    //初始化界面
    ui->label_5->setVisible(false);
    ui->label_5->setText("数据序号：NO." + QString::number(1) + "  ");
    ui->NextButton->setVisible(false);

    //获取数据量、哈希表长度
    connect(ui->pushButton, &QPushButton::clicked, this, [=](){
        datanum = ui->spinBox_datanum->value();
        hashtable_length = ui->spinBox_hashtable_length->value();

        qDebug() << "datanum =" << datanum;
        qDebug() << "hashtable_length =" << hashtable_length;

        QLabel * ValueNotFound_label = new QLabel("哈希表长度为0，请重新输入！", this);
        QFont ValueNotFound_label_font("SimSun", 16, 75);
        ValueNotFound_label->setFont(ValueNotFound_label_font);
        ValueNotFound_label->setVisible(false);
        ValueNotFound_label->move(80, 230);

        if (hashtable_length == 0)
        {
            ValueNotFound_label->setVisible(true);
        }
        else
        {
            ui->NextButton->setVisible(true);
            ui->label_5->setVisible(true);

            ValueNotFound_label->setVisible(false);

            count = 0;

            //输入标签
            QFont label_font("SimSun", 12);
            QLabel * KeyWords_label = new QLabel("关键字：", this);
            KeyWords_label->setFont(label_font);
            KeyWords_label->setVisible(true);
            KeyWords_label->move(110, 220);
            QLabel * Values_label = new QLabel("数据值：", this);
            Values_label->setFont(label_font);
            Values_label->setVisible(true);
            Values_label->move(110, 270);

            //输入文本框
            QLineEdit * KeyWords_lineedit = new QLineEdit(this);
            KeyWords_lineedit->setVisible(true);
            KeyWords_lineedit->move(210, 218);

            QLineEdit * Values_lineedit = new QLineEdit(this);
            Values_lineedit->setVisible(true);
            Values_lineedit->move(210, 268);

            //按下NEXT按钮继续输入数据
            connect(ui->NextButton, &QPushButton::clicked, this, [=](){
                QString key;
                QString value;
                //QString转char数组
                key = KeyWords_lineedit->text();
                QByteArray ba = key.toLocal8Bit();
                memcpy(keys[count], ba.data(), ba.size() + 1);

                value = Values_lineedit->text();

                QByteArray ba2 = value.toLocal8Bit();
                memcpy(values[count], ba2.data(), ba2.size() + 1);

                qDebug() << "keys[" << count << "] =" << keys[count];
                qDebug() << "values[" << count << "] =" << values[count];

                count++;
                ui->label_5->setText("数据序号：NO." + QString::number(count + 1));
                KeyWords_lineedit->setText("");
                Values_lineedit->setText("");

                if (count >= datanum)
                {
                    KeyWords_label->setVisible(false);
                    Values_label->setVisible(false);
                    KeyWords_lineedit->setVisible(false);
                    Values_lineedit->setVisible(false);
                    ui->NextButton->setVisible(false);
                    ui->label_5->setVisible(false);

                    QFont InputOver_font("KaiTi", 15, 75);
                    QLabel * InputOver_label = new QLabel("输入完毕，请前往目录界面！", this);
                    InputOver_label->setFont(InputOver_font);
                    InputOver_label->setVisible(true);
                    InputOver_label->move(40, 230);
                }
            });
        }
    });

    //进入链地址法目录
    connect(ui->menuButton, &QPushButton::clicked, this, [=](){
        ChainMenu_Scene = new ChainMenu(datanum, hashtable_length, keys, values);
        this->hide();
        ChainMenu_Scene->show();
    });
}

void ChainInput::paintEvent(QPaintEvent *)
{
    //创建画家，指定绘图设备
    QPainter painter(this);
    //创建QPixmap对象
    QPixmap pix;
    //加载图片
    pix.load(":/HashTablePicture/background4.jpg");
    //绘制背景图
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
}

ChainInput::~ChainInput()
{
    delete ui;
}
