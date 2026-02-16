#include "../../include/Shapes/circle.hpp"
#include <string>
#include <sstream>
#include <cmath>
namespace mainSpace{
    Circle::Circle(double center_x, double center_y, double m_radius, int m_id) : GraphicClass(m_id, 3, center_x - m_radius, center_y - m_radius, 2.0*m_radius, 2.0*m_radius){
        center_.x = center_x;
        center_.y = center_y;
        radius_ = m_radius;
    } 
    void Circle::move_shape(double x, double y){
        center_.x = x;
        center_.y = y;
        position_.x = x - radius_;
        position_.y = y - radius_;
    }
    void Circle::resize(double new_radius){
        radius_ = new_radius;
        position_.x = center_.x - radius_;
        position_.y = center_.y - radius_;
        width_ = 2*radius_;
        height_ = 2*radius_;
    }
    void Circle::set_radius(double m_radius){
        radius_ = m_radius;
    }
    double Circle::get_radius() const{
        return radius_;
    }
    std::unique_ptr<GraphicClass> Circle::clone() const{
        return std::make_unique<Circle>(*this);
    }
    std::string Circle::to_svg(){
        std::stringstream ss;
        ss << "<circle cx=\"" << center_.x 
        << "\" cy=\"" << center_.y 
        << "\" r=\"" << radius_ 
        << "\" stroke=\"" << strokeClr_ 
        << "\" stroke-width=\"" << strokeWt_ 
        << "\" fill=\"" << fillClr_ << "\" />";
        return ss.str();
    }
    void Circle::draw(QPainter& painter){
        QPen pen(QColor(QString::fromStdString(strokeClr_)), strokeWt_);
        painter.setPen(pen);
        painter.setBrush(QColor(QString::fromStdString(fillClr_)));
        painter.drawEllipse(QPointF(center_.x, center_.y), radius_, radius_);
    }
    int Circle::get_mode(const QPoint& point) const{
        double delx = point.x() - center_.x;
        double dely = point.y() - center_.y;
        double dist = sqrt(delx*delx + dely*dely);
        if(dist <= (1.1*radius_ + strokeWt_/2) && dist >= (0.9*radius_ - strokeWt_/2)){
            return 1;//resize mode
        }
        else{
            return 0;//move mode
        }
    }
    Point Circle::get_center() const{
        return center_;
    }
    void Circle::set_center(double x, double y){
        center_.x = x;
        center_.y = y;
    }
}