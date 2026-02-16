#include "../../include/Qt_Part/qt_canvas_objModify.hpp"
void obj_modify(int tool, const QPoint& start_point, const QPoint& current_point, int mode, mainSpace::GraphicClass* selected_shape){
    switch(tool){
        case 1: {//Rectangle
            if(mode == 0){//move mode
                if(auto* rect_ = dynamic_cast<mainSpace::Rectangle*>(selected_shape)){
                    QPointF shift = current_point - start_point;
                    QPointF pos_new(rect_ -> get_position().x + shift.x(), rect_ -> get_position().y + shift.y());
                    rect_ -> set_position(pos_new.x(), pos_new.y());
                }
            }
            else{//resize mode
                if(auto* rect_ = dynamic_cast<mainSpace::Rectangle*>(selected_shape)){
                    QPointF shift = current_point - start_point;
                    float new_x = rect_ -> get_position().x;
                    float new_y = rect_ -> get_position().y;
                    float width_new;
                    float height_new;
                    if(mode == 1){//top left corner
                        new_x = rect_ -> get_position().x + shift.x();
                        new_y = rect_ -> get_position().y + shift.y();
                        width_new = rect_ -> get_width() - shift.x();
                        height_new = rect_ -> get_height() - shift.y();
                    }
                    else if(mode == 2){//top right corner
                        new_y = rect_ -> get_position().y + shift.y();
                        width_new = rect_ -> get_width() + shift.x();
                        height_new = rect_ -> get_height() - shift.y();
                    }
                    else if(mode == 3){//bottom left corner
                        new_x = rect_ -> get_position().x + shift.x();
                        width_new = rect_ -> get_width() - shift.x();
                        height_new = rect_ -> get_height() + shift.y();
                    }
                    else{//bottom right corner
                        width_new = rect_ -> get_width() + shift.x();
                        height_new = rect_ -> get_height() + shift.y();
                    }
                    rect_ -> set_position(new_x, new_y);
                    rect_ -> set_width(width_new);
                    rect_ -> set_height(height_new);
                }
            }
            break;
        }
        case 2: {//Rounded Rectangle
            if(auto* rect_ = dynamic_cast<mainSpace::RoundedRectangle*>(selected_shape)){
                QPointF shift = current_point - start_point;
                float new_x = rect_ -> get_position().x;
                float new_y = rect_ -> get_position().y;
                float width_new;
                float height_new;
                if(mode == 1){//top left corner
                    new_x = rect_ -> get_position().x + shift.x();
                    new_y = rect_ -> get_position().y + shift.y();
                    width_new = rect_ -> get_width() - shift.x();
                    height_new = rect_ -> get_height() - shift.y();
                }
                else if(mode == 2){//top right corner
                    new_y = rect_ -> get_position().y + shift.y();
                    width_new = rect_ -> get_width() + shift.x();
                    height_new = rect_ -> get_height() - shift.y();
                }
                else if(mode == 3){//bottom left corner
                    new_x = rect_ -> get_position().x + shift.x();
                    width_new = rect_ -> get_width() - shift.x();
                    height_new = rect_ -> get_height() + shift.y();
                }
                else{//bottom right corner
                    width_new = rect_ -> get_width() + shift.x();
                    height_new = rect_ -> get_height() + shift.y();
                }
                rect_ -> set_position(new_x, new_y);
                rect_ -> set_width(width_new);
                rect_ -> set_height(height_new);
            }
            break;
        }
        case 3: {//Circle
            if(mode == 0){//move mode - to ensure that the selected shape is a circle before performing the dynamic_cast
                if(auto* circle_ = dynamic_cast<mainSpace::Circle*>(selected_shape)){
                    QPointF shift = current_point - start_point;
                    mainSpace::Point center_og = circle_ -> get_center();
                    circle_ -> set_center(center_og.x + shift.x(), center_og.y + shift.y());
                    circle_ -> set_position(circle_ -> get_center().x - circle_ -> get_radius(), circle_ -> get_center().y - circle_ -> get_radius());
                }
            }
            else{//resize mode
                if(auto* circle_ = dynamic_cast<mainSpace::Circle*>(selected_shape)){
                    QPointF shift = current_point - QPointF(circle_ -> get_center().x, circle_ -> get_center().y);
                    float radius_new = qMax(qAbs(shift.x()), qAbs(shift.y()));//modelled as in inkscape
                    circle_ -> set_radius(radius_new);
                    circle_ -> set_position(circle_ -> get_center().x - circle_ -> get_radius(), circle_ -> get_center().y - circle_ -> get_radius());
                    circle_ -> set_width(2*circle_ -> get_radius());
                    circle_ -> set_height(2*circle_ -> get_radius());
                }
            }
            break;
        }
        case 4: {//Line
            break;
        }
        case 5: {//Hexagon - LEFT TO IMPLEMENT
            break;
        }
        case 6: {//Freehand - LEFT TO IMPLEMENT
            break;
        }
        default:
            break;
    }
}