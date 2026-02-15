#include "../../include/Qt_Part/qt_call.hpp"
#include <QColorDialog>
#include <QInputDialog>
#include <QPixmap>

void DialogHelpers::show_brdr_clr_dialog(MainWindow* main_window, Canvas* canvas, QAction* colorBdr){
    QColor color = QColorDialog::getColor(Qt::black, main_window, "Select Border Color");
    if(color.isValid()){
        canvas -> set_bdr_clr(color.name().toStdString());//converting to a normal string from a QString
        QPixmap pixmap(16, 16);
        pixmap.fill(color);
        colorBdr -> setIcon(QIcon(pixmap));//for visual feedback
        colorBdr -> setText("Border Color");
    }
}

void DialogHelpers::show_fill_clr_dialog(MainWindow* main_window, Canvas* canvas, QAction* colorFill){
    QColor color = QColorDialog::getColor(Qt::white, main_window, "Select Fill Color");
    if(color.isValid()){
        canvas -> set_fill_clr(color.name().toStdString());//converting to a normal string from a QString
        QPixmap pixmap(16, 16);
        pixmap.fill(color);
        colorFill -> setIcon(QIcon(pixmap));//for visual feedback
        colorFill -> setText("Fill Color");
    }
}

void DialogHelpers::show_brdr_wt_dialog(MainWindow* main_window, Canvas* canvas){
    bool checker;
    int width = QInputDialog::getInt(main_window, "Border Width", "Enter Border Width:", 1, 1, 20, 1, &checker);
    if(checker){
        canvas -> set_bdr_wt(width);
    }
}