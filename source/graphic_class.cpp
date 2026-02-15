#include "graphic_class.hpp"

namespace mainSpace{
    GraphicClass::GraphicClass(int m_id, int m_tool, double x, double y, double m_width, double m_height){
        id_ = m_id;
        width_ = m_width;
        height_ = m_height;
        position_ = {x,y};
        strokeClr_ = "black";
        strokeWt_ = 1;
        fillClr_ = "white";
        tool_ = m_tool;
    }

    void GraphicClass::set_stroke_clr(std::string m_strokeClr){
        strokeClr_ = m_strokeClr;
    }
    void GraphicClass::set_stroke_wt(double m_strokeWt){
        strokeWt_ = m_strokeWt;
    }
    void GraphicClass::set_fill_clr(std::string m_newClr){
        fillClr_ = m_newClr;
    }
    void GraphicClass::set_width(double m_width){
        width_ = m_width;
    }
    void GraphicClass::set_height(double m_height){
        height_ = m_height;
    }
    void GraphicClass::set_position(double x, double y){
        position_ = {x,y};
    }
    bool GraphicClass::contains_point(const QPoint& point) const{
        if(point.x() >= position_.x && point.x() <= position_.x + width_ && point.y() <= position_.y && point.y() >= position_.y - height_){
            return true;
        }
        return false;
    }

    int GraphicClass::get_tool() const{
        return tool_;
    }
    std::string GraphicClass::get_stroke_clr() const{
        return strokeClr_;
    }
    double GraphicClass::get_stroke_wt() const{
        return strokeWt_;
    }
    std::string GraphicClass::get_fill_clr() const{
        return fillClr_;
    }
    double GraphicClass::get_width() const{
        return width_;
    }
    double GraphicClass::get_height() const{
        return height_;
    }
    Point GraphicClass::get_position() const{
        return position_;
    }
    int GraphicClass::get_id() const{
        return id_;
    }
    QRectF GraphicClass::getBoundingBox() const{
        return QRectF(position_.x, position_.y, position_.x + width_, position_.y - height_);
    }
}