#ifndef OPENADDRESSOPERATION_H
#define OPENADDRESSOPERATION_H

#include <QWidget>

namespace Ui {
class OpenAddressOperation;
}

class OpenAddressOperation : public QWidget
{
    Q_OBJECT

public:
    explicit OpenAddressOperation(int &datanum, int &hashtable_length, char keys[][100], char values[][100], int openaddress_number, QWidget *parent = nullptr);
    ~OpenAddressOperation();

signals:
    void SceneBack();

private:
    Ui::OpenAddressOperation *ui;
};

#endif // OPENADDRESSOPERATION_H
