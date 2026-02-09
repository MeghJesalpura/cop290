#ifndef qt_call.hpp
#define qt_call.hpp

#include <iostream>
#include <string>
#include <QMainWindow>
#include <QWidget> // be careful while compiling this file - need to use CMake

/* CHECK : need to check whether this access specifier has to be public or private */
class MainWindow : public QWidget{
    public:
        MainWindow();
        void createToolBar();
        void createMenus();
        void createActions();
};

#endif