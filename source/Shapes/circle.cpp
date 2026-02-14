#include "circle.hpp"
#include <string>
#include <sstream>

namespace mainSpace{
    Circle::Circle(Point& center, double m_radius, int m_id) : GraphicClass(m_id), center_(center), radius_(m_radius) {}
    void Circle::move_shape(double x, double y){
        center_.x = x;
        center_.y = y;
    }
    void Circle::resize(double new_radius){
        radius_ = new_radius;
    }
    void Circle::set_radius(double m_radius){
        radius_ = m_radius;
    }
    double Circle::get_radius(){
        return radius_;
    }
    virtual std::unique_ptr<GraphicClass> Circle::clone() const{
        return std::make_unique<Circle>(*this);
    }
    virtual std::string Circle::to_svg(){
        std::stringstream ss;
        ss << "<circle cx=\"" << center_.x 
        << "\" cy=\"" << center_.y 
        << "\" r=\"" << radius_ 
        << "\" stroke=\"" << strokeClr_ 
        << "\" stroke-width=\"" << strokeWt_ 
        << "\" fill=\"" << fillClr_ << "\" />";
        return ss.str();
    }
    virtual void Circle::draw(QPainter& painter){
        QPen pen(QColor(QString::fromStdString(strokeClr_)), strokeWt_);
        painter.setPen(pen);
        painter.setBrush(QColor(QString::fromStdString(fillClr_)));
        painter.drawEllipse(QPointF(center_.x, center_.y), radius_, radius_);
    }
}