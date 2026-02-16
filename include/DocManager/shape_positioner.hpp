#ifndef shape_positioner_hpp
#define shape_positioner_hpp
#include "../graphic_class.hpp"
#include <memory>

class ShapePositioner{
    public:
        static void move_shape_to(mainSpace::GraphicClass* shape, double x, double y);
};

#endif