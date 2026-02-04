#include "widget.h"      // Includes the header file for our custom Widget class so we can use it.
#include <QApplication>  // Includes the QApplication class, which manages the application's control flow and main settings.

// The main entry point of the C++ program.
int main(int argc, char *argv[])
{
    // Creates the application object. 
    // It requires argc and argv to handle command-line arguments (standard for Qt apps).
    QApplication a(argc, argv);

    // Creates an instance of our custom 'Widget' class (defined in widget.h/cpp).
    // This is the main window of our application.
    Widget w;

    // Makes the widget visible on the screen. 
    // Without this, the window exists in memory but is not shown to the user.
    w.show();

    // Enters the main event loop and waits until exit() is called.
    // This is where the app waits for user interaction (clicks, key presses, etc.).
    return a.exec();
}
