#ifndef WIDGET_H    // specific preprocessor command (Header Guard) to prevent...
#define WIDGET_H    // ...this file from being included more than once in a single compilation.

#include <QWidget>      // Includes the base QWidget class which we inherit from.
#include <QFont>        // Includes QFont to handle font styling (used for the button text).
#include <QPushButton>  // Includes QPushButton to create the clickable button.

// Standard Qt macros to ensure namespaces work correctly across different Qt versions.
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget; // Forward declaration of the Ui::Widget class (generated from widget.ui).
}
QT_END_NAMESPACE

// Defines our custom class 'Widget' which inherits from QWidget (the base class for all UI objects).
class Widget : public QWidget
{
    Q_OBJECT // A special macro required for any class that uses Qt's signals and slots mechanism.

public:
    // Constructor declaration: Takes an optional parent widget (nullptr means it's a top-level window).
    Widget(QWidget *parent = nullptr);
    
    // Destructor declaration: Cleans up resources when the object is destroyed.
    ~Widget();

private:
    // A pointer to the UI object created by Qt Designer (manages the XML layout).
    Ui::Widget *ui;
};
#endif // WIDGET_H  // Ends the header guard.
