#include "../../include/Shapes/rectangle.hpp"
#include <string>
#include <sstream>
namespace mainSpace{
    Rectangle::Rectangle(double x, double y, double width, double height, int m_id) : GraphicClass(m_id, 1, x, y, width, height){
        width_r = width;
        height_r = height;
        width_ = width;
        height_ = height;
    }
    void Rectangle::move_shape(double x, double y){
        position_.x = x;
        position_.y = y;
    }
    void Rectangle::resize(double new_width, double new_height){
        width_r = new_width;
        height_r = new_height;
        width_ = new_width;
        height_ = new_height;
    }
    void Rectangle::set_width(double m_width){
        width_r = m_width;
        width_ = m_width;
    }
    void Rectangle::set_height(double m_height){
        height_r = m_height;
        height_ = m_height;
    }
    double Rectangle::get_width() const{
        return width_;
    }
    double Rectangle::get_height() const{
        return height_;
    }
    std::unique_ptr<GraphicClass> Rectangle::clone() const{
        return std::make_unique<Rectangle>(*this);
    }
    std::string Rectangle::to_svg(){
        std::stringstream ss;
        ss << "<rect x=\"" << position_.x
        << "\" y=\"" << position_.y
        << "\" width=\"" << width_r
        << "\" height=\"" << height_r
        << "\" stroke=\"" << strokeClr_
        << "\" stroke-width=\"" << strokeWt_
        << "\" fill=\"" << fillClr_ << "\" />";
        return ss.str();
    }
    void Rectangle::draw(QPainter& painter){
        QPen pen(QColor(QString::fromStdString(strokeClr_)), strokeWt_);
        painter.setPen(pen);
        painter.setBrush(QColor(QString::fromStdString(fillClr_)));
        painter.drawRect(QRectF(position_.x, position_.y, width_r, height_r));
    }
    int Rectangle::get_mode(const QPoint& point) const{
        //if it is near one of the corners then it is in resize mode else move mode : modelled as in inkscape
        if(point.x() >= position_.x - 20 && point.x() <= position_.x + 20 && point.y() >= position_.y - 20 && point.y() <= position_.y + 20){
            return 1;//resize mode - top left
        }
        else if(point.x() >= position_.x + width_r - 20 && point.x() <= position_.x + width_r + 20 && point.y() >= position_.y - 20 && point.y() <= position_.y + 20){
            return 2;//resize mode - top right
        }
        else if(point.x() >= position_.x - 20 && point.x() <= position_.x + 20 && point.y() >= position_.y + height_r - 20 && point.y() <= position_.y + height_r + 20){
            return 3;//resize mode - bottom left
        }
        else if(point.x() >= position_.x + width_r - 20 && point.x() <= position_.x + width_r + 20 && point.y() >= position_.y + height_r - 20 && point.y() <= position_.y + height_r + 20){
            return 4;//resize mode - bottom right
        }
        else{
            return 0;//move mode
        }
    }
}