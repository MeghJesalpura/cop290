#include "../../include/Shapes/line.hpp"
#include <string>
#include <sstream>
#include "QLineF"
#include "QPointF"
namespace mainSpace{
    line::line(double x1, double y1, double x2, double y2, int m_id) : GraphicClass(x1, y1, m_id), x2(x2), y2(y2){
        //constructor to initialize the line with its endpoints and id
    }
    void line::move_shape(double x, double y){
        double shift_x = x - get_position().x;
        double shift_y = y - get_position().y;
        set_position(x, y);
        x2 += shift_x;
        y2 += shift_y;
    }
    void line::resize(double new_x2, double new_y2){
        x2 = new_x2;
        y2 = new_y2;
    }
    std::unique_ptr<GraphicClass> line::clone() const{
        return std::make_unique<line>(*this);
    }
    std::string line::to_svg(){
        std::stringstream ss;
        ss << "<line x1=\"" << get_position().x
        << "\" y1=\"" << get_position().y
        << "\" x2=\"" << x2
        << "\" y2=\"" << y2
        << "\" stroke=\"" << get_stroke_clr()
        << "\" stroke-width=\"" << get_stroke_wt() << "\" />";
        return ss.str();
    }
    void line::draw(QPainter& painter){
        QPen pen(QColor(QString::fromStdString(get_stroke_clr())), get_stroke_wt());
        painter.setPen(pen);
        painter.drawLine(QPointF(get_position().x, get_position().y), QPointF(x2, y2));
    }
    int line::get_mode(const QPoint& point) const{
        const double threshold = 5.0;
        QLineF line_segment(QPointF(get_position().x, get_position().y), QPointF(x2, y2));
        if (QLineF(line_segment.p1(), point).length() <= threshold || QLineF(line_segment.p2(), point).length() <= threshold) {
            return 0; 
        }
        else{
            return 1; //resize mode otherwise
        }
    }
    void line::set_x2(double m_x2){
        x2 = m_x2;
    }
    void line::set_y2(double m_y2){
        y2 = m_y2;
    }
    double line::get_x2() const{
        return x2;
    }
    double line::get_y2() const{
        return y2;
    }
}