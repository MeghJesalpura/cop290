#include "../../include/Qt_Part/qt_call.hpp" 
#include <QMenuBar>

MainWindow::MainWindow(){
    resize(1200, 900);
    setWindowTitle("SVG Editor");
    canvas = new Canvas(this);
    createActions();
    connectActions();
    createToolBar();
    createMenus();
    setCentralWidget(canvas);
}

void MainWindow::createToolBar(){
    fileToolBar = new QToolBar(tr("File"));
    addToolBar(Qt::LeftToolBarArea, fileToolBar);
    fileToolBar -> addAction(select);
    fileToolBar -> addAction(rectangle);
    fileToolBar -> addAction(roundedRectangle);
    fileToolBar -> addAction(circle);
    fileToolBar -> addAction(line);
    fileToolBar -> addAction(hexagon);
    fileToolBar -> addAction(freehand);
    fileToolBar -> addAction(text);
    fileToolBar -> addAction(colorFill);
    fileToolBar -> addAction(colorBdr);
    fileToolBar -> addAction(widthBdr);
}

void MainWindow::createMenus(){
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu -> addAction(newFile);
    fileMenu -> addAction(openFile);
    fileMenu -> addAction(saveFile);
    fileMenu -> addAction(saveAsFile);
    fileMenu -> addAction(exitApp);

    fileMenu2 = menuBar()->addMenu(tr("&Edit"));
    fileMenu2 -> addAction(cut);
    fileMenu2 -> addAction(copy);
    fileMenu2 -> addAction(paste);
    fileMenu2 -> addSeparator();
    fileMenu2 -> addAction(undo);
    fileMenu2 -> addAction(redo);
}

void MainWindow::createActions(){
    select = new QAction(tr("&Select"), this);
    select -> setCheckable(true);
    rectangle = new QAction(tr("&Rectangle"), this);
    rectangle -> setCheckable(true);
    roundedRectangle = new QAction(tr("&Rounded Rectangle"), this);
    roundedRectangle -> setCheckable(true);
    circle = new QAction(tr("&Circle"), this);
    circle -> setCheckable(true);
    line = new QAction(tr("&Line"), this);
    line -> setCheckable(true);
    hexagon = new QAction(tr("&Hexagon"), this);
    hexagon -> setCheckable(true);
    freehand = new QAction(tr("&Freehand"), this);
    freehand -> setCheckable(true);
    text = new QAction(tr("&Text"), this);
    text -> setCheckable(true);
    colorFill = new QAction(tr("Fill Color"), this);
    colorBdr = new QAction(tr("Border Color"), this);
    widthBdr = new QAction(tr("Border Width"), this);

    toolActionGroup = new QActionGroup(this);
    toolActionGroup -> addAction(select);
    toolActionGroup -> addAction(rectangle);
    toolActionGroup -> addAction(roundedRectangle);
    toolActionGroup -> addAction(circle);
    toolActionGroup -> addAction(line);
    toolActionGroup -> addAction(hexagon);
    toolActionGroup -> addAction(freehand);
    toolActionGroup -> addAction(text);

    newFile = new QAction(tr("&New File"), this);
    openFile = new QAction(tr("&Open File"), this);
    saveFile = new QAction(tr("&Save File"), this);
    saveAsFile = new QAction(tr("Save &As File"), this);
    exitApp = new QAction(tr("E&xit Application"), this);

    cut = new QAction(tr("Cu&t"), this);
    copy = new QAction(tr("&Copy"), this);
    paste = new QAction(tr("&Paste"), this);
    undo = new QAction(tr("&Undo"), this);
    redo = new QAction(tr("&Redo"), this);
}

void MainWindow::connectActions(){
    connect(circle, &QAction::triggered, this, [this](){ canvas -> set_current_tool(3); canvas -> set_current_shape_id(-1);});
    connect(rectangle, &QAction::triggered, this, [this](){ canvas -> set_current_tool(1); canvas -> set_current_shape_id(-1);});
    connect(roundedRectangle, &QAction::triggered, this, [this](){ canvas -> set_current_tool(2); canvas -> set_current_shape_id(-1);});
    connect(line, &QAction::triggered, this, [this](){ canvas -> set_current_tool(4); canvas -> set_current_shape_id(-1);});
    connect(hexagon, &QAction::triggered, this, [this](){ canvas -> set_current_tool(5); canvas -> set_current_shape_id(-1);});
    connect(freehand, &QAction::triggered, this, [this](){ canvas -> set_current_tool(6); canvas -> set_current_shape_id(-1);});
    connect(text, &QAction::triggered, this, [this](){ canvas -> set_current_tool(7); canvas -> set_current_shape_id(-1);});
    connect(select, &QAction::triggered, this, [this](){ canvas -> set_current_tool(0); canvas -> set_current_shape_id(-1);});
    //Text, fill colour and other options won't be clickable but rather would show the palletes - to implement later
    //need to connect file menu actions to their respective slots for functionality
}