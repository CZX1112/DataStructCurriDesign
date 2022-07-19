#include "chainoperation.h"
#include "ui_chainoperation.h"
#include <QPushButton>
#include <QDebug>
#include <QLabel>
#include <QFont>
#include <QLineEdit>
#include <QString>
#include <QPainter>

int nodecount;

ChainOperation::ChainOperation(int &datanum, int &hashtable_length, char keys[][100], char values[][100], int chain_number, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChainOperation)
{
    ui->setupUi(this);

    resize(500, 400);

    for (int i = 0; i < hashtable_length; i++)
        hashdata[i] = NULL;

    //哈希表建立
    if (chain_number == 1)
    {
        //设置窗口命名
        setWindowTitle("哈希表建立");

        resize(800, 600);

        ui->returnmenuButton->move(0, this->height() - ui->returnmenuButton->height());
        ui->exitButton->move(this->width() - ui->exitButton->width(), this->height() - ui->exitButton->height());


        hash_size = hashtable_length;

        //标题标签
        QLabel * title_label = new QLabel("链地址法", this);
        QFont title_label_font("SimHei", 18, 75);
        title_label->setFont(title_label_font);
        title_label->setVisible(true);
        title_label->move(this->width() / 2 - title_label->width() / 2, 20);

        //哈希表建立标签
        QLabel * search_label = new QLabel("哈希表的建立", this);
        QFont search_label_font("KaiTi", 18, 75);
        search_label->setFont(search_label_font);
        search_label->setVisible(true);
        search_label->move(this->width() / 2 - search_label->width() / 2, 80);

        //链地址法图例（颜色解释）
        //头节点框
        QLabel * HeadNodeNotesFrame_label = new QLabel(this);
        HeadNodeNotesFrame_label->resize(60, 40);
        HeadNodeNotesFrame_label->move(160, this->height() - HeadNodeNotesFrame_label->height());
        QImage * HeadNodeNotesFrame_image = new QImage(":/HashTablePicture/HeadNodeFrame.png");
        HeadNodeNotesFrame_image->scaled(HeadNodeNotesFrame_label->size(), Qt::KeepAspectRatio);
        HeadNodeNotesFrame_label->setScaledContents(true);
        HeadNodeNotesFrame_label->setPixmap(QPixmap::fromImage(*HeadNodeNotesFrame_image));
        //头节点框标签
        QLabel * HeadNodeNotesFrameText_label = new QLabel("头节点框" ,this);
        QFont HeadNodeNotesFrameText_font("KaiTi", 12);
        HeadNodeNotesFrameText_label->setFont(HeadNodeNotesFrameText_font);
        HeadNodeNotesFrameText_label->move(160 + HeadNodeNotesFrame_label->width(), this->height() - HeadNodeNotesFrame_label->height() + 10);

        //key框
        QLabel * KeyNotesFrame_label = new QLabel(this);
        KeyNotesFrame_label->resize(60, 40);
        KeyNotesFrame_label->move(330, this->height() - KeyNotesFrame_label->height());
        QImage * KeyNotesFrame_image = new QImage(":/HashTablePicture/keyframe.png");
        KeyNotesFrame_image->scaled(KeyNotesFrame_label->size(), Qt::KeepAspectRatio);
        KeyNotesFrame_label->setScaledContents(true);
        KeyNotesFrame_label->setPixmap(QPixmap::fromImage(*KeyNotesFrame_image));
        //key框标签
        QLabel * KeyNotesFrameText_label = new QLabel("关键字框" ,this);
        QFont KeyNotesFrameFrameText_font("KaiTi", 12);
        KeyNotesFrameText_label->setFont(KeyNotesFrameFrameText_font);
        KeyNotesFrameText_label->move(330 + KeyNotesFrame_label->width(), this->height() - KeyNotesFrame_label->height() + 10);

        //value框
        QLabel * ValueNotesFrame_label = new QLabel(this);
        ValueNotesFrame_label->resize(60, 40);
        ValueNotesFrame_label->move(500, this->height() - ValueNotesFrame_label->height());
        QImage * ValueNotesFrame_image = new QImage(":/HashTablePicture/valueframe.png");
        ValueNotesFrame_image->scaled(ValueNotesFrame_label->size(), Qt::KeepAspectRatio);
        ValueNotesFrame_label->setScaledContents(true);
        ValueNotesFrame_label->setPixmap(QPixmap::fromImage(*ValueNotesFrame_image));
        //value框标签
        QLabel * ValueNotesFrameText_label = new QLabel("数据值框" ,this);
        QFont ValueNotesFrameFrameText_font("KaiTi", 12);
        ValueNotesFrameText_label->setFont(ValueNotesFrameFrameText_font);
        ValueNotesFrameText_label->move(500 + ValueNotesFrame_label->width(), this->height() - ValueNotesFrame_label->height() + 10);

        for (int i = 0; i < hashtable_length; i++)
        {
            //1——hashtable_length哈希表序号
            QLabel * HashTableNO_label = new QLabel(QString::number(i), this);
            QFont HashTableNO_font("KaiTi", 12);
            HashTableNO_label->setFont(HashTableNO_font);
            HashTableNO_label->move(25, 140 + 50 * i);

            QLabel * HeadNodeFrame_label = new QLabel(this);
            HeadNodeFrame_label->resize(60, 40);
            HeadNodeFrame_label->move(50, 130 + 50 * i);
            QImage * HeadNodeFrame_image = new QImage(":/HashTablePicture/HeadNodeFrame.png");
            HeadNodeFrame_image->scaled(HeadNodeFrame_label->size(), Qt::KeepAspectRatio);
            HeadNodeFrame_label->setScaledContents(true);
            HeadNodeFrame_label->setPixmap(QPixmap::fromImage(*HeadNodeFrame_image));
        }

        //进入下一步按钮
        QPushButton * next_btn = new QPushButton("NEXT", this);
        QFont next_btn_font("KaiTi", 10);
        next_btn->setFont(next_btn_font);


        next_btn->move(this->width() - ui->exitButton->width(), this->height() - ui->exitButton->height() - next_btn->height());

        QLabel * HashTableNOText_label = new QLabel[hashtable_length];
        for (int i = 0; i < hashtable_length; i++)
        {
            HashTableNOText_label[i].setParent(this);
            HashTableNOText_label[i].setText("空");
            HashTableNOText_label[i].resize(60, 40);
            QFont HashTableNO_font("KaiTi", 12);
            HashTableNOText_label[i].setFont(HashTableNO_font);
            HashTableNOText_label[i].move(70, 130 + 50 * i);
            HashTableNOText_label[i].setAlignment(Qt::AlignHCenter);//QLabel水平居中
            HashTableNOText_label[i].setAlignment(Qt::AlignVCenter);//QLabel垂直居中
        }

        //计数器
        nodecount = 0;
        connect(next_btn, &QPushButton::clicked, this, [=](){
            for (int i = 0; i < hashtable_length; i++)
                hashdata[i] = NULL;
            for (int i = 0; i < nodecount + 1; i++)
                hashinsert(keys[i], values[i]);
            qDebug() << "The results is:";
            display();
            //输出链地址法哈希表数据
            hashnode *p;
            for (int i = 0; i < hash_size; i++)
            {
                if (hashdata[i] == NULL)
                    HashTableNOText_label[i].setVisible(true);
                else
                {
                    HashTableNOText_label[i].setVisible(false);
                    p = hashdata[i];
                    int j = 0;
                    for (; p != NULL; p = p->next)
                    {
                        QLabel * NotesPic_label = new QLabel(this);
                        NotesPic_label->resize(160, 40);
                        NotesPic_label->move(110 + 160 * j, 130 + 50 * i);
                        QImage *img_mainicon;//主图标显示在右上角lable中
                        img_mainicon =new QImage;//新建一个image对象
                        img_mainicon->load(":/HashTablePicture/frame2.png");
                        img_mainicon->scaled(NotesPic_label->size(),Qt::KeepAspectRatio);
                        NotesPic_label->setScaledContents(true);
                        NotesPic_label->setPixmap(QPixmap::fromImage(*img_mainicon));
                        NotesPic_label->setVisible(true);

                        QLabel * NodeKeyText_label = new QLabel(p->key, this);
                        QFont NodeKeyText_font("KaiTi", 12);
                        NodeKeyText_label->setFont(NodeKeyText_font);
                        NodeKeyText_label->move(110 + 160 * j + 30, 130 + 50 * i + 10);
                        NodeKeyText_label->setVisible(true);

                        QLabel * NodeValueText_label = new QLabel(p->value, this);
                        QFont NodeValueText_font("KaiTi", 12);
                        NodeValueText_label->setFont(NodeValueText_font);
                        NodeValueText_label->move(110 + 160 * j + 30 + 60, 130 + 50 * i + 10);
                        NodeValueText_label->setVisible(true);

                        j++;
                    }
                }
            }
            nodecount++;
            if (nodecount >= datanum)
                next_btn->setVisible(false);
        });

        //按返回目录按钮返回目录界面
        connect(ui->returnmenuButton, &QPushButton::clicked, this, [=](){
            emit this->SceneBack();
        });
    }

    //哈希表查找
    if (chain_number == 2)
    {
        //设置窗口命名
        setWindowTitle("哈希表查找");

        hash_size = hashtable_length;
        for (int i = 0; i < datanum; i++)
            hashinsert(keys[i], values[i]);
        qDebug() << "The results is:";
        display();

        //标题标签
        QLabel * title_label = new QLabel("链地址法", this);
        QFont title_label_font("SimHei", 18, 75);
        title_label->setFont(title_label_font);
        title_label->setVisible(true);
        title_label->move(this->width() / 2 - title_label->width() / 2, 20);

        //哈希查找标签
        QLabel * search_label = new QLabel("哈希表的查找", this);
        QFont search_label_font("KaiTi", 18, 75);
        search_label->setFont(search_label_font);
        search_label->setVisible(true);
        search_label->move(this->width() / 2 - search_label->width() / 2, 85);

        //提示标签
        QLabel * Tips_label = new QLabel("请输入关键字进行查找", this);
        QFont Tips_label_font("SimHei", 16);
        Tips_label->setFont(Tips_label_font);
        Tips_label->setVisible(true);
        Tips_label->move(this->width() / 2 - Tips_label->width() / 2, 150);

        //输入标签（关键字）
        QFont label_font("SimSun", 14);
        QLabel * KeyWords_label = new QLabel("关键字：", this);
        KeyWords_label->setFont(label_font);
        KeyWords_label->setVisible(true);
        KeyWords_label->move(80, 220);

        //输入文本框（关键字）
        QLineEdit * KeyWords_lineedit = new QLineEdit(this);
        KeyWords_lineedit->setVisible(true);
        KeyWords_lineedit->move(180, 222);

        //输入完成按钮
        QPushButton * InputOver_btn = new QPushButton("输入完成", this);
        QFont InputOver_btn_font("SimSun", 10);
        InputOver_btn->setFont(InputOver_btn_font);
        InputOver_btn->setVisible(true);
        InputOver_btn->move(200 + KeyWords_lineedit->width(), 220);

        //输入标签（数据值）
        QFont values_label_font("SimSun", 16);
        QLabel * Values_label = new QLabel("数据值：           ", this);
        Values_label->setFont(values_label_font);
        Values_label->setVisible(false);
        Values_label->move(80, 280);

        //输入标签（没找到）
        qDebug() << "查找失败——找不到所对应的数据值！";
        QLabel * ValueNotFound_label = new QLabel("找不到所对应的数据值！", this);
        QFont ValueNotFound_label_font("SimSun", 16);
        ValueNotFound_label->setFont(ValueNotFound_label_font);
        ValueNotFound_label->setVisible(false);
        ValueNotFound_label->move(110, 280);


        //按下输入完成按钮得到关键字
        connect(InputOver_btn, &QPushButton::clicked, this, [=](){
            hashnode *flag = NULL;
            QString key;
            QString value;
            char StringkeyTokeys[100];
            //QString转char数组
            key = KeyWords_lineedit->text();
            QByteArray ba = key.toLocal8Bit();
            memcpy(StringkeyTokeys, ba.data(), ba.size() + 1);

            flag = hashfind(StringkeyTokeys);
            if (flag == NULL)
            {
                Values_label->setVisible(false);
                ValueNotFound_label->setVisible(true);
            }
            else
            {
                ValueNotFound_label->setVisible(false);
                value = QString::fromLocal8Bit(flag->value);
                Values_label->setText("数据值：" + value);
                Values_label->setVisible(true);
            }
        });

        //按返回目录按钮返回目录界面
        connect(ui->returnmenuButton, &QPushButton::clicked, this, [=](){
            emit this->SceneBack();
        });
    }

    //哈希表插入
    if (chain_number == 3)
    {
        //设置窗口命名
        setWindowTitle("哈希表插入");

        resize(800, 600);

        ui->returnmenuButton->move(0, this->height() - ui->returnmenuButton->height());
        ui->exitButton->move(this->width() - ui->exitButton->width(), this->height() - ui->exitButton->height());

        hash_size = hashtable_length;
        for (int i = 0; i < datanum; i++)
            hashinsert(keys[i], values[i]);

        //标题标签
        QLabel * title_label = new QLabel("链地址法", this);
        QFont title_label_font("SimHei", 18, 75);
        title_label->setFont(title_label_font);
        title_label->setVisible(true);
        title_label->move(this->width() / 2 - title_label->width() / 2, 20);

        //哈希表插入标签
        QLabel * insert_label = new QLabel("哈希表的插入", this);
        QFont search_label_font("KaiTi", 18, 75);
        insert_label->setFont(search_label_font);
        insert_label->setVisible(true);
        insert_label->move(this->width() / 2 - insert_label->width() / 2, 80);

        //插入关键字标签
        QLabel * KeyInsert_label = new QLabel("关键字：",this);
        QFont KeyInsert_label_font("KaiTi", 12, 75);
        KeyInsert_label->setFont(KeyInsert_label_font);
        KeyInsert_label->move(40, 130);
        //插入关键字文本框
        QLineEdit * KeyInsert_lineedit = new QLineEdit(this);
        KeyInsert_lineedit->move(40 + KeyInsert_label->width(), 130);
        //插入数据值标签
        QLabel * ValueInsert_label = new QLabel("数据值：",this);
        QFont ValueInsert_label_font("KaiTi", 12, 75);
        ValueInsert_label->setFont(ValueInsert_label_font);
        ValueInsert_label->move(350, 130);
        //插入数据值文本框
        QLineEdit * ValueInsert_lineedit = new QLineEdit(this);
        ValueInsert_lineedit->move(350 + ValueInsert_label->width(), 130);
        //插入哈希表输入完成按钮
        QPushButton * InsertInputOver_btn = new QPushButton("插入完毕", this);
        QFont InsertInputOver_btn_font("KaiTi", 12, 75);
        InsertInputOver_btn->setFont(InsertInputOver_btn_font);
        InsertInputOver_btn->move(665, 130);

        connect(InsertInputOver_btn, &QPushButton::clicked, this, [=, &datanum](){
            QString key, value;
            char KEY[100], VALUE[100];
            key = KeyInsert_lineedit->text();
            QByteArray ba = key.toLocal8Bit();
            memcpy(KEY, ba.data(), ba.size() + 1);

            value = ValueInsert_lineedit->text();

            QByteArray ba2 = value.toLocal8Bit();
            memcpy(VALUE, ba2.data(), ba2.size() + 1);

            hashinsert2(datanum, KEY, VALUE, keys, values);
            qDebug() << "插入完查看！";
            qDebug() << "The results is:";
            display();


            //链地址法图例（颜色解释）
            //头节点框
            QLabel * HeadNodeNotesFrame_label = new QLabel(this);
            HeadNodeNotesFrame_label->resize(60, 40);
            HeadNodeNotesFrame_label->move(160, this->height() - HeadNodeNotesFrame_label->height());
            QImage * HeadNodeNotesFrame_image = new QImage(":/HashTablePicture/HeadNodeFrame.png");
            HeadNodeNotesFrame_image->scaled(HeadNodeNotesFrame_label->size(), Qt::KeepAspectRatio);
            HeadNodeNotesFrame_label->setScaledContents(true);
            HeadNodeNotesFrame_label->setPixmap(QPixmap::fromImage(*HeadNodeNotesFrame_image));
            HeadNodeNotesFrame_label->setVisible(true);
            //头节点框标签
            QLabel * HeadNodeNotesFrameText_label = new QLabel("头节点框" ,this);
            QFont HeadNodeNotesFrameText_font("KaiTi", 12);
            HeadNodeNotesFrameText_label->setFont(HeadNodeNotesFrameText_font);
            HeadNodeNotesFrameText_label->move(160 + HeadNodeNotesFrame_label->width(), this->height() - HeadNodeNotesFrame_label->height() + 10);
            HeadNodeNotesFrameText_label->setVisible(true);

            //key框
            QLabel * KeyNotesFrame_label = new QLabel(this);
            KeyNotesFrame_label->resize(60, 40);
            KeyNotesFrame_label->move(330, this->height() - KeyNotesFrame_label->height());
            QImage * KeyNotesFrame_image = new QImage(":/HashTablePicture/keyframe.png");
            KeyNotesFrame_image->scaled(KeyNotesFrame_label->size(), Qt::KeepAspectRatio);
            KeyNotesFrame_label->setScaledContents(true);
            KeyNotesFrame_label->setPixmap(QPixmap::fromImage(*KeyNotesFrame_image));
            KeyNotesFrame_label->setVisible(true);
            //key框标签
            QLabel * KeyNotesFrameText_label = new QLabel("关键字框" ,this);
            QFont KeyNotesFrameFrameText_font("KaiTi", 12);
            KeyNotesFrameText_label->setFont(KeyNotesFrameFrameText_font);
            KeyNotesFrameText_label->move(330 + KeyNotesFrame_label->width(), this->height() - KeyNotesFrame_label->height() + 10);
            KeyNotesFrameText_label->setVisible(true);

            //value框
            QLabel * ValueNotesFrame_label = new QLabel(this);
            ValueNotesFrame_label->resize(60, 40);
            ValueNotesFrame_label->move(500, this->height() - ValueNotesFrame_label->height());
            QImage * ValueNotesFrame_image = new QImage(":/HashTablePicture/valueframe.png");
            ValueNotesFrame_image->scaled(ValueNotesFrame_label->size(), Qt::KeepAspectRatio);
            ValueNotesFrame_label->setScaledContents(true);
            ValueNotesFrame_label->setPixmap(QPixmap::fromImage(*ValueNotesFrame_image));
            ValueNotesFrame_label->setVisible(true);
            //value框标签
            QLabel * ValueNotesFrameText_label = new QLabel("数据值框" ,this);
            QFont ValueNotesFrameFrameText_font("KaiTi", 12);
            ValueNotesFrameText_label->setFont(ValueNotesFrameFrameText_font);
            ValueNotesFrameText_label->move(500 + ValueNotesFrame_label->width(), this->height() - ValueNotesFrame_label->height() + 10);
            ValueNotesFrameText_label->setVisible(true);

            for (int i = 0; i < hashtable_length; i++)
            {
                //1——hashtable_length哈希表序号
                QLabel * HashTableNO_label = new QLabel(QString::number(i), this);
                QFont HashTableNO_font("KaiTi", 12);
                HashTableNO_label->setFont(HashTableNO_font);
                HashTableNO_label->move(25, 180 + 50 * i);
                HashTableNO_label->setVisible(true);

                QLabel * HeadNodeFrame_label = new QLabel(this);
                HeadNodeFrame_label->resize(60, 40);
                HeadNodeFrame_label->move(50, 170 + 50 * i);
                QImage * HeadNodeFrame_image = new QImage(":/HashTablePicture/HeadNodeFrame.png");
                HeadNodeFrame_image->scaled(HeadNodeFrame_label->size(), Qt::KeepAspectRatio);
                HeadNodeFrame_label->setScaledContents(true);
                HeadNodeFrame_label->setPixmap(QPixmap::fromImage(*HeadNodeFrame_image));
                HeadNodeFrame_label->setVisible(true);
            }

            //输出链地址法哈希表数据
            hashnode *p;
            for (int i = 0; i < hash_size; i++)
            {
                if (hashdata[i] == NULL)
                {
                    //1——hashtable_length哈希表序号
                    QLabel * HashTableNOText_label = new QLabel("空", this);
                    HashTableNOText_label->resize(60, 40);
                    QFont HashTableNO_font("KaiTi", 12);
                    HashTableNOText_label->setFont(HashTableNO_font);
                    HashTableNOText_label->move(70, 170 + 50 * i);
                    HashTableNOText_label->setAlignment(Qt::AlignHCenter);//QLabel水平居中
                    HashTableNOText_label->setAlignment(Qt::AlignVCenter);//QLabel垂直居中
                    HashTableNOText_label->setVisible(true);
                }
                else
                {
                    p = hashdata[i];
                    int j = 0;
                    for (; p != NULL; p = p->next)
                    {
                        QLabel * NotesPic_label = new QLabel(this);
                        NotesPic_label->resize(160, 40);
                        NotesPic_label->move(110 + 160 * j, 170 + 50 * i);
                        QImage *img_mainicon;//主图标显示在右上角lable中
                        img_mainicon =new QImage;//新建一个image对象
                        img_mainicon->load(":/HashTablePicture/frame2.png");
                        img_mainicon->scaled(NotesPic_label->size(),Qt::KeepAspectRatio);
                        NotesPic_label->setScaledContents(true);
                        NotesPic_label->setPixmap(QPixmap::fromImage(*img_mainicon));
                        NotesPic_label->setVisible(true);

                        QLabel * NodeKeyText_label = new QLabel(p->key, this);
                        QFont NodeKeyText_font("KaiTi", 12);
                        NodeKeyText_label->setFont(NodeKeyText_font);
                        NodeKeyText_label->setVisible(true);
                        NodeKeyText_label->move(110 + 160 * j + 30, 170 + 50 * i + 10);

                        QLabel * NodeValueText_label = new QLabel(p->value, this);
                        QFont NodeValueText_font("KaiTi", 12);
                        NodeValueText_label->setFont(NodeValueText_font);
                        NodeValueText_label->move(110 + 160 * j + 30 + 60, 170 + 50 * i + 10);
                        NodeValueText_label->setVisible(true);

                        j++;
                    }
                }
            }
        });


        //按返回目录按钮返回目录界面
        connect(ui->returnmenuButton, &QPushButton::clicked, this, [=](){
            emit this->SceneBack();
        });
    }

    //哈希表删除
    if (chain_number == 4)
    {
        //设置窗口命名
        setWindowTitle("哈希表删除");

        resize(800, 600);

        ui->returnmenuButton->move(0, this->height() - ui->returnmenuButton->height());
        ui->exitButton->move(this->width() - ui->exitButton->width(), this->height() - ui->exitButton->height());

        //标题标签
        QLabel * title_label = new QLabel("链地址法", this);
        QFont title_label_font("SimHei", 18, 75);
        title_label->setFont(title_label_font);
        title_label->setVisible(true);
        title_label->move(this->width() / 2 - title_label->width() / 2, 20);

        //哈希表删除标签
        QLabel * search_label = new QLabel("哈希表的删除", this);
        QFont search_label_font("KaiTi", 18, 75);
        search_label->setFont(search_label_font);
        search_label->setVisible(true);
        search_label->move(this->width() / 2 - search_label->width() / 2, 80);

        //删除关键字标签
        QLabel * KeyDelete_label = new QLabel("要删除的关键字：",this);
        QFont KeyDelete_label_font("KaiTi", 12, 75);
        KeyDelete_label->setFont(KeyDelete_label_font);
        KeyDelete_label->move(160, 130);
        //删除关键字文本框
        QLineEdit * KeyDelete_lineedit = new QLineEdit(this);
        KeyDelete_lineedit->move(340, 130);
        //删除哈希表输入完成按钮
        QPushButton * DeleteInputOver_btn = new QPushButton("删除完毕", this);
        QFont DeleteInputOver_btn_font("KaiTi", 12, 75);
        DeleteInputOver_btn->setFont(DeleteInputOver_btn_font);
        DeleteInputOver_btn->move(530, 128);

        //找不到提示标签
        qDebug() << "删除失败——找不到此关键字对应的数据值！";
        QLabel * DeleteNotFound_label = new QLabel("找不到此关键字对应的数据值！", this);
        QFont DeleteNotFound_font("KaiTi", 25, 75);
        DeleteNotFound_label->setFont(DeleteNotFound_font);
        DeleteNotFound_label->setVisible(false);
        DeleteNotFound_label->move(50, 300);

        hash_size = hashtable_length;

        //按下输入删除完成按钮
        connect(DeleteInputOver_btn, &QPushButton::clicked, this, [=, &datanum](){
            for (int i = 0; i < datanum; i++)
                hashinsert(keys[i], values[i]);
            QString key;
            char KEY[100];
            key = KeyDelete_lineedit->text();
            QByteArray ba = key.toLocal8Bit();
            memcpy(KEY, ba.data(), ba.size() + 1);

            bool flag;
            flag = hashdelete2(datanum, keys, values, KEY);
            if (flag == true)
            {
                DeleteNotFound_label->setVisible(false);
                hashdelete(KEY);


                qDebug() << "删除完查看！";
                qDebug() << "The results is:";
                display();

                //链地址法图例（颜色解释）
                //头节点框
                QLabel * HeadNodeNotesFrame_label = new QLabel(this);
                HeadNodeNotesFrame_label->resize(60, 40);
                HeadNodeNotesFrame_label->move(160, this->height() - HeadNodeNotesFrame_label->height());
                QImage * HeadNodeNotesFrame_image = new QImage(":/HashTablePicture/HeadNodeFrame.png");
                HeadNodeNotesFrame_image->scaled(HeadNodeNotesFrame_label->size(), Qt::KeepAspectRatio);
                HeadNodeNotesFrame_label->setScaledContents(true);
                HeadNodeNotesFrame_label->setPixmap(QPixmap::fromImage(*HeadNodeNotesFrame_image));
                HeadNodeNotesFrame_label->setVisible(true);
                //头节点框标签
                QLabel * HeadNodeNotesFrameText_label = new QLabel("头节点框" ,this);
                QFont HeadNodeNotesFrameText_font("KaiTi", 12);
                HeadNodeNotesFrameText_label->setFont(HeadNodeNotesFrameText_font);
                HeadNodeNotesFrameText_label->move(160 + HeadNodeNotesFrame_label->width(), this->height() - HeadNodeNotesFrame_label->height() + 10);
                HeadNodeNotesFrameText_label->setVisible(true);

                //key框
                QLabel * KeyNotesFrame_label = new QLabel(this);
                KeyNotesFrame_label->resize(60, 40);
                KeyNotesFrame_label->move(330, this->height() - KeyNotesFrame_label->height());
                QImage * KeyNotesFrame_image = new QImage(":/HashTablePicture/keyframe.png");
                KeyNotesFrame_image->scaled(KeyNotesFrame_label->size(), Qt::KeepAspectRatio);
                KeyNotesFrame_label->setScaledContents(true);
                KeyNotesFrame_label->setPixmap(QPixmap::fromImage(*KeyNotesFrame_image));
                KeyNotesFrame_label->setVisible(true);
                //key框标签
                QLabel * KeyNotesFrameText_label = new QLabel("关键字框" ,this);
                QFont KeyNotesFrameFrameText_font("KaiTi", 12);
                KeyNotesFrameText_label->setFont(KeyNotesFrameFrameText_font);
                KeyNotesFrameText_label->move(330 + KeyNotesFrame_label->width(), this->height() - KeyNotesFrame_label->height() + 10);
                KeyNotesFrameText_label->setVisible(true);

                //value框
                QLabel * ValueNotesFrame_label = new QLabel(this);
                ValueNotesFrame_label->resize(60, 40);
                ValueNotesFrame_label->move(500, this->height() - ValueNotesFrame_label->height());
                QImage * ValueNotesFrame_image = new QImage(":/HashTablePicture/valueframe.png");
                ValueNotesFrame_image->scaled(ValueNotesFrame_label->size(), Qt::KeepAspectRatio);
                ValueNotesFrame_label->setScaledContents(true);
                ValueNotesFrame_label->setPixmap(QPixmap::fromImage(*ValueNotesFrame_image));
                ValueNotesFrame_label->setVisible(true);
                //value框标签
                QLabel * ValueNotesFrameText_label = new QLabel("数据值框" ,this);
                QFont ValueNotesFrameFrameText_font("KaiTi", 12);
                ValueNotesFrameText_label->setFont(ValueNotesFrameFrameText_font);
                ValueNotesFrameText_label->move(500 + ValueNotesFrame_label->width(), this->height() - ValueNotesFrame_label->height() + 10);
                ValueNotesFrameText_label->setVisible(true);

                for (int i = 0; i < hashtable_length; i++)
                {
                    //1——hashtable_length哈希表序号
                    QLabel * HashTableNO_label = new QLabel(QString::number(i), this);
                    QFont HashTableNO_font("KaiTi", 12);
                    HashTableNO_label->setFont(HashTableNO_font);
                    HashTableNO_label->move(25, 180 + 50 * i);
                    HashTableNO_label->setVisible(true);

                    QLabel * HeadNodeFrame_label = new QLabel(this);
                    HeadNodeFrame_label->resize(60, 40);
                    HeadNodeFrame_label->move(50, 170 + 50 * i);
                    QImage * HeadNodeFrame_image = new QImage(":/HashTablePicture/HeadNodeFrame.png");
                    HeadNodeFrame_image->scaled(HeadNodeFrame_label->size(), Qt::KeepAspectRatio);
                    HeadNodeFrame_label->setScaledContents(true);
                    HeadNodeFrame_label->setPixmap(QPixmap::fromImage(*HeadNodeFrame_image));
                    HeadNodeFrame_label->setVisible(true);
                }

                //输出链地址法哈希表数据
                hashnode *p;
                for (int i = 0; i < hash_size; i++)
                {
                    if (hashdata[i] == NULL)
                    {
                        //1——hashtable_length哈希表序号
                        QLabel * HashTableNOText_label = new QLabel("空", this);
                        HashTableNOText_label->resize(60, 40);
                        QFont HashTableNO_font("KaiTi", 12);
                        HashTableNOText_label->setFont(HashTableNO_font);
                        HashTableNOText_label->move(70, 170 + 50 * i);
                        HashTableNOText_label->setAlignment(Qt::AlignHCenter);//QLabel水平居中
                        HashTableNOText_label->setAlignment(Qt::AlignVCenter);//QLabel垂直居中
                        HashTableNOText_label->setVisible(true);
                    }
                    else
                    {
                        p = hashdata[i];
                        int j = 0;
                        for (; p != NULL; p = p->next)
                        {
                            QLabel * NotesPic_label = new QLabel(this);
                            NotesPic_label->resize(160, 40);
                            NotesPic_label->move(110 + 160 * j, 170 + 50 * i);
                            QImage *img_mainicon;//主图标显示在右上角lable中
                            img_mainicon =new QImage;//新建一个image对象
                            img_mainicon->load(":/HashTablePicture/frame2.png");
                            img_mainicon->scaled(NotesPic_label->size(),Qt::KeepAspectRatio);
                            NotesPic_label->setScaledContents(true);
                            NotesPic_label->setPixmap(QPixmap::fromImage(*img_mainicon));
                            NotesPic_label->setVisible(true);

                            QLabel * NodeKeyText_label = new QLabel(p->key, this);
                            QFont NodeKeyText_font("KaiTi", 12);
                            NodeKeyText_label->setFont(NodeKeyText_font);
                            NodeKeyText_label->setVisible(true);
                            NodeKeyText_label->move(110 + 160 * j + 30, 170 + 50 * i + 10);

                            QLabel * NodeValueText_label = new QLabel(p->value, this);
                            QFont NodeValueText_font("KaiTi", 12);
                            NodeValueText_label->setFont(NodeValueText_font);
                            NodeValueText_label->move(110 + 160 * j + 30 + 60, 170 + 50 * i + 10);
                            NodeValueText_label->setVisible(true);

                            j++;
                        }
                    }
                }
            }
            else
                DeleteNotFound_label->setVisible(true);
        });

        //按返回目录按钮返回目录界面
        connect(ui->returnmenuButton, &QPushButton::clicked, this, [=](){
            emit this->SceneBack();
        });
    }

    //按下退出程序按钮退出程序
    connect(ui->exitButton, &QPushButton::clicked, this, [=](){
        this->close();
    });
}

char *strcopy(char *s)
{
    int len = strlen(s) + 1;
    char *res = new char[len];
    strcpy(res, s);
    if (res == NULL)
        return NULL;
    return res;
}

void ChainOperation::hashtable(int size)
{
    hash_size = size;
}

//hash函数可以自己定义
unsigned int ChainOperation::hasher(char *s)
{
    unsigned int res = 0;
    for (; *s != '\0'; ++s)
        res = *s + res;
    return res % hash_size;
}

hashnode *ChainOperation::hashfind(char *keys)
{
    unsigned int res = hasher(keys);
    hashnode *p = hashdata[res];
    for (; p != NULL; p = p->next)
        if (strcmp(p->key, keys) == 0)
            return p;
    return NULL;
}

bool ChainOperation::hashinsert(char *keys, char *values)
{
    unsigned int res;
    if (keys == NULL)
        return 0;
    hashnode *p;
    if ((p = hashfind(keys)) == NULL)
    {
        res = hasher(keys);
        p = new hashnode;
        if (p == NULL)
            return 0;
        p->key = strcopy(keys);
        p->value = strcopy(values);
        if (p->key == NULL)
            return 0;

        p->next = hashdata[res]; //链表头插入
        hashdata[res] = p;
    }
    else
    {
        delete p->value; //如果key在哈希表中，先删除原有value值
        p->value = strcopy(values);
    }
    if (p->value == NULL)
        return 0;
    return 1;
}

bool ChainOperation::hashinsert2(int &datanum, char *key, char *value, char keys[][100], char values[][100])
{
    unsigned int res;
    if (keys == NULL)
        return 0;
    hashnode *p;
    if ((p = hashfind(key)) == NULL)
    {
        res = hasher(key);
        p = new hashnode;
        if (p == NULL)
            return 0;
        p->key = strcopy(key);
        p->value = strcopy(value);
        if (p->key == NULL)
            return 0;

        p->next = hashdata[res]; //链表头插入
        hashdata[res] = p;

        strcpy(keys[datanum], key);
        strcpy(values[datanum], value);
        datanum++;
    }
    else
    {
        delete p->value; //如果key在哈希表中，先删除原有value值
        p->value = strcopy(value);
    }
    if (p->value == NULL)
        return 0;
    return 1;
}

bool ChainOperation::hashdelete(char *keys)
{
    hashnode *p = NULL, *q = NULL;
    unsigned int res = hasher(keys);
    p = hashdata[res];
    if (!p)
        return 0;
    if (strcmp(p->key, keys) == 0)
    {
        hashdata[res] = p->next;
        delete p->key;
        delete p->value;
        delete p;
    }
    q = p;
    p = q->next;
    while (p && (strcmp(p->key, keys) != 0))
    {
        q = p;
        p = p->next;
    }
    if (p)
    {
        q->next = p->next;
        delete p->key;
        delete p->value;
        delete p;
    }
    return 1;
}

bool ChainOperation::hashdelete2(int &datanum, char keys[][100], char values[][100], char *key)
{
    int location = -1;
    for (int i = 0; i < datanum; i++)
        if (strcmp(keys[i], key) == 0)
            location = i;
    if (location != -1)
    {
        for (int i = location; i < datanum - 1; i++)
        {
            strcpy(keys[i], keys[i + 1]);
            strcpy(values[i], values[i + 1]);
        }
        datanum--;
    }

    if (location == -1)
        return false;
    else
        return true;
}

void ChainOperation::display()
{
    hashnode *p;
    for (int i = 0; i < hash_size; i++)
    {
        if (hashdata[i] == NULL)
            qDebug() << "()";
        //        {
        //            //1——hashtable_length哈希表序号
        //            QLabel * HashTableNOText_label = new QLabel(QString::number(i), this);
        //            QFont HashTableNO_font("SimHei", 10, 75);
        //            HashTableNOText_label->setFont(HashTableNO_font);
        //            HashTableNOText_label->move(50, 130 + 50 * i);
        //            HashTableNOText_label->setVisible(true);
        //        }
        else
        {
            p = hashdata[i];
            qDebug() << "(";
            for (; p != NULL; p = p->next)
                qDebug() << "(" << p->key << "," << p->value << ")";
            qDebug() << ")";
        }
    }
}

void ChainOperation::paintEvent(QPaintEvent *)
{
    //创建画家，指定绘图设备
    QPainter painter(this);
    //创建QPixmap对象
    QPixmap pix;
    //加载图片
    pix.load(":/HashTablePicture/background6.jfif");
    //绘制背景图
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
}

ChainOperation::~ChainOperation()
{
    delete ui;
}
