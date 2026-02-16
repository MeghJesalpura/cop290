#include "../../include/Qt_Part/qt_canvas.hpp"

Canvas::Canvas(QWidget* parent) : QWidget(parent){
    //need to call the base constructor of QWidget
    //setAttribute(Qt::WA_StaticContents);
    tot_id = 0;
    state_fill_clr = "#FFFFFF"; //default fill color is white
    state_bdr_clr = "#000000"; //default border color is black
    state_bdr_wt = 1.0; //default border width is 1.0
    current_tool = -1; //initially no tool is selected
    current_mode = 0; //initially in move mode
    mouse_pressed = false;
    setMouseTracking(true); //to track mouse movements even when no button is pressed
    doc_manager = std::make_unique<DocManager>(); //initializing the doc_manager
}
DocManager* Canvas::get_doc_manager(){
    return doc_manager.get();
}
void Canvas::cut(int id){
    doc_manager -> cut_shape(id);
    update();
}
void Canvas::copy(int id){
    doc_manager -> copy_shape(id);
}
void Canvas::paste_at_cursor(){
    QPoint cursor_pos = mapFromGlobal(QCursor::pos());
    doc_manager -> paste_shape(cursor_pos.x(), cursor_pos.y());
    update();
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
    doc_manager -> set_current_shape_id(m_shape_id);
}
void Canvas::paintEvent(QPaintEvent* event){
    QPainter painter(this);
    //Here we will iterate through the list of shapes and call their draw method to render them on the canvas
    painter.setRenderHint(QPainter::Antialiasing); //inbuilt method to make the shapes look smoother
    for(auto& render_shape: doc_manager -> get_all_shapes()){
        if(render_shape -> get_id() != doc_manager -> get_current_shape_id() || !mouse_pressed){//to avoid drawing the shape being currently drawn/moved in the list of shapes
            render_shape->draw(painter);//rendering all the shapes
        }
    }
    if(doc_manager -> get_current_shape_id() != -1 && doc_manager -> get_selected_shape(doc_manager -> get_current_shape_id()) != nullptr){
        mainSpace::GraphicClass* selected_shape = doc_manager -> get_selected_shape(doc_manager -> get_current_shape_id());
        QRectF bounds = selected_shape -> getBoundingBox();
        painter.setPen(QPen(Qt::white, 1, Qt::DashLine));
        painter.setBrush(Qt::NoBrush);
        painter.drawRect(bounds);
    }
    if(mouse_pressed && (current_tool == 0 || current_tool == -1)){
        if(doc_manager -> get_current_shape_id() != -1 && doc_manager -> get_selected_shape(doc_manager -> get_current_shape_id()) != nullptr){
            mainSpace::GraphicClass* selected_shape = doc_manager -> get_selected_shape(doc_manager -> get_current_shape_id());
            if(current_mode != 0){//resize mode
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
            doc_manager -> set_current_shape_id(-1);
            //right now going in reverse order - but later will implement Z axis based implementation to select topmost shape
            bool flag_got = false;
            auto& lshapes = doc_manager -> get_all_shapes_mutable();
            for(auto it = lshapes.rbegin(); it != lshapes.rend(); it++){
                if((*it) -> contains_point(event -> pos())){//contains_point is a method in the GraphicClass
                    flag_got = true;
                    mainSpace::GraphicClass* temp_ptr = it -> get();
                    if(auto* circle_ = dynamic_cast<mainSpace::Circle*>(temp_ptr)){
                        current_mode = circle_ -> get_mode(event -> pos());
                    }
                    else if(auto* rect_ = dynamic_cast<mainSpace::Rectangle*>(temp_ptr)){
                        current_mode = rect_ -> get_mode(event -> pos());
                    }
                    else if(auto* rrect_ = dynamic_cast<mainSpace::RoundedRectangle*>(temp_ptr)){
                        current_mode = rrect_ -> get_mode(event -> pos());
                    }
                    else if(auto* line_ = dynamic_cast<mainSpace::line*>(temp_ptr)){
                        current_mode = line_ -> get_mode(event -> pos());
                    }
                    doc_manager -> set_current_shape_id((*it) -> get_id());
                    break;
                }
            }
            if(flag_got == false){
                doc_manager -> set_current_shape_id(-1);
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
            if(doc_manager -> get_current_shape_id() != -1 && doc_manager -> get_selected_shape(doc_manager -> get_current_shape_id()) != nullptr){
                mainSpace::GraphicClass* selected_shape = doc_manager -> get_selected_shape(doc_manager -> get_current_shape_id());    
                obj_modify(selected_shape -> get_tool(), last_point, mapFromGlobal(QCursor::pos()), current_mode, selected_shape);
            }
        }
        else if(current_tool >= 1 && current_tool <= 6){
            doc_manager -> add_shape(objCreate(current_tool, last_point, event->pos(), doc_manager -> get_new_id(), state_fill_clr, state_bdr_clr, state_bdr_wt));
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