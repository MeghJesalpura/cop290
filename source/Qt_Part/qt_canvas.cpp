#include "../../include/Qt_Part/qt_canvas.hpp"
#include "../../include/Qt_Part/qt_canvas_preview.hpp"
#include "../../include/Qt_Part/qt_canvas_objCreate.hpp"
#include "../../include/Qt_Part/qt_canvas_objModify.hpp"
#include <QPainter>
#include <QMouseEvent>
#include "../../include/Shapes/circle.hpp"
#include "../../include/graphic_class.hpp"


Canvas::Canvas(QWidget* parent) : QWidget(parent){
    //need to call the base constructor of QWidget
    //setAttribute(Qt::WA_StaticContents);
    current_shape_id = -1; //initially no shape is selected
    tot_id = 0;
    state_fill_clr = "#FFFFFF"; //default fill color is white
    state_bdr_clr = "#000000"; //default border color is black
    state_bdr_wt = 1.0; //default border width is 1.0
    current_tool = -1; //initially no tool is selected
    current_mode = 0; //initially in move mode
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
void Canvas::set_current_tool(int m_tool){
    current_tool = m_tool;
}
void Canvas::set_current_shape_id(int m_shape_id){
    current_shape_id = m_shape_id;
}
void Canvas::paintEvent(QPaintEvent* event){
    QPainter painter(this);
    //Here we will iterate through the list of shapes and call their draw method to render them on the canvas
    painter.setRenderHint(QPainter::Antialiasing); //inbuilt method to make the shapes look smoother
    for(auto& render_shape: lshapes){
        if(render_shape -> get_id() != current_shape_id)
            render_shape->draw(painter);//rendering all the shapes
    }

    if(mouse_pressed && (current_tool == 0 || current_tool == -1)){
        if(current_shape_id != -1 && selected_shape != nullptr){
            QRectF bounds = selected_shape -> getBoundingBox();
            painter.setPen(QPen(Qt::white, 1, Qt::DashLine));
            painter.setBrush(Qt::NoBrush);
            painter.drawRect(bounds);
            if(current_mode == 1){//resize mode
                draw_preview(painter, selected_shape -> get_tool(), last_point, mapFromGlobal(QCursor::pos()), current_mode, selected_shape);
            }
            else{//move mode
                draw_preview(painter, selected_shape -> get_tool(), last_point, mapFromGlobal(QCursor::pos()), current_mode, selected_shape);
            }
        }
    }
    if(mouse_pressed && (current_tool >= 1 && current_tool <= 8)){
        if(current_tool >= 1 && current_tool <= 6){
            painter.setPen(QPen(QColor(QString::fromStdString(state_bdr_clr)), state_bdr_wt));
            painter.setBrush(QColor(QString::fromStdString(state_fill_clr)));
            draw_preview(painter, current_tool, last_point, mapFromGlobal(QCursor::pos()), -1, nullptr);//mapFromGlobal is to shift coordinates relative to 
            //our widget instead of the entire screen
        }
        else if(current_tool == 7){
            //freehand tool
        }
        else if(current_tool == 8){
            //text tool
        }
    }
}
void Canvas::mousePressEvent(QMouseEvent* event){
    if(event->button() == Qt::LeftButton){
        mouse_pressed = true;
        last_point = event->pos();
        if(current_tool == 0 || current_tool == -1){
            selected_shape = nullptr;
            //right now going in reverse order - but later will implement Z axis based implementation to select topmost shape
            bool flag_got = false;
            for(auto it = lshapes.rbegin(); it != lshapes.rend(); it++){
                if((*it) -> contains_point(event -> pos())){//contains_point is a method in the GraphicClass
                    flag_got = true;
                    mainSpace::GraphicClass* temp_ptr = it -> get();
                    if(auto* circle_ = dynamic_cast<mainSpace::Circle*>(temp_ptr)){
                        current_mode = circle_ -> get_mode(event -> pos());
                    }
                    current_shape_id = (*it) -> get_id();
                    selected_shape = temp_ptr;//storing a raw pointer to the selected shape
                    break;
                }
            }
            if(flag_got == false){
                current_shape_id = -1;
            }
        }
    }
}
void Canvas::mouseMoveEvent(QMouseEvent* event){
    if(mouse_pressed){
        update(); //schedules an event to repaint the canvas to show the shape being drawn/moved
    }
}
void Canvas::mouseReleaseEvent(QMouseEvent* event){
    if(event->button() == Qt::LeftButton){
        mouse_pressed = false;
        //need to add new shape object here
        if(current_tool == 0 || current_tool == -1){
            if(current_shape_id != -1 && selected_shape != nullptr){
                current_shape_id = -1;
                if(current_mode == 0){//resize mode
                    obj_modify(selected_shape -> get_tool(), last_point, mapFromGlobal(QCursor::pos()), current_mode, selected_shape);
                }
                else{//move mode
                    obj_modify(selected_shape -> get_tool(), last_point, mapFromGlobal(QCursor::pos()), current_mode, selected_shape);
                }
            }
        }
        else if(current_tool >= 1 && current_tool <= 6){
            lshapes.push_back(objCreate(current_tool, last_point, event->pos(), tot_id, state_fill_clr, state_bdr_clr, state_bdr_wt));
        }
        else if(current_tool == 7){
            //freehand tool
        }
        else if(current_tool == 8){
            //text tool
        }
        update();
    }
}