#ifndef qt_call_hpp
#define qt_call_hpp

#include <QMainWindow>
#include "qt_canvas.hpp"
#include <QAction>
#include <QActionGroup>
#include <QMenu>
#include <QToolBar>
/*CHECK : need to check whether this access specifier has to be public or private */
class MainWindow : public QMainWindow{
    public:
        MainWindow();
        void createActions();
        void connectActions();
        void createToolBar();
        void createMenus();
    
    private:
        QAction* rectangle;
        QAction* roundedRectangle;
        QAction* circle;
        QAction* line;
        QAction* hexagon;
        QAction* freehand;
        QAction* text;
        QAction* select;
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
        Canvas* canvas;
        QActionGroup* toolActionGroup; //to ensure that only one tool is selected at a time
};

#endif