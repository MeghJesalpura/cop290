#ifndef qt_canvas_preview_hpp
#define qt_canvas_preview_hpp

#include <QPainter>
#include <QPoint>
void draw_preview(QPainter& painter, int tool, const QPoint& start_point, const QPoint& current_point);
#endif