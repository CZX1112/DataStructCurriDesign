#include "seperatechaining.h"
#include "ui_seperatechaining.h"

seperatechaining::seperatechaining(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::seperatechaining)
{
    ui->setupUi(this);
}

seperatechaining::~seperatechaining()
{
    delete ui;
}
