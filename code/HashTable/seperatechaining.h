#ifndef SEPERATECHAINING_H
#define SEPERATECHAINING_H

#include <QWidget>

namespace Ui {
class seperatechaining;
}

class seperatechaining : public QWidget
{
    Q_OBJECT

public:
    explicit seperatechaining(QWidget *parent = nullptr);
    ~seperatechaining();

private:
    Ui::seperatechaining *ui;
};

#endif // SEPERATECHAINING_H
