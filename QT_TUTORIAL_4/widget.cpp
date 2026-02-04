#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setFixedHeight(200, 120);
    QPushButton *quit = new QPushButton(tr("QUIT APPLICATION"),this);
    quit->setGeometry(62,40,75,30);
    quit->setFont(QFont("Times",18,QFont::Bold));
    connect(quit,SIGNAL(clicked()),qApp,SLOT(quit()));
}

Widget::~Widget()
{
    delete ui;
}
