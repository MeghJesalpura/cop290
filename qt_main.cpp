#include <QtWidgets>
#include <QApplication>
//including the file which contains MainWindow class
#include "qt_call.hpp"

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    //Setting up application properties and UI
    QPalette myDark;
    myDark.setColor(QPalette::Window, QColor(45, 45, 45));
    myDark.setColor(QPalette::WindowText, Qt::white);
    myDark.setColor(QPalette::Base, QColor(30, 30, 30));
    myDark.setColor(QPalette::Text, Qt::white);
    myDark.setColor(QPalette::Button, QColor(45, 45, 45));
    myDark.setColor(QPalette::ButtonText, Qt::white);

    QApplication::setApplicationName("My SVG Editor");
    QApplication::setPalette(myDark);
    QApplication::setFont(QFont("Arial", 12));
    //Setup and show widgets here
    MainWindow w;
    w.show();

    return app.exec();
}