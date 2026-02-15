#include "../../include/Qt_Part/qt_canvas_objModify.hpp"
#include "../../include/Shapes/circle.hpp"
#include "../../include/graphic_class.hpp"

void obj_modify(int tool, const QPoint& start_point, const QPoint& current_point, int mode, mainSpace::GraphicClass* selected_shape){
    switch(tool){
        case 1: {//Rectangle
            break;
        }
        case 2: {//Rounded Rectangle
            break;
        }
        case 3: {//Circle
            if(mode == 0){//move mode - to ensure that the selected shape is a circle before performing the dynamic_cast
                if(auto* circle_ = dynamic_cast<mainSpace::Circle*>(selected_shape)){
                    QPointF shift = current_point - start_point;
                    mainSpace::Point center_og = circle_ -> get_center();
                    circle_ -> set_center(center_og.x + shift.x(), center_og.y + shift.y());
                }
            }
            else{//resize mode
                if(auto* circle_ = dynamic_cast<mainSpace::Circle*>(selected_shape)){
                    QPointF shift = current_point - start_point;
                    float radius_og = circle_ -> get_radius();
                    float radius_new = radius_og + qMax(shift.x(), shift.y());//modelled as in inkscape
                    circle_ -> set_radius(radius_new);
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