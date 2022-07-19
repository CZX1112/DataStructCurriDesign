#ifndef OUTPUT_SEARCH_H
#define OUTPUT_SEARCH_H

#include <QWidget>

namespace Ui {
class OutPut_Search;
}

typedef struct
{
    int itemnum;        //项目编号
    int top;            //取名次的数目
    int range[5];       //名次
    int mark[5];        //分数
} itemnode;             //定义项目结点的类型

typedef struct
{
    int countrynum;     //国家编号
    int score;          //国家总分
    int mscore;         //男团体总分
    int wscore;         //女团体总分
    itemnode c[100];    //项目数组
} headnode;             //定义头结点类型

class OutPut_Search : public QWidget
{
    Q_OBJECT

public:
    explicit OutPut_Search(headnode *h, int &country_num, QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    ~OutPut_Search();

signals:
    void SceneBack();

private:
    Ui::OutPut_Search *ui;
};

#endif // OUTPUT_SEARCH_H
