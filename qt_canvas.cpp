#include "qt_canvas.hpp"
#include <QPainter>
#include <QMouseEvent>

Canvas::Canvas(QWidget* parent) : QWidget(parent) {
    //need to call the base constructor of QWidget
    setAttribute(Qt::WA_StaticContents);
}
    
void Canvas::paintEvent(QPaintEvent* event) {
}

void Canvas::mousePressEvent(QMouseEvent* event) {
}

void Canvas::mouseMoveEvent(QMouseEvent* event) {
}

void Canvas::mouseReleaseEvent(QMouseEvent* event) {
}