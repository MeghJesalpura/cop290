#include "../../include/Qt_Part/qt_canvas_preview.hpp"

void draw_preview(QPainter& painter, int tool, const QPoint& start_point, const QPoint& current_point){
    QPen pen(Qt::DashLine);//just to ensure that preview looks different from final shape
    painter.setPen(pen);
    switch(tool){
        case 0: {//Rectangle
            painter.drawRect(QRect(start_point, current_point));
            break;
        }

        case 1: {//Rounded Rectangle
            painter.drawRoundedRect(QRect(start_point, current_point), 10, 10);//Need to change this
            break;
        }
        
        case 2: {//Circle
            int radius = qMax(qAbs(current_point.x() - start_point.x()), qAbs(current_point.y() - start_point.y()));//modelled as in inkscape
            painter.drawEllipse(start_point, radius, radius);
            break;
        }

        case 3: {//Line
            painter.drawLine(start_point, current_point);
            break;
        }

        case 4: {//Hexagon - LEFT TO IMPLEMENT
            break;
        }

        case 5: {//Freehand - LEFT TO IMPLEMENT
            break;
        }
    }
}