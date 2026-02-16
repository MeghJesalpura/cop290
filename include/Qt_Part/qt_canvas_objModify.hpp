#ifndef qt_canvas_objModify_hpp
#define qt_canvas_objModify_hpp
#include <QPoint>
#include "../point.hpp"
#include "../graphic_class.hpp"
#include "../../include/Shapes/circle.hpp"
#include "../../include/Shapes/rectangle.hpp"
#include "../../include/Shapes/roundedRectangle.hpp"
#include "../../include/Shapes/line.hpp"
#include "../../include/Shapes/hexagon.hpp"
void obj_modify(int tool, const QPoint& start_point, const QPoint& current_point, int mode, mainSpace::GraphicClass* selected_shape);

#endif