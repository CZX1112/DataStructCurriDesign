#include "inputdata.h"
#include "ui_inputdata.h"
#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QRadioButton>
#include <QButtonGroup>
#include <QCheckBox>
#include <QDebug>
#include <QSpinBox>
#include <QPainter>

InputData::InputData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InputData)
{
    ui->setupUi(this);

    //固定窗口大小
    setFixedSize(600, 500);

    //设置窗口命名
    this->setWindowIcon(QPixmap(":/OlympicsPicture/Medal1.jfif"));
    setWindowTitle("输入信息");

    ui->menuButton->setIcon(QPixmap(":/OlympicsPicture/picture2.jfif"));

    //定义国家数、男子项目数、女子项目数
    int country_num;
    int eventnum_man;
    int eventnum_woman;

    //国家序号
    QLabel * countrynum_label = new QLabel("国家1 ", this);
    QFont countrynum_font("SimSun", 12, 75);
    countrynum_label->setFont(countrynum_font);
    countrynum_label->move(250, 100);
    countrynum_label->setVisible(false);

    //项目序号
    QLabel * eventnum_label = new QLabel("项目1 ", this);
    QFont eventnum_font("SimSun", 12, 75);
    eventnum_label->setFont(countrynum_font);
    eventnum_label->move(250, 140);
    eventnum_label->setVisible(false);

    //名次数目选择标签
    QLabel * RankingNum_label = new QLabel("项目名次数目：", this);
    RankingNum_label->setFont(countrynum_font);
    RankingNum_label->move(50, 180);
    RankingNum_label->setVisible(false);

    //名次数目选择单选框
    QRadioButton * RankingNum_rdbtn1 = new QRadioButton("前五名", this);
    QRadioButton * RankingNum_rdbtn2 = new QRadioButton("前三名", this);
    QFont button_font("SimSun", 12, 75);
    RankingNum_rdbtn1->setFont(button_font);
    RankingNum_rdbtn2->setFont(button_font);
    RankingNum_rdbtn1->setVisible(false);
    RankingNum_rdbtn2->setVisible(false);

    RankingNum_rdbtn1->move(50, 220);
    RankingNum_rdbtn2->move(50, 260);
    QButtonGroup * Ranking_Num = new QButtonGroup(this);
    Ranking_Num->addButton(RankingNum_rdbtn1, 0);
    Ranking_Num->addButton(RankingNum_rdbtn2, 1);
    RankingNum_rdbtn1->setVisible(false);
    RankingNum_rdbtn2->setVisible(false);

    //名次数目选择确认按钮
    QPushButton * RankChooseConfirm_btn = new QPushButton("确认选择", this);
    RankChooseConfirm_btn->setFont(countrynum_font);
    RankChooseConfirm_btn->move(50, 300);
    RankChooseConfirm_btn->setVisible(false);

    int country_count;
    int eventnum_count;

    //定义country_num个结点
    headnode *h;

    QLabel * InputAgain_label = new QLabel("国家数为0，请重新输入！", this);
    InputAgain_label->setVisible(false);

    //获取国家数、男子项目数、女子项目数
    connect(ui->pushButton, &QPushButton::clicked, this, [=, &h, &country_num, &eventnum_man, &eventnum_woman, &country_count, &eventnum_count](){
        h = new headnode[100];

        //初始化头节点
        for (int i = 0; i < 100; i++)
        {
            h[i].score = 0;
            h[i].mscore = 0;
            h[i].wscore = 0;
        }

        country_count = 0;
        eventnum_count = 0;

        QFont button_font("KaiTi", 25, 75);
        InputAgain_label->setFont(button_font);
        InputAgain_label->move(50, 250);

        country_num = ui->spinBox_countrynum->value();
        eventnum_man = ui->spinBox_eventnum_man->value();
        eventnum_woman = ui->spinBox_eventnum_woman->value();
        qDebug() << "country_num =" << country_num;
        qDebug() << "eventnum_man =" << eventnum_man;
        qDebug() << "eventnum_woman =" << eventnum_woman;
        if (country_num != 0)
        {
            InputAgain_label->setVisible(false);
            countrynum_label->setVisible(true);
            eventnum_label->setVisible(true);
            RankingNum_label->setVisible(true);
            RankingNum_rdbtn1->setVisible(true);
            RankingNum_rdbtn2->setVisible(true);
            RankingNum_rdbtn1->setVisible(true);
            RankingNum_rdbtn2->setVisible(true);
            RankChooseConfirm_btn->setVisible(true);
        }
        else
        {
            InputAgain_label->setVisible(true);
        }
    });

    QLabel * InputOver_label = new QLabel("输入完毕，请前往目录界面！", this);
    InputOver_label->setVisible(false);

    /*
    第一个属性是字体（微软雅黑），第二个是大小，第三个是加粗（权重是75）
    常见权重
    QFont::Light - 25 高亮
    QFont::Normal - 50 正常
    QFont::DemiBold - 63 半粗体
    QFont::Bold - 75 粗体
    QFont::Black - 87 黑体
    */

    //名次数目
    int RankNum;

    //按下名次数目选择确认按钮
    connect(RankChooseConfirm_btn, &QPushButton::clicked, this, [=, &h, &RankNum, &country_num, &eventnum_man, &eventnum_woman, &country_count, &eventnum_count](){
        if (RankingNum_rdbtn1->isChecked())
        {
            h[country_count].countrynum = country_count + 1;
            h[country_count].c[eventnum_count].itemnum = eventnum_count + 1;
            h[country_count].c[eventnum_count].top = 5;
            for (int i = 0; i < 5; i++)
            {
                h[country_count].c[eventnum_count].range[i] = 0;
                h[country_count].c[eventnum_count].mark[i] = 0;
            }


            RankNum = 5;
            qDebug() << "RankNum =" << RankNum;

            //项目名次选择标签
            QLabel * RankingChoose_label = new QLabel("项目名次选择：", this);
            RankingChoose_label->setFont(countrynum_font);
            RankingChoose_label->move(300, 180);

            //项目名次选择复选框
            QCheckBox * RankingChoose_checkbox1 = new QCheckBox("第一名", this);
            QCheckBox * RankingChoose_checkbox2 = new QCheckBox("第二名", this);
            QCheckBox * RankingChoose_checkbox3 = new QCheckBox("第三名", this);
            QCheckBox * RankingChoose_checkbox4 = new QCheckBox("第四名", this);
            QCheckBox * RankingChoose_checkbox5 = new QCheckBox("第五名", this);
            QCheckBox * RankingChoose_checkbox6 = new QCheckBox("没得奖", this);
            RankingChoose_checkbox1->setFont(button_font);
            RankingChoose_checkbox2->setFont(button_font);
            RankingChoose_checkbox3->setFont(button_font);
            RankingChoose_checkbox4->setFont(button_font);
            RankingChoose_checkbox5->setFont(button_font);
            RankingChoose_checkbox6->setFont(button_font);
            RankingChoose_checkbox1->move(300, 220);
            RankingChoose_checkbox2->move(300, 250);
            RankingChoose_checkbox3->move(300, 280);
            RankingChoose_checkbox4->move(300, 310);
            RankingChoose_checkbox5->move(300, 340);
            RankingChoose_checkbox6->move(300, 370);

            //项目名次选择确认按钮
            QPushButton * RankingChooseConfirm_btn = new QPushButton("确认选择", this);
            RankingChooseConfirm_btn->setFont(countrynum_font);
            RankingChooseConfirm_btn->move(300, 410);

            //集体显示操作
            RankingChoose_label->setVisible(true);
            RankingChoose_checkbox1->setVisible(true);
            RankingChoose_checkbox2->setVisible(true);
            RankingChoose_checkbox3->setVisible(true);
            RankingChoose_checkbox4->setVisible(true);
            RankingChoose_checkbox5->setVisible(true);
            RankingChoose_checkbox6->setVisible(true);
            RankingChooseConfirm_btn->setVisible(true);

            //按下项目名次选择确认按钮
            connect(RankingChooseConfirm_btn, &QPushButton::clicked, this, [=, &h, &eventnum_man, &country_count, &eventnum_count](){
                if (RankingChoose_checkbox1->isChecked() == true)
                {
                    h[country_count].c[eventnum_count].range[0] = 1;
                    h[country_count].c[eventnum_count].mark[0] = 7;
                }
                if (RankingChoose_checkbox2->isChecked() == true)
                {
                    h[country_count].c[eventnum_count].range[1] = 2;
                    h[country_count].c[eventnum_count].mark[1] = 5;
                }
                if (RankingChoose_checkbox3->isChecked() == true)
                {
                    h[country_count].c[eventnum_count].range[2] = 3;
                    h[country_count].c[eventnum_count].mark[2] = 3;
                }
                if (RankingChoose_checkbox4->isChecked() == true)
                {
                    h[country_count].c[eventnum_count].range[3] = 4;
                    h[country_count].c[eventnum_count].mark[3] = 2;
                }
                if (RankingChoose_checkbox5->isChecked() == true)
                {
                    h[country_count].c[eventnum_count].range[4] = 5;
                    h[country_count].c[eventnum_count].mark[4] = 1;
                }
                if (RankingChoose_checkbox6->isChecked() == true)
                {
                    for (int i = 0; i < 5; i++)
                    {
                        h[country_count].c[eventnum_count].range[i] = 0;
                        h[country_count].c[eventnum_count].mark[i] = 0;
                    }
                }

                //计算加分
                for (int i = 0; i < 5; i++)
                {
                    //加到总分
                    h[country_count].score += h[country_count].c[eventnum_count].mark[i];

                    //加给男队
                    if (eventnum_count < eventnum_man)
                        h[country_count].mscore += h[country_count].c[eventnum_count].mark[i];
                    else
                        h[country_count].wscore += h[country_count].c[eventnum_count].mark[i];
                }


                qDebug() << "测试开始：";
                qDebug() << "国家" << country_count + 1 << "项目" << eventnum_count + 1 << "获奖情况如下：";
                for (int i = 0; i < 5; i++)
                    if (h[country_count].c[eventnum_count].range[i] != 0)
                        qDebug() << "第" << i + 1 << "名，积分：" << h[country_count].c[eventnum_count].mark[i];
                qDebug() << "国家" << country_count + 1 << "目前总分：" << h[country_count].score;
                qDebug() << "国家" << country_count + 1 << "男队总分：" << h[country_count].mscore;
                qDebug() << "国家" << country_count + 1 << "女队总分：" << h[country_count].wscore;
            });

            //下一步按钮
            QPushButton * next_step = new QPushButton("NEXT", this);
            next_step->setFont(countrynum_font);
            next_step->move(this->width() - next_step->width(), 410);
            next_step->setVisible(true);

            //按下下一步按钮
            connect(next_step, &QPushButton::clicked, this, [=, &country_count, &eventnum_count, &country_num, &eventnum_man, &eventnum_woman](){
                eventnum_count++;
                qDebug() << "eventnum_count =" << eventnum_count;
                qDebug() << "country_count =" << country_count;
                next_step->setVisible(false);
                RankingChoose_label->setVisible(false);
                RankingChoose_checkbox1->setVisible(false);
                RankingChoose_checkbox2->setVisible(false);
                RankingChoose_checkbox3->setVisible(false);
                RankingChoose_checkbox4->setVisible(false);
                RankingChoose_checkbox5->setVisible(false);
                RankingChoose_checkbox6->setVisible(false);
                RankingChooseConfirm_btn->setVisible(false);
                eventnum_label->setText("项目" + QString::number(eventnum_count + 1));
                if (eventnum_count >= eventnum_man + eventnum_woman)
                {
                    if (country_count < country_num - 1)
                    {
                        country_count++;
                        countrynum_label->setText("国家" + QString::number(country_count + 1));
                        eventnum_count = 0;
                        eventnum_label->setText("项目1");
                    }
                }


                if (country_count == country_num - 1 && eventnum_count == eventnum_man + eventnum_woman)
                {
                    countrynum_label->setVisible(false);
                    eventnum_label->setVisible(false);
                    RankingNum_label->setVisible(false);
                    RankingNum_rdbtn1->setVisible(false);
                    RankingNum_rdbtn2->setVisible(false);
                    RankingNum_rdbtn1->setVisible(false);
                    RankingNum_rdbtn2->setVisible(false);
                    RankChooseConfirm_btn->setVisible(false);

                    QFont button_font("KaiTi", 20, 75);
                    QLabel * InputOver_label = new QLabel("输入完毕，请前往目录界面！", this);
                    InputOver_label->setFont(button_font);
                    InputOver_label->setVisible(true);
                    InputOver_label->move(25, 250);
                }

            });
        }

        if (RankingNum_rdbtn2->isChecked())
        {
            h[country_count].countrynum = country_count + 1;
            h[country_count].c[eventnum_count].itemnum = eventnum_count + 1;
            h[country_count].c[eventnum_count].top = 3;
            for (int i = 0; i < 5; i++)
            {
                h[country_count].c[eventnum_count].range[i] = 0;
                h[country_count].c[eventnum_count].mark[i] = 0;
            }


            RankNum = 3;
            qDebug() << "RankNum =" << RankNum;

            //项目名次选择标签
            QLabel * RankingChoose_label = new QLabel("项目名次选择：", this);
            RankingChoose_label->setFont(countrynum_font);
            RankingChoose_label->move(300, 180);

            //项目名次选择复选框
            QCheckBox * RankingChoose_checkbox1 = new QCheckBox("第一名", this);
            QCheckBox * RankingChoose_checkbox2 = new QCheckBox("第二名", this);
            QCheckBox * RankingChoose_checkbox3 = new QCheckBox("第三名", this);
            QCheckBox * RankingChoose_checkbox4 = new QCheckBox("没得奖", this);
            RankingChoose_checkbox1->setFont(button_font);
            RankingChoose_checkbox2->setFont(button_font);
            RankingChoose_checkbox3->setFont(button_font);
            RankingChoose_checkbox4->setFont(button_font);
            RankingChoose_checkbox1->move(300, 220);
            RankingChoose_checkbox2->move(300, 260);
            RankingChoose_checkbox3->move(300, 300);
            RankingChoose_checkbox4->move(300, 340);

            //项目名次选择确认按钮
            QPushButton * RankingChooseConfirm_btn = new QPushButton("确认选择", this);
            RankingChooseConfirm_btn->setFont(countrynum_font);
            RankingChooseConfirm_btn->move(300, 380);

            //按下项目名次选择确认按钮
            connect(RankingChooseConfirm_btn, &QPushButton::clicked, this, [=, &h, &eventnum_man, &country_count, &eventnum_count](){
                if (RankingChoose_checkbox1->isChecked() == true)
                {
                    h[country_count].c[eventnum_count].range[0] = 1;
                    h[country_count].c[eventnum_count].mark[0] = 5;
                }
                if (RankingChoose_checkbox2->isChecked() == true)
                {
                    h[country_count].c[eventnum_count].range[1] = 2;
                    h[country_count].c[eventnum_count].mark[1] = 3;
                }
                if (RankingChoose_checkbox3->isChecked() == true)
                {
                    h[country_count].c[eventnum_count].range[2] = 3;
                    h[country_count].c[eventnum_count].mark[2] = 2;
                }
                if (RankingChoose_checkbox4->isChecked() == true)
                {
                    for (int i = 0; i < 5; i++)
                    {
                        h[country_count].c[eventnum_count].range[i] = 0;
                        h[country_count].c[eventnum_count].mark[i] = 0;
                    }
                }

                //计算加分
                for (int i = 0; i < 5; i++)
                {
                    //加到总分
                    h[country_count].score += h[country_count].c[eventnum_count].mark[i];

                    //加给男队
                    if (eventnum_count < eventnum_man)
                        h[country_count].mscore += h[country_count].c[eventnum_count].mark[i];
                    else
                        h[country_count].wscore += h[country_count].c[eventnum_count].mark[i];
                }


                qDebug() << "测试开始：";
                qDebug() << "国家" << country_count + 1 << "项目" << eventnum_count + 1 << "获奖情况如下：";
                for (int i = 0; i < 5; i++)
                    if (h[country_count].c[eventnum_count].range[i] != 0)
                        qDebug() << "第" << i + 1 << "名，积分：" << h[country_count].c[eventnum_count].mark[i];
                qDebug() << "国家" << country_count + 1 << "目前总分：" << h[country_count].score;
                qDebug() << "国家" << country_count + 1 << "男队总分：" << h[country_count].mscore;
                qDebug() << "国家" << country_count + 1 << "女队总分：" << h[country_count].wscore;
            });


            //集体显示操作
            RankingChoose_label->setVisible(true);
            RankingChoose_checkbox1->setVisible(true);
            RankingChoose_checkbox2->setVisible(true);
            RankingChoose_checkbox3->setVisible(true);
            RankingChoose_checkbox4->setVisible(true);
            RankingChooseConfirm_btn->setVisible(true);

            //下一步按钮
            QPushButton * next_step = new QPushButton("NEXT", this);
            next_step->setFont(countrynum_font);
            next_step->move(this->width() - next_step->width(), 410);
            next_step->setVisible(true);

            //按下下一步按钮
            connect(next_step, &QPushButton::clicked, this, [=, &country_count, &eventnum_count, &country_num, &eventnum_man, &eventnum_woman](){
                eventnum_count++;
                qDebug() << "eventnum_count =" << eventnum_count;
                qDebug() << "country_count =" << country_count;
                next_step->setVisible(false);
                RankingChoose_label->setVisible(false);
                RankingChoose_checkbox1->setVisible(false);
                RankingChoose_checkbox2->setVisible(false);
                RankingChoose_checkbox3->setVisible(false);
                RankingChoose_checkbox4->setVisible(false);
                RankingChooseConfirm_btn->setVisible(false);
                eventnum_label->setText("项目" + QString::number(eventnum_count + 1));

                if (eventnum_count >= eventnum_man + eventnum_woman)
                {
                    if (country_count < country_num - 1)
                    {
                        country_count++;
                        countrynum_label->setText("国家" + QString::number(country_count + 1));
                        eventnum_count = 0;
                        eventnum_label->setText("项目1");
                    }
                }

                if (country_count == country_num - 1 && eventnum_count == eventnum_man + eventnum_woman)
                {
                    countrynum_label->setVisible(false);
                    eventnum_label->setVisible(false);
                    RankingNum_label->setVisible(false);
                    RankingNum_rdbtn1->setVisible(false);
                    RankingNum_rdbtn2->setVisible(false);
                    RankingNum_rdbtn1->setVisible(false);
                    RankingNum_rdbtn2->setVisible(false);
                    RankChooseConfirm_btn->setVisible(false);

                    QFont button_font("KaiTi", 25, 75);
                    InputOver_label->setFont(button_font);
                    InputOver_label->setVisible(true);
                    InputOver_label->move(25, 250);
                }
            });
        }

    });


    //跳转目录界面
    connect(ui->menuButton, &QPushButton::clicked, this, [=, &h, &country_num](){
        //实例化目录场景
        menuscene = new Menu(h, country_num);
        InputOver_label->setVisible(false);
        this->hide();
        menuscene->show();

        //返回输入界面
        connect(menuscene, &Menu::SceneBack, this, [=](){
            menuscene->hide();
            this->show();
        });
    });
}


void InputData::paintEvent(QPaintEvent *)
{
    //创建画家，指定绘图设备
    QPainter painter(this);
    //创建QPixmap对象
    QPixmap pix;
    //加载图片
    pix.load(":/OlympicsPicture/background6.jfif");
    //绘制背景图
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
}


InputData::~InputData()
{
    delete ui;
}
