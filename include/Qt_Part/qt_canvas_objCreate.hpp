#ifndef qt_canvas_objCreate_hpp
#define qt_canvas_objCreate_hpp
#include "../mainSpace/GraphicClass.hpp"
#include <memory>
std::unique_ptr<mainSpace::GraphicClass> objCreate(int tool, const QPoint& start_point, const QPoint& end_point){};
#endif