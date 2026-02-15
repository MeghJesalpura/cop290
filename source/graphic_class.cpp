#include "graphic_class.hpp"

namespace mainSpace{
    GraphicClass::GraphicClass(int m_id, int m_tool){
        id_ = m_id;
        width_ = 0;
        height_ = 0;
        position_ = {0,0};
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

    int GraphicClass::get_tool(){
        return tool_;
    }
    std::string GraphicClass::get_stroke_clr(){
        return strokeClr_;
    }
    double GraphicClass::get_stroke_wt(){
        return strokeWt_;
    }
    std::string GraphicClass::get_fill_clr(){
        return fillClr_;
    }
    double GraphicClass::get_width(){
        return width_;
    }
    double GraphicClass::get_height(){
        return height_;
    }
    Point GraphicClass::get_position(){
        return position_;
    }
    int GraphicClass::get_id(){
        return id_;
    }
}