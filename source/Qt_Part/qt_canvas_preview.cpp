#include "../../include/Qt_Part/qt_canvas_preview.hpp"
void draw_preview(QPainter& painter, int tool, const QPoint& start_point, const QPoint& current_point, int mode, mainSpace::GraphicClass* selected_shape){
    QPen pen(Qt::DashLine);//just to ensure that preview looks different from final shape
    painter.setPen(pen);
    if(selected_shape != nullptr){
        painter.setBrush(QColor(QString::fromStdString(selected_shape -> get_fill_clr())));
    }
    switch(tool){
        case 1: {//Rectangle
            if(mode == -1){
                painter.drawRect(QRect(start_point, current_point));
            }
            else if(mode == 0){//move mode
                if(auto* rect_ = dynamic_cast<const mainSpace::Rectangle*>(selected_shape)){
                    QPointF shift = current_point - start_point;
                    QPointF pos_new(rect_ -> get_position().x + shift.x(), rect_ -> get_position().y + shift.y());
                    painter.drawRect(QRectF(pos_new, QSizeF(rect_ -> get_width(), rect_ -> get_height())));
                }
            }
            else{//resize mode
                if(auto* rect_ = dynamic_cast<const mainSpace::Rectangle*>(selected_shape)){
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
                    painter.drawRect(QRectF(QPointF(new_x, new_y), QSizeF(width_new, height_new)));
                }
            }
            break;
        }

        case 2: {//Rounded Rectangle
            if(mode == -1){
                painter.drawRoundedRect(QRect(start_point, current_point), 10, 10);
            }
            else if(mode == 0){//move mode
                if(auto* rect_ = dynamic_cast<const mainSpace::RoundedRectangle*>(selected_shape)){
                    QPointF shift = current_point - start_point;
                    QPointF pos_new(rect_ -> get_position().x + shift.x(), rect_ -> get_position().y + shift.y());
                    painter.drawRoundedRect(QRectF(pos_new, QSizeF(rect_ -> get_width(), rect_ -> get_height())), rect_ -> get_corner_radius(), rect_ -> get_corner_radius());
                }
            }
            else{//resize mode
                if(auto* rect_ = dynamic_cast<const mainSpace::RoundedRectangle*>(selected_shape)){
                    QPointF shift = current_point - start_point;
                    float new_x = rect_ -> get_position().x;
                    float new_y = rect_ -> get_position().y;
                    float width_new;
                    float height_new;
                    if(mode >= 1 && mode <= 4){
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
                        painter.drawRoundedRect(QRectF(QPointF(new_x, new_y), QSizeF(width_new, height_new)), rect_ -> get_corner_radius(), rect_ -> get_corner_radius());
                    }
                    else{
                        double handle_y = (rect_ -> get_position().y) + (rect_ -> get_corner_radius());
                        double shift_y = current_point.y() - start_point.y();
                        double new_radius = (rect_ -> get_corner_radius()) - shift_y;
                        new_radius = qMax(new_radius, 0.0);//to ensure that radius does not become negative
                        painter.drawRoundedRect(QRectF(rect_ -> get_position().x, rect_ -> get_position().y, rect_ -> get_width(), rect_ -> get_height()), new_radius, new_radius);
                    }
                }
            }
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
                    QPointF shift = current_point - QPointF(circle_ -> get_center().x, circle_ -> get_center().y);
                    float radius_new = qMax(qAbs(shift.x()), qAbs(shift.y()));//modelled as in inkscape
                    painter.drawEllipse(QPointF(circle_ -> get_center().x, circle_ -> get_center().y), radius_new, radius_new);
                }
            }
            break;
        }
        case 4: {//Line
            if(mode == -1){
                painter.drawLine(start_point, current_point);
            }
            else if(mode == 0){//move mode
                if(auto* line_ = dynamic_cast<const mainSpace::line*>(selected_shape)){
                    QPointF shift = current_point - start_point;
                    QPointF p1_new(line_ -> get_position().x + shift.x(), line_ -> get_position().y + shift.y());
                    QPointF p2_new(line_ -> get_x2() + shift.x(), line_ -> get_y2() + shift.y());
                    painter.drawLine(p1_new, p2_new);
                }
            }
            else{//resize mode
                if(auto* line_ = dynamic_cast<const mainSpace::line*>(selected_shape)){
                    QPointF p1(line_ -> get_position().x, line_ -> get_position().y);
                    QPointF p2(line_ -> get_x2(), line_ -> get_y2());
                    QLineF line_segment(p1, p2);
                    QPointF unit_vector = line_segment.unitVector().p2() - line_segment.unitVector().p1();
                    QPointF shift = current_point - start_point;
                    QPointF shift_along_line = QPointF(unit_vector.x() * (shift.x() * unit_vector.x() + shift.y() * unit_vector.y()), unit_vector.y() * (shift.x() * unit_vector.x() + shift.y() * unit_vector.y()));
                    QPointF p1_new(p1.x() + shift_along_line.x(), p1.y() + shift_along_line.y());
                    QPointF p2_new(p2.x() + shift_along_line.x(), p2.y() + shift_along_line.y());
                    painter.drawLine(p1_new, p2_new);
                }
            }
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