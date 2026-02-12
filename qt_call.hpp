#ifndef qt_call_hpp
#define qt_call_hpp

#include <iostream>
#include <string>
#include <QMainWindow>
#include "qt_canvas.hpp"
/* CHECK : need to check whether this access specifier has to be public or private */
class MainWindow : public QMainWindow{
    public:
        MainWindow();
        void createToolBar();
        void createMenus();
        void createActions();
    
    private:
        QAction* rectangle;
        QAction* roundedRectangle;
        QAction* circle;
        QAction* line;
        QAction* hexagon;
        QAction* freehand;
        QAction* text;
        QAction* colorFill;
        QAction* colorBdr;
        QAction* widthBdr;
        QAction* newFile;
        QAction* openFile;
        QAction* saveFile;
        QAction* saveAsFile;
        QAction* exitApp;
        QMenu* fileMenu;
        QMenu* fileMenu2;
        QToolBar* fileToolBar;
        QAction* cut; 
        QAction* copy; 
        QAction* paste; 
        QAction* undo; 
        QAction* redo;
};

#endif