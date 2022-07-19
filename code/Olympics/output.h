#ifndef OUTPUT_H
#define OUTPUT_H

#include <QWidget>

typedef struct
{
    int itemnum;        //项目编号
    int top;            //取名次的数目
    int range[5];       //名次
    int mark[5];        //分数
} itemnode;             //定义项目结点的类型

typedef struct
{
    int countrynum;     //学校编号
    int score;          //学校总分
    int mscore;         //男团体总分
    int wscore;         //女团体总分
    itemnode c[100];    //项目数组
} headnode;             //定义头结点类型

namespace Ui {
class OutPut;
}

class OutPut : public QWidget
{
    Q_OBJECT

public:

    explicit OutPut(headnode *h, int &country_num, int &eventnum_man, int &eventnum_woman, QWidget *parent = nullptr);
    ~OutPut();

private:
    Ui::OutPut *ui;
};

#endif // OUTPUT_H
