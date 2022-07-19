#include "output_search.h"
#include "ui_output_search.h"
#include <QDebug>
#include <QSpinBox>
#include <QLabel>
#include <QString>
#include <QPainter>

int country_count;

OutPut_Search::OutPut_Search(headnode *h, int &country_num, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OutPut_Search)
{
    ui->setupUi(this);

    //设置窗口命名
    this->setWindowIcon(QPixmap(":/OlympicsPicture/FiveRings.jfif"));
    setWindowTitle("输出查询信息");

    //返回输出界面按钮
    QPushButton * returnoutput_btn = new QPushButton("返回输出", this);
    returnoutput_btn->move(this->width() / 2 - returnoutput_btn->width(), this->height() - returnoutput_btn->height());
    returnoutput_btn->setVisible(false);

    //返回查询界面按钮
    QPushButton * returnsearch_btn = new QPushButton("返回查询", this);
    returnsearch_btn->move(this->width() - returnsearch_btn->width(), this->height() - returnsearch_btn->height());
    returnsearch_btn->setVisible(false);

    //字体设置
    QFont returnbtn_font("SimSun", 12);
    returnsearch_btn->setFont(returnbtn_font);
    returnoutput_btn->setFont(returnbtn_font);


    //按国家编号输出信息
    connect(ui->outputButton1, &QPushButton::clicked, this, [=, &country_num](){

        country_count = 0;

        returnoutput_btn->setVisible(true);
        ui->outputButton1->setVisible(false);
        ui->outputButton2->setVisible(false);
        ui->outputButton3->setVisible(false);
        ui->outputButton4->setVisible(false);

        //标签
        QLabel * OutputTips_label = new QLabel("按国家编号输出：", this);
        OutputTips_label->setVisible(true);
        OutputTips_label->move(110, 110);
        OutputTips_label->resize(200, 60);

        //字体设置
        QFont LabelFont("SimSun", 15, 75);
        OutputTips_label->setFont(LabelFont);

        //需要显示的标签
        QLabel * CountryNo_label = new QLabel("国家编号：    ", this);
        QLabel * CountryTotalScore_label = new QLabel("国家总分：    ", this);
        QLabel * CountryTotalScoreMan_label = new QLabel("男团总分：    ", this);
        QLabel * CountryTotalScoreWoman_label = new QLabel("女团总分：    ", this);
        QLabel * InputOver_label = new QLabel("输出完毕，请返回！", this);

        QFont LabelFont2("SimSun", 15);
        QFont LabelFont3("KaiTi", 23, 75);

        CountryNo_label->setFont(LabelFont2);
        CountryTotalScore_label->setFont(LabelFont2);
        CountryTotalScoreMan_label->setFont(LabelFont2);
        CountryTotalScoreWoman_label->setFont(LabelFont2);
        InputOver_label->setFont(LabelFont3);

        CountryNo_label->move(110, 190);
        CountryTotalScore_label->move(110, 240);
        CountryTotalScoreMan_label->move(110, 290);
        CountryTotalScoreWoman_label->move(110, 340);
        InputOver_label->move(50, 250);

        CountryNo_label->setVisible(true);
        CountryTotalScore_label->setVisible(true);
        CountryTotalScoreMan_label->setVisible(true);
        CountryTotalScoreWoman_label->setVisible(true);

        CountryNo_label->setText("国家编号：" + QString::number(h[0].countrynum));
        CountryTotalScore_label->setText("国家总分：" + QString::number(h[0].score));
        CountryTotalScoreMan_label->setText("男团总分：" + QString::number(h[0].mscore));
        CountryTotalScoreWoman_label->setText("女团总分：" + QString::number(h[0].wscore));

        //下一步按钮
        QPushButton * next_btn = new QPushButton("NEXT", this);
        next_btn->move(this->width() / 2 - returnsearch_btn->width(), this->height() - returnsearch_btn->height() - next_btn->height());
        next_btn->setVisible(true);
        next_btn->setFont(returnbtn_font);

        connect(next_btn, &QPushButton::clicked, this, [=, &country_num](){
            country_count++;
            if (country_count < country_num)
            {
                CountryNo_label->setText("国家编号：" + QString::number(h[country_count].countrynum));
                CountryTotalScore_label->setText("国家总分：" + QString::number(h[country_count].score));
                CountryTotalScoreMan_label->setText("男团总分：" + QString::number(h[country_count].mscore));
                CountryTotalScoreWoman_label->setText("女团总分：" + QString::number(h[country_count].wscore));
            }
            else
            {
                CountryNo_label->setVisible(false);
                CountryTotalScore_label->setVisible(false);
                CountryTotalScoreMan_label->setVisible(false);
                CountryTotalScoreWoman_label->setVisible(false);
                InputOver_label->setVisible(true);
            }
        });


        connect(returnoutput_btn, &QPushButton::clicked, this, [=](){
            returnoutput_btn->setVisible(false);
            ui->outputButton1->setVisible(true);
            ui->outputButton2->setVisible(true);
            ui->outputButton3->setVisible(true);
            ui->outputButton4->setVisible(true);

            OutputTips_label->setVisible(false);
            CountryNo_label->setVisible(false);
            CountryTotalScore_label->setVisible(false);
            CountryTotalScoreMan_label->setVisible(false);
            CountryTotalScoreWoman_label->setVisible(false);
            InputOver_label->setVisible(false);
            next_btn->setVisible(false);
        });
    });

    //按国家总分输出信息
    connect(ui->outputButton2, &QPushButton::clicked, this, [=, &country_num](){

        country_count = 0;

        returnoutput_btn->setVisible(true);
        ui->outputButton1->setVisible(false);
        ui->outputButton2->setVisible(false);
        ui->outputButton3->setVisible(false);
        ui->outputButton4->setVisible(false);

        //标签
        QLabel * OutputTips_label = new QLabel("按国家总分输出：", this);
        OutputTips_label->setVisible(true);
        OutputTips_label->move(110, 110);
        OutputTips_label->resize(200, 60);

        //字体设置
        QFont LabelFont("SimSun", 12, 75);
        OutputTips_label->setFont(LabelFont);

        //需要显示的标签
        QLabel * CountryNo_label = new QLabel("国家编号：    ", this);
        QLabel * CountryTotalScore_label = new QLabel("国家总分：    ", this);
        QLabel * CountryTotalScoreMan_label = new QLabel("男团总分：    ", this);
        QLabel * CountryTotalScoreWoman_label = new QLabel("女团总分：    ", this);
        QLabel * InputOver_label = new QLabel("输出完毕，请返回！", this);

        QFont LabelFont2("SimSun", 15);
        QFont LabelFont3("KaiTi", 23, 75);

        CountryNo_label->setFont(LabelFont2);
        CountryTotalScore_label->setFont(LabelFont2);
        CountryTotalScoreMan_label->setFont(LabelFont2);
        CountryTotalScoreWoman_label->setFont(LabelFont2);
        InputOver_label->setFont(LabelFont3);

        CountryNo_label->move(110, 190);
        CountryTotalScore_label->move(110, 240);
        CountryTotalScoreMan_label->move(110, 290);
        CountryTotalScoreWoman_label->move(110, 340);
        InputOver_label->move(50, 250);

        CountryNo_label->setVisible(true);
        CountryTotalScore_label->setVisible(true);
        CountryTotalScoreMan_label->setVisible(true);
        CountryTotalScoreWoman_label->setVisible(true);

        //下一步按钮
        QPushButton * next_btn = new QPushButton("NEXT", this);
        next_btn->move(this->width() / 2 - returnsearch_btn->width(), this->height() - returnsearch_btn->height() - next_btn->height());
        next_btn->setVisible(true);
        next_btn->setFont(returnbtn_font);


        int * remember = new int[country_num];
        int k;
        //用冒泡排序方法，用辅助数组记住头结点下标
        for (int i = 0; i < country_num; i++)
            remember[i] = i;
        for (int i = 0; i < country_num; i++)
        {
            for (int j = i + 1; j < country_num; j++)
                if (h[remember[i]].score < h[j].score)
                {
                    k = remember[i];
                    remember[i] = remember[j], remember[j] = k;
                }
        }

        CountryNo_label->setText("国家编号：" + QString::number(h[remember[0]].countrynum));
        CountryTotalScore_label->setText("国家总分：" + QString::number(h[remember[0]].score));
        CountryTotalScoreMan_label->setText("男团总分：" + QString::number(h[remember[0]].mscore));
        CountryTotalScoreWoman_label->setText("女团总分：" + QString::number(h[remember[0]].wscore));

        connect(next_btn, &QPushButton::clicked, this, [=, &country_num](){
            country_count++;
            if (country_count < country_num)
            {
                CountryNo_label->setText("国家编号：" + QString::number(h[remember[country_count]].countrynum));
                CountryTotalScore_label->setText("国家总分：" + QString::number(h[remember[country_count]].score));
                CountryTotalScoreMan_label->setText("男团总分：" + QString::number(h[remember[country_count]].mscore));
                CountryTotalScoreWoman_label->setText("女团总分：" + QString::number(h[remember[country_count]].wscore));
            }
            else
            {
                CountryNo_label->setVisible(false);
                CountryTotalScore_label->setVisible(false);
                CountryTotalScoreMan_label->setVisible(false);
                CountryTotalScoreWoman_label->setVisible(false);
                InputOver_label->setVisible(true);
            }
        });


        connect(returnoutput_btn, &QPushButton::clicked, this, [=](){
            returnoutput_btn->setVisible(false);
            ui->outputButton1->setVisible(true);
            ui->outputButton2->setVisible(true);
            ui->outputButton3->setVisible(true);
            ui->outputButton4->setVisible(true);

            OutputTips_label->setVisible(false);
            CountryNo_label->setVisible(false);
            CountryTotalScore_label->setVisible(false);
            CountryTotalScoreMan_label->setVisible(false);
            CountryTotalScoreWoman_label->setVisible(false);
            InputOver_label->setVisible(false);
            next_btn->setVisible(false);
        });
    });

    //按男团总分输出信息
    connect(ui->outputButton3, &QPushButton::clicked, this, [=](){

        country_count = 0;

        returnoutput_btn->setVisible(true);
        ui->outputButton1->setVisible(false);
        ui->outputButton2->setVisible(false);
        ui->outputButton3->setVisible(false);
        ui->outputButton4->setVisible(false);

        //标签
        QLabel * OutputTips_label = new QLabel("按男团总分输出：", this);
        OutputTips_label->setVisible(true);
        OutputTips_label->move(110, 110);
        OutputTips_label->resize(200, 60);

        //字体设置
        QFont LabelFont("SimSun", 12, 75);
        OutputTips_label->setFont(LabelFont);

        //需要显示的标签
        QLabel * CountryNo_label = new QLabel("国家编号：    ", this);
        QLabel * CountryTotalScore_label = new QLabel("国家总分：    ", this);
        QLabel * CountryTotalScoreMan_label = new QLabel("男团总分：    ", this);
        QLabel * CountryTotalScoreWoman_label = new QLabel("女团总分：    ", this);
        QLabel * InputOver_label = new QLabel("输出完毕，请返回！", this);

        QFont LabelFont2("SimSun", 15);
        QFont LabelFont3("KaiTi", 23, 75);

        CountryNo_label->setFont(LabelFont2);
        CountryTotalScore_label->setFont(LabelFont2);
        CountryTotalScoreMan_label->setFont(LabelFont2);
        CountryTotalScoreWoman_label->setFont(LabelFont2);
        InputOver_label->setFont(LabelFont3);

        CountryNo_label->move(110, 190);
        CountryTotalScore_label->move(110, 240);
        CountryTotalScoreMan_label->move(110, 290);
        CountryTotalScoreWoman_label->move(110, 340);
        InputOver_label->move(50, 250);

        CountryNo_label->setVisible(true);
        CountryTotalScore_label->setVisible(true);
        CountryTotalScoreMan_label->setVisible(true);
        CountryTotalScoreWoman_label->setVisible(true);

        //下一步按钮
        QPushButton * next_btn = new QPushButton("NEXT", this);
        next_btn->move(this->width() / 2 - returnsearch_btn->width(), this->height() - returnsearch_btn->height() - next_btn->height());
        next_btn->setVisible(true);
        next_btn->setFont(returnbtn_font);


        int * remember = new int[country_num];
        int k;
        //用冒泡排序方法，用辅助数组记住头结点下标
        for (int i = 0; i < country_num; i++)
            remember[i] = i;
        for (int i = 0; i < country_num; i++)
        {
            for (int j = i + 1; j < country_num; j++)
                if (h[remember[i]].mscore < h[j].mscore)
                {
                    k = remember[i];
                    remember[i] = remember[j], remember[j] = k;
                }
        }

        CountryNo_label->setText("国家编号：" + QString::number(h[remember[0]].countrynum));
        CountryTotalScore_label->setText("国家总分：" + QString::number(h[remember[0]].score));
        CountryTotalScoreMan_label->setText("男团总分：" + QString::number(h[remember[0]].mscore));
        CountryTotalScoreWoman_label->setText("女团总分：" + QString::number(h[remember[0]].wscore));

        connect(next_btn, &QPushButton::clicked, this, [=, &country_num](){
            country_count++;
            if (country_count < country_num)
            {
                CountryNo_label->setText("国家编号：" + QString::number(h[remember[country_count]].countrynum));
                CountryTotalScore_label->setText("国家总分：" + QString::number(h[remember[country_count]].score));
                CountryTotalScoreMan_label->setText("男团总分：" + QString::number(h[remember[country_count]].mscore));
                CountryTotalScoreWoman_label->setText("女团总分：" + QString::number(h[remember[country_count]].wscore));
            }
            else
            {
                CountryNo_label->setVisible(false);
                CountryTotalScore_label->setVisible(false);
                CountryTotalScoreMan_label->setVisible(false);
                CountryTotalScoreWoman_label->setVisible(false);
                InputOver_label->setVisible(true);
            }
        });

        connect(returnoutput_btn, &QPushButton::clicked, this, [=](){
            returnoutput_btn->setVisible(false);
            ui->outputButton1->setVisible(true);
            ui->outputButton2->setVisible(true);
            ui->outputButton3->setVisible(true);
            ui->outputButton4->setVisible(true);

            OutputTips_label->setVisible(false);
            CountryNo_label->setVisible(false);
            CountryTotalScore_label->setVisible(false);
            CountryTotalScoreMan_label->setVisible(false);
            CountryTotalScoreWoman_label->setVisible(false);
            InputOver_label->setVisible(false);
            next_btn->setVisible(false);
        });
    });

    //按女团总分输出信息
    connect(ui->outputButton4, &QPushButton::clicked, this, [=](){

        country_count = 0;

        returnoutput_btn->setVisible(true);
        ui->outputButton1->setVisible(false);
        ui->outputButton2->setVisible(false);
        ui->outputButton3->setVisible(false);
        ui->outputButton4->setVisible(false);

        //标签
        QLabel * OutputTips_label = new QLabel("按女团总分输出：", this);
        OutputTips_label->setVisible(true);
        OutputTips_label->move(110, 110);
        OutputTips_label->resize(200, 60);

        //字体设置
        QFont LabelFont("SimSun", 12, 75);
        OutputTips_label->setFont(LabelFont);

        //需要显示的标签
        QLabel * CountryNo_label = new QLabel("国家编号：    ", this);
        QLabel * CountryTotalScore_label = new QLabel("国家总分：    ", this);
        QLabel * CountryTotalScoreMan_label = new QLabel("男团总分：    ", this);
        QLabel * CountryTotalScoreWoman_label = new QLabel("女团总分：    ", this);
        QLabel * InputOver_label = new QLabel("输出完毕，请返回！", this);

        QFont LabelFont2("SimSun", 15);
        QFont LabelFont3("KaiTi", 23, 75);

        CountryNo_label->setFont(LabelFont2);
        CountryTotalScore_label->setFont(LabelFont2);
        CountryTotalScoreMan_label->setFont(LabelFont2);
        CountryTotalScoreWoman_label->setFont(LabelFont2);
        InputOver_label->setFont(LabelFont3);

        CountryNo_label->move(110, 190);
        CountryTotalScore_label->move(110, 240);
        CountryTotalScoreMan_label->move(110, 290);
        CountryTotalScoreWoman_label->move(110, 340);
        InputOver_label->move(50, 250);

        CountryNo_label->setVisible(true);
        CountryTotalScore_label->setVisible(true);
        CountryTotalScoreMan_label->setVisible(true);
        CountryTotalScoreWoman_label->setVisible(true);

        //下一步按钮
        QPushButton * next_btn = new QPushButton("NEXT", this);
        next_btn->move(this->width() / 2 - returnsearch_btn->width(), this->height() - returnsearch_btn->height() - next_btn->height());
        next_btn->setVisible(true);
        next_btn->setFont(returnbtn_font);


        int * remember = new int[country_num];
        int k;
        //用冒泡排序方法，用辅助数组记住头结点下标
        for (int i = 0; i < country_num; i++)
            remember[i] = i;
        for (int i = 0; i < country_num; i++)
        {
            for (int j = i + 1; j < country_num; j++)
                if (h[remember[i]].wscore < h[j].wscore)
                {
                    k = remember[i];
                    remember[i] = remember[j], remember[j] = k;
                }
        }

        CountryNo_label->setText("国家编号：" + QString::number(h[remember[0]].countrynum));
        CountryTotalScore_label->setText("国家总分：" + QString::number(h[remember[0]].score));
        CountryTotalScoreMan_label->setText("男团总分：" + QString::number(h[remember[0]].mscore));
        CountryTotalScoreWoman_label->setText("女团总分：" + QString::number(h[remember[0]].wscore));

        connect(next_btn, &QPushButton::clicked, this, [=, &country_num](){
            country_count++;
            if (country_count < country_num)
            {
                CountryNo_label->setText("国家编号：" + QString::number(h[remember[country_count]].countrynum));
                CountryTotalScore_label->setText("国家总分：" + QString::number(h[remember[country_count]].score));
                CountryTotalScoreMan_label->setText("男团总分：" + QString::number(h[remember[country_count]].mscore));
                CountryTotalScoreWoman_label->setText("女团总分：" + QString::number(h[remember[country_count]].wscore));
            }
            else
            {
                CountryNo_label->setVisible(false);
                CountryTotalScore_label->setVisible(false);
                CountryTotalScoreMan_label->setVisible(false);
                CountryTotalScoreWoman_label->setVisible(false);
                InputOver_label->setVisible(true);
            }
        });

        connect(returnoutput_btn, &QPushButton::clicked, this, [=](){
            returnoutput_btn->setVisible(false);
            ui->outputButton1->setVisible(true);
            ui->outputButton2->setVisible(true);
            ui->outputButton3->setVisible(true);
            ui->outputButton4->setVisible(true);

            OutputTips_label->setVisible(false);
            CountryNo_label->setVisible(false);
            CountryTotalScore_label->setVisible(false);
            CountryTotalScoreMan_label->setVisible(false);
            CountryTotalScoreWoman_label->setVisible(false);
            InputOver_label->setVisible(false);
            next_btn->setVisible(false);
        });
    });

    //按国家编号查询某个项目情况
    connect(ui->searchButton1, &QPushButton::clicked, this, [=](){
        ui->searchButton1->setVisible(false);
        ui->searchButton2->setVisible(false);
        returnsearch_btn->setVisible(true);

        QSpinBox * SpinBox_country = new QSpinBox(this);
        QSpinBox * SpinBox_event = new QSpinBox(this);
        SpinBox_country->setVisible(true);
        SpinBox_event->setVisible(true);
        SpinBox_country->move(600, 128);
        SpinBox_event->move(600, 158);

        //标签
        QLabel * countrynum_label = new QLabel("国家编号：", this);
        QLabel * eventnum_label = new QLabel("项目编号：", this);
        countrynum_label->setVisible(true);
        eventnum_label->setVisible(true);
        countrynum_label->resize(91, 21);
        eventnum_label->resize(91, 21);
        countrynum_label->move(500, 130);
        eventnum_label->move(500, 160);

        //字体设置
        QFont label_font("KaiTi", 11, 75);
        countrynum_label->setFont(label_font);
        eventnum_label->setFont(label_font);

        //输入完毕按钮
        QPushButton * InputOver_btn = new QPushButton("输入完毕", this);
        QFont InputOver_Font("SimSun", 10);
        InputOver_btn->setFont(InputOver_Font);
        InputOver_btn->setVisible(true);
        InputOver_btn->move(665, 155);

        //需要显示的标签
        QFont label_font2("SimSun", 11);
        QLabel * country_NO_label = new QLabel("国家编号：  ", this);
        QLabel * event_NO_label = new QLabel("项目编号：  ", this);
        QLabel * event_TopN_label = new QLabel("项目所取名次：  ", this);
        QLabel * OutputTips = new QLabel("该国家成绩如下：", this);

        QLabel * Rank_label = new QLabel[5];
        for (int i = 0; i < 5; i++)
        {
            Rank_label[i].setText("所得名次：  ");
            Rank_label[i].setParent(this);
            Rank_label[i].setFont(label_font2);
            Rank_label[i].move(500, 280 + 30 * i);
        }

        QLabel * Score_label = new QLabel[5];
        for (int i = 0; i < 5; i++)
        {
            Score_label[i].setText("所得积分：  ");
            Score_label[i].setParent(this);
            Score_label[i].setFont(label_font2);
            Score_label[i].move(630, 280 + 30 * i);
        }

        country_NO_label->setFont(label_font2);
        event_NO_label->setFont(label_font2);
        event_TopN_label->setFont(label_font2);
        OutputTips->setFont(label_font2);
        country_NO_label->move(500, 190);
        event_NO_label->move(630, 190);
        event_TopN_label->move(500, 220);
        OutputTips->move(500, 250);


        //按下输入完毕按钮
        connect(InputOver_btn, &QPushButton::clicked, this, [=](){
            for (int i = 0; i < 5; i++)
            {
                Rank_label[i].setVisible(false);
                Score_label[i].setVisible(false);
            }

            int country_NO;
            int event_NO;
            country_NO = SpinBox_country->value();
            event_NO = SpinBox_event->value();
//            qDebug() << "这个项目取前" << h[0].c[event_NO - 1].top << "名";
//            for (int k = 0; k < 5; k++)
//                if (h[country_NO - 1].c[event_NO - 1].range[k] != 0)
//                    qDebug() << "名次：" << h[country_NO - 1].c[event_NO - 1].range[k];

            country_NO_label->setText("国家编号：" + QString::number(country_NO));
            event_NO_label->setText("项目编号：" + QString::number(event_NO));
            event_TopN_label->setText("项目所取名次：" + QString::number(h[0].c[event_NO - 1].top));

            country_NO_label->setVisible(true);
            event_NO_label->setVisible(true);
            event_TopN_label->setVisible(true);
            OutputTips->setVisible(true);
            int j = 0;

            for (int i = 0; i < 5; i++)
            {
                if (h[country_NO - 1].c[event_NO - 1].range[i] != 0)
                {
                    Rank_label[j].setVisible(true);
                    Score_label[j].setVisible(true);
                    Rank_label[j].setText("所得名次：" + QString::number(h[country_NO - 1].c[event_NO - 1].range[i]));
                    Score_label[j].setText("所得积分：" + QString::number(h[country_NO - 1].c[event_NO - 1].mark[i]));
                    j++;
                }
            }

        });

        connect(returnsearch_btn, &QPushButton::clicked, this, [=](){
            ui->searchButton1->setVisible(true);
            ui->searchButton2->setVisible(true);
            returnsearch_btn->setVisible(false);
            countrynum_label->setVisible(false);
            eventnum_label->setVisible(false);
            InputOver_btn->setVisible(false);
            SpinBox_country->setVisible(false);
            SpinBox_event->setVisible(false);
            country_NO_label->setVisible(false);
            event_NO_label->setVisible(false);
            event_TopN_label->setVisible(false);
            OutputTips->setVisible(false);
            for (int i = 0; i < 5; i++)
            {
                Rank_label[i].setVisible(false);
                Score_label[i].setVisible(false);
            }
        });

    });

    //按项目编号查询
    connect(ui->searchButton2, &QPushButton::clicked, this, [=, &country_num](){
        ui->searchButton1->setVisible(false);
        ui->searchButton2->setVisible(false);
        returnsearch_btn->setVisible(true);

        QSpinBox * SpinBox_event = new QSpinBox(this);
        SpinBox_event->setVisible(true);
        SpinBox_event->move(600, 128);

        //标签
        QLabel * eventnum_label = new QLabel("项目编号：", this);
        eventnum_label->setVisible(true);
        eventnum_label->resize(91, 21);
        eventnum_label->move(500, 130);

        //字体设置
        QFont label_font("KaiTi", 11, 75);
        eventnum_label->setFont(label_font);

        //输入完毕按钮
        QPushButton * InputOver_btn = new QPushButton("输入完毕", this);
        QFont InputOver_Font("SimSun", 10);
        InputOver_btn->setFont(InputOver_Font);
        InputOver_btn->setVisible(true);
        InputOver_btn->move(665, 125);

        //需要显示的标签
        QFont label_font2("SimSun", 11);
        QLabel * event_NO_label = new QLabel("项目编号：  ", this);
        QLabel * event_TopN_label = new QLabel("项目所取名次：  ", this);
        QLabel * OutputTips = new QLabel("取得名次的国家如下：", this);

        QLabel * Country_label = new QLabel[5];
        for (int i = 0; i < 5; i++)
        {
            Country_label[i].setText("国家序号：  ");
            Country_label[i].setParent(this);
            Country_label[i].setFont(label_font2);
            Country_label[i].move(500, 250 + 30 * i);
        }

        QLabel * Rank_label = new QLabel[5];
        for (int i = 0; i < 5; i++)
        {
            Rank_label[i].setText("所得名次：  ");
            Rank_label[i].setParent(this);
            Rank_label[i].setFont(label_font2);
            Rank_label[i].move(630, 250 + 30 * i);
        }

        event_NO_label->setFont(label_font2);
        event_TopN_label->setFont(label_font2);
        OutputTips->setFont(label_font2);
        event_NO_label->move(500, 160);
        event_TopN_label->move(500, 190);
        OutputTips->move(500, 220);

        //按下输入完毕按钮
        connect(InputOver_btn, &QPushButton::clicked, this, [=, &country_num](){
            for (int i = 0; i < 5; i++)
            {
                Country_label[i].setVisible(false);
                Rank_label[i].setVisible(false);
            }

            int event_NO;
            event_NO = SpinBox_event->value();

            event_NO_label->setText("项目编号：" + QString::number(event_NO));
            event_TopN_label->setText("项目所取名次：" + QString::number(h[0].c[event_NO - 1].top));

            event_NO_label->setVisible(true);
            event_TopN_label->setVisible(true);
            OutputTips->setVisible(true);

            for (int i = 0; i < 5; i++)
            {
                //取前三名
                if(h[0].c[event_NO - 1].top == 3 && i < 3)
                {
                    Country_label[i].setVisible(true);
                    Rank_label[i].setVisible(true);
                }

                //取前五名
                if (h[0].c[event_NO - 1].top == 5)
                {
                    Country_label[i].setVisible(true);
                    Rank_label[i].setVisible(true);
                }
            }

//            //方案一：按国家顺序输出
//            for (int i = 0; i < country_num; i++)
//            {
//                for (int j = 0; j < 5; j++)
//                {
//                    if (h[i].c[event_NO - 1].range[j] != 0)
//                    {
//                        qDebug() << "国家编号：" << h[i].countrynum << "，名次" << h[i].c[event_NO - 1].range[j];
//                        Country_label[count].setText("国家编号：" + QString::number(h[i].countrynum));
//                        Rank_label[count].setText("所得名次：" + QString::number(h[i].c[event_NO - 1].range[j]));
//                        count++;
//                    }
//                }
//            }

            //方案二：按名次顺序输出
            for (int i = 0; i < 5; i++)
            {
                Country_label[i].move(630, 250 + 30 * i);
                Rank_label[i].move(500, 250 + 30 * i);
            }

            for (int i = 0; i < 5; i++)
                Rank_label[i].setText("所得名次：" + QString::number(i + 1));
            for (int i = 0; i < country_num; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (h[i].c[event_NO - 1].range[j] != 0)
                    {
                        Country_label[h[i].c[event_NO - 1].range[j] - 1].setText("国家编号：" + QString::number(h[i].countrynum));
                    }
                }
            }

        });

        connect(returnsearch_btn, &QPushButton::clicked, this, [=](){
            ui->searchButton1->setVisible(true);
            ui->searchButton2->setVisible(true);
            returnsearch_btn->setVisible(false);

            SpinBox_event->setVisible(false);
            eventnum_label->setVisible(false);
            InputOver_btn->setVisible(false);

            event_NO_label->setVisible(false);
            event_TopN_label->setVisible(false);
            OutputTips->setVisible(false);

            for (int i = 0; i < 5; i++)
            {
                Country_label[i].setVisible(false);
                Rank_label[i].setVisible(false);
            }
        });

    });

    //点击返回目录按钮
    connect(ui->returnmenuButton, &QPushButton::clicked, this, [=](){
        emit this->SceneBack();
    });
}

void OutPut_Search::paintEvent(QPaintEvent *)
{
    //创建画家，指定绘图设备
    QPainter painter(this);
    //创建QPixmap对象
    QPixmap pix;
    //加载图片
    pix.load(":/OlympicsPicture/background7.jfif");
    //绘制背景图
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
}

OutPut_Search::~OutPut_Search()
{
    delete ui;
}
