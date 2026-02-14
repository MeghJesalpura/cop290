#include "qt_canvas.hpp"
#include <QPainter>
#include <QMouseEvent>

Canvas::Canvas(QWidget* parent) : QWidget(parent){
    //need to call the base constructor of QWidget
    //setAttribute(Qt::WA_StaticContents);
    current_shape_id = -1; //initially no shape is selected
    state_fill_clr = "#FFFFFF"; //default fill color is white
    state_bdr_clr = "#000000"; //default border color is black
    state_bdr_wt = 1.0; //default border width is 1.0
    current_tool = -1; //initially no tool is selected
    mouse_pressed = false;
    setMouseTracking(true); //to track mouse movements even when no button is pressed
}
void Canvas::set_fill_clr(std::string m_fill_clr){
    state_fill_clr = m_fill_clr;
}
void Canvas::set_bdr_clr(std::string m_bdr_clr){
    state_bdr_clr = m_bdr_clr;
}
void Canvas::set_bdr_wt(double m_bdr_wt){
    state_bdr_wt = m_bdr_wt;
}
void Canvas::paintEvent(QPaintEvent* event){
    QPainter painter(this);
    //Here we will iterate through the list of shapes and call their draw method to render them on the canvas
}
void Canvas::mousePressEvent(QMouseEvent* event){
    if(event()->button() == Qt::LeftButton){
        mouse_pressed = true;
        last_point = event()->pos();
    }
}
void Canvas::mouseMoveEvent(QMouseEvent* event){
    if(mouse_pressed){
        update(); //repaint the canvas to show the shape being drawn/moved
    }
}
void Canvas::mouseReleaseEvent(QMouseEvent* event){
    if(event()->button() == Qt::LeftButton){
        mouse_pressed = false;
        
    }
}