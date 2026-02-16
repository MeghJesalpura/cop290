#include "../../include/DocManager/shape_positioner.hpp"
#include "../../include/Shapes/circle.hpp"
void ShapePositioner::move_shape_to(mainSpace::GraphicClass* shape, double x, double y){
    if(shape == nullptr){
        return;
    }
    if(auto* circle_ = dynamic_cast<mainSpace::Circle*>(shape)){
        double radius_ = circle_ -> get_radius();
        circle_ -> move_shape(x + radius_, y + radius_);
    }
    //extend here
}