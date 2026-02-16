#include "../../include/DocManager/shape_positioner.hpp"
#include "../../include/Shapes/circle.hpp"
#include "../../include/Shapes/rectangle.hpp"
#include "../../include/Shapes/roundedRectangle.hpp"
#include "../../include/Shapes/line.hpp"
#include "../../include/Shapes/hexagon.hpp"
void ShapePositioner::move_shape_to(mainSpace::GraphicClass* shape, double x, double y){
    if(shape == nullptr){
        return;
    }
    if(auto* circle_ = dynamic_cast<mainSpace::Circle*>(shape)){
        double radius_ = circle_ -> get_radius();
        circle_ -> move_shape(x + radius_, y + radius_);
    }
    else if(auto* rect_ = dynamic_cast<mainSpace::Rectangle*>(shape)){
        rect_ -> move_shape(x, y);
    }
    else if(auto* rrect_ = dynamic_cast<mainSpace::RoundedRectangle*>(shape)){
        rrect_ -> move_shape(x, y);
    }
    else if(auto* line_ = dynamic_cast<mainSpace::line*>(shape)){
        line_ -> move_shape(x, y);
    }
    //extend here
}