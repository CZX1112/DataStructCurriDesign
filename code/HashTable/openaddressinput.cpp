#include "openaddressinput.h"
#include "ui_openaddressinput.h"
#include <QPushButton>
#include <QSpinBox>
#include <QDebug>
#include <QString>
#include <QLabel>
#include <QFont>
#include <QLineEdit>

//定义数据量、哈希表长度
int datanum_open;
int hashtable_length_open;
char keys_open[100][100];
char values_open[100][100];

int count_open;

OpenAddressInput::OpenAddressInput(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OpenAddressInput)
{
    ui->setupUi(this);

    //设置窗口命名
    setWindowTitle("开放定址法");

    //初始化界面
    ui->label_5->setVisible(false);
    ui->label_5->setText("数据序号：NO." + QString::number(1));
    ui->NextButton->setVisible(false);

    //获取数据量、哈希表长度
    connect(ui->pushButton, &QPushButton::clicked, this, [=](){
        ui->NextButton->setVisible(true);
        datanum_open = ui->spinBox_datanum->value();
        hashtable_length_open = ui->spinBox_hashtable_length->value();
        ui->label_5->setVisible(true);

        count_open = 0;

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
            memcpy(keys_open[count_open], ba.data(), ba.size() + 1);

            value = Values_lineedit->text();

            QByteArray ba2 = value.toLocal8Bit();
            memcpy(values_open[count_open], ba2.data(), ba2.size() + 1);

            qDebug() << "keys[" << count_open << "] =" << keys_open[count_open];
            qDebug() << "values[" << count_open << "] =" << values_open[count_open];

            count_open++;
            ui->label_5->setText("数据序号：NO." + QString::number(count_open + 1));
            KeyWords_lineedit->setText("");
            Values_lineedit->setText("");

            if (count_open >= datanum_open)
            {
                KeyWords_label->setVisible(false);
                Values_label->setVisible(false);
                KeyWords_lineedit->setVisible(false);
                Values_lineedit->setVisible(false);
                ui->NextButton->setVisible(false);
                ui->label_5->setVisible(false);

                QFont InputOver_font("KaiTi", 20, 75);
                QLabel * InputOver_label = new QLabel("输入完毕，请前往目录界面！", this);
                InputOver_label->setFont(InputOver_font);
                InputOver_label->setVisible(true);
                InputOver_label->move(40, 230);
            }
        });
    });

    //进入开放定址法目录
    connect(ui->menuButton, &QPushButton::clicked, this, [=](){
        OpenAddressMenu_Scene = new OpenAddressMenu(datanum_open, hashtable_length_open, keys_open, values_open);
        this->hide();
        OpenAddressMenu_Scene->show();
    });
}

OpenAddressInput::~OpenAddressInput()
{
    delete ui;
}
