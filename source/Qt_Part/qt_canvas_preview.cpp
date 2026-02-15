#include "../../include/Qt_Part/qt_canvas_preview.hpp"
#include "../../include/Shapes/circle.hpp"
#include "../../include/graphic_class.hpp"
void draw_preview(QPainter& painter, int tool, const QPoint& start_point, const QPoint& current_point, int mode, mainSpace::GraphicClass* selected_shape){
    QPen pen(Qt::DashLine);//just to ensure that preview looks different from final shape
    painter.setPen(pen);
    switch(tool){
        case 1: {//Rectangle
            painter.drawRect(QRect(start_point, current_point));
            break;
        }

        case 2: {//Rounded Rectangle
            painter.drawRoundedRect(QRect(start_point, current_point), 10, 10);//Need to change this
            break;
        }
        case 3: {//Circle
            if(mode == -1){
                float radius_ = qMax(qAbs(current_point.x() - start_point.x()), qAbs(current_point.y() - start_point.y())) / 2;//modelled as in inkscape
                QPointF centre_point((start_point.x() + current_point.x()) / 2, (start_point.y() + current_point.y()) / 2);
                painter.drawEllipse(centre_point, radius_, radius_);
            }
            else if(mode == 0){//move mode - to ensure that the selected shape is a circle before performing the dynamic_cast
                if(auto* circle_ = dynamic_cast<const mainSpace::Circle*>(selected_shape)){
                    QPointF shift = current_point - start_point;
                    mainSpace::Point center_og = circle_ -> get_center();
                    QPointF center_new(center_og.x + shift.x(), center_og.y + shift.y());
                    painter.drawEllipse(center_new, circle_ -> get_radius(), circle_ -> get_radius());
                }
            }
            else{//resize mode
                if(auto* circle_ = dynamic_cast<const mainSpace::Circle*>(selected_shape)){
                    QPointF shift = current_point - start_point;
                    float radius_og = circle_ -> get_radius();
                    float radius_new = radius_og + qMax(shift.x(), shift.y());//modelled as in inkscape
                    painter.drawEllipse(QPointF(circle_ -> get_center().x, circle_ -> get_center().y), radius_new, radius_new);
                }
            }
            break;
        }

        case 4: {//Line
            painter.drawLine(start_point, current_point);
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