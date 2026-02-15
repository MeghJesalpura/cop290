#ifndef qt_canvas_preview_hpp
#define qt_canvas_preview_hpp

#include <QPainter>
#include <QPoint>
#include "../point.hpp"
void draw_preview(QPainter& painter, int tool, const QPoint& start_point, const QPoint& current_point, int mode = -1, const GraphicClass* selected_shape = nullptr);//mode is only required for select tool to determine whether we are in move mode or resize mode
#endif