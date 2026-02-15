#ifndef qt_canvas_objCreate_hpp
#define qt_canvas_objCreate_hpp
#include "../graphic_class.hpp"
#include <memory>
std::unique_ptr<mainSpace::GraphicClass> objCreate(int tool, const QPoint& start_point, const QPoint& end_point, int& tot_id, const std::string& fill_clr, const std::string& bdr_clr, double bdr_wt);
#endif