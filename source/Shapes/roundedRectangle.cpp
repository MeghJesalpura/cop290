#include "../../include/Shapes/roundedRectangle.hpp"
#include <string>
#include <sstream>
namespace mainSpace{
    RoundedRectangle::RoundedRectangle(double x, double y, double width, double height, int m_id) : GraphicClass(m_id, 2, x, y, width, height){
        corner_radius_ = 10;
    }
    void RoundedRectangle::move_shape(double x, double y){
        position_.x = x;
        position_.y = y;
    }
    void RoundedRectangle::resize(double new_width, double new_height){
        width_ = new_width;
        height_ = new_height;
    }
    void RoundedRectangle::set_width(double m_width){
        width_ = m_width;
    }
    void RoundedRectangle::set_height(double m_height){
        height_ = m_height;
    }
    double RoundedRectangle::get_width() const{
        return width_;
    }
    double RoundedRectangle::get_height() const{
        return height_;
    }
    std::unique_ptr<GraphicClass> RoundedRectangle::clone() const{
        return std::make_unique<RoundedRectangle>(*this);
    }
    std::string RoundedRectangle::to_svg(){
        std::stringstream ss;
        ss << "<rect x=\"" << position_.x
        << "\" y=\"" << position_.y
        << "\" width=\"" << width_
        << "\" height=\"" << height_
        << "\" rx=\"" << corner_radius_
        << "\" ry=\"" << corner_radius_
        << "\" stroke=\"" << strokeClr_
        << "\" stroke-width=\"" << strokeWt_
        << "\" fill=\"" << fillClr_ << "\" />";
        return ss.str();
    }
    void RoundedRectangle::draw(QPainter& painter){
        QPen pen(QColor(QString::fromStdString(strokeClr_)), strokeWt_);
        painter.setPen(pen);
        painter.setBrush(QColor(QString::fromStdString(fillClr_)));
        painter.drawRoundedRect(QRectF(position_.x, position_.y, width_, height_), corner_radius_, corner_radius_);
    }
    int RoundedRectangle::get_mode(const QPoint& point) const{
        //if it is near one of the corners then it is in resize mode else move mode : modelled as in inkscape
        if(point.x() >= position_.x - 20 && point.x() <= position_.x + 20 && point.y() >= position_.y - 20 && point.y() <= position_.y + 20){
            return 1;//resize mode - top left
        }
        else if(point.x() >= position_.x + width_ - 20 && point.x() <= position_.x + width_ + 20 && point.y() >= position_.y - 20 && point.y() <= position_.y + 20){
            return 2;//resize mode - top right
        }
        else if(point.x() >= position_.x - 20 && point.x() <= position_.x + 20 && point.y() >= position_.y + height_ - 20 && point.y() <= position_.y + height_ + 20){
            return 3;//resize mode - bottom left
        }
        else if(point.x() >= position_.x + width_ - 20 && point.x() <= position_.x + width_ + 20 && point.y() >= position_.y + height_ - 20 && point.y() <= position_.y + height_ + 20){
            return 4;//resize mode - bottom right
        }
        else{
            return 0;//move mode
        }
    }
}