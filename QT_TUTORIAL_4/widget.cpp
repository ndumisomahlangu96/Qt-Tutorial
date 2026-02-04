#include "widget.h"       // Includes our class definition.
#include "ui_widget.h"    // Includes the code generated automatically from widget.ui.

// Constructor implementation
Widget::Widget(QWidget *parent)
    : QWidget(parent)       // Calls the base class (QWidget) constructor to initialize the widget.
    , ui(new Ui::Widget)    // Initializes the 'ui' pointer by creating a new instance of the UI class.
{
    // Sets up the user interface elements defined in widget.ui (connects the XML design to C++).
    ui->setupUi(this);

    // Sets the window size to a fixed width of 200px and height of 120px.
    // This prevents the user from resizing the window by dragging the corners.
    setFixedSize(200, 120);

    // Creates a new Push Button dynamically with the text "QUIT" and sets 'this' (the Widget) as its parent.
    QPushButton *quit = new QPushButton(tr("QUIT"), this);

    // Sets the position and size of the button inside the window:
    // x=62, y=40 (position from top-left), width=75, height=30.
    quit->setGeometry(62, 40, 75, 30);

    // Creates a font object (Times New Roman, Size 18, Bold) and applies it to the button.
    quit->setFont(QFont("Times", 18, QFont::Bold));

    // Connects the button's action to the application's exit command.
    // 1. Sender: quit (the button)
    // 2. Signal: clicked() (triggered when user clicks it)
    // 3. Receiver: qApp (global pointer to the QApplication)
    // 4. Slot: quit() (the function to run, which closes the app)
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
}

// Destructor implementation
Widget::~Widget()
{
    // Deletes the UI object to free up memory (prevents memory leaks).
    delete ui;
}
