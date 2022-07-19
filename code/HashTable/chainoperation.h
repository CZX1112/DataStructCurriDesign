#ifndef CHAINOPERATION_H
#define CHAINOPERATION_H

#include <QWidget>

struct hashnode
{
    char *key;
    char *value;
    hashnode *next;
};

namespace Ui {
class ChainOperation;
}

class ChainOperation : public QWidget
{
    Q_OBJECT

public:

    explicit ChainOperation(int &datanum, int &hashtable_length, char keys[][100], char values[][100], int chain_number, QWidget *parent = nullptr);
    ~ChainOperation();
    void paintEvent(QPaintEvent *);

    int hash_size;
    hashnode *hashdata[100];

    void hashtable(int size);

    unsigned int hasher(char *s);
    hashnode *hashfind(char *keys);
    bool hashinsert(char *keys, char *values);
    bool hashinsert2(int &datanum, char *key, char *value, char keys[][100], char values[][100]);
    bool hashdelete(char *keys);
    bool hashdelete2(int &datanum, char keys[][100], char values[][100], char *key);
    void display();

signals:
    void SceneBack();

private:
    Ui::ChainOperation *ui;
};

#endif // CHAINOPERATION_H
