#include "../../include/Qt_Part/qt_canvas_objCreate.hpp"
#include "../../include/Shapes/circle.hpp"

std::unique_ptr<mainSpace::GraphicClass> objCreate(int tool, const QPoint& start_point, const QPoint& end_point, int& tot_id){
    switch(tool){
        case 0:{
            //rectangle
            break;
        }
        case 1:{
            //rounded rectangle
            break;
        }
        case 2:{
            //circle
            double radius = qMax(qAbs(end_point.x() - start_point.x()), qAbs(end_point.y() - start_point.y())) / 2.0;//using inbuild fns
            auto new_circle = std::make_unique<mainSpace::Circle>(start_point.x(), start_point.y(), radius, tot_id);
            tot_id++;
            return new_circle;
        }
        case 3:{
            //line
            break;
        }
        case 4:{
            //hexagon
            break;
        }
        case 5:{
            //freehand
            break;
        }
    }
}