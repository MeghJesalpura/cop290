#include <QtWidgets>
#include <QApplication>
//including the file which contains MainWindow class
#include "qt_call.hpp"

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    //Setup and show widgets here
    MainWindow w;
    w.show();

    return app.exec();
}