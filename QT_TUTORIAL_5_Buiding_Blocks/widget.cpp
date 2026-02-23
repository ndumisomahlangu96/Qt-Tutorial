#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // FIX 1: Pass 'this' to establish the parent-child hierarchy.
    // This ensures the button is drawn inside the widget and prevents memory leaks.
    QPushButton *quit = new QPushButton("Quit", this);
    quit->setFont(QFont("Times", 18, QFont::Bold));

    QLCDNumber *lcd = new QLCDNumber(2,this);
    lcd->setSegmentStyle(QLCDNumber::Filled);

    QSlider *slider = new QSlider(Qt::Horizontal,this);
    slider->setRange(0,99);
    slider->setValue(0);

    // FIX 2 (Recommended): Use a layout to manage the UI correctly,
    // especially since you are also using a .ui file (ui->setupUi).
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(quit);
    mainLayout->addWidget(lcd);
    mainLayout->addWidget(slider);

    // Set the layout to the main widget
    this->setLayout(mainLayout);

    // Optional: Connect the quit button to close the application
    connect(quit, &QPushButton::clicked, this, &Widget::close);
}

Widget::~Widget()
{
    delete ui;
}
