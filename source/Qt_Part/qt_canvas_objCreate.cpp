#include "../../include/Qt_Part/qt_canvas_objCreate.hpp"
#include "../../include/Shapes/circle.hpp"

std::unique_ptr<mainSpace::GraphicClass> objCreate(int tool, const QPoint& start_point, const QPoint& end_point, int tot_id, const std::string& fill_clr, const std::string& bdr_clr, double bdr_wt){
    switch(tool){
        case 1:{
            //rectangle
            break;
        }
        case 2:{
            //rounded rectangle
            break;
        }
        case 3:{
            //circle
            double radius = qMax(qAbs(end_point.x() - start_point.x()), qAbs(end_point.y() - start_point.y())) / 2.0;//using inbuild fns
            auto new_circle = std::make_unique<mainSpace::Circle>((start_point.x() + end_point.x()) / 2, (start_point.y() + end_point.y()) / 2, radius, tot_id);
            new_circle -> set_fill_clr(fill_clr);
            new_circle -> set_stroke_clr(bdr_clr);
            new_circle -> set_stroke_wt(bdr_wt);
            return new_circle;
            break;
        }
        case 4:{
            //line
            break;
        }
        case 5:{
            //hexagon
            break;
        }
        case 6:{
            //freehand
            break;
        }
        default:
            return nullptr;
    }
}