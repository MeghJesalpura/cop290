#include <QtWidgets>
#include <QApplication>
//will have to include header files for the different applications
#include "qt_call.hpp"

int main(int argc, char *argv[]){
    Qapplication app(argc, argv);
    //Setup and show widgets here
    MainWindow w;
    w.show();

    return app.exec();
}