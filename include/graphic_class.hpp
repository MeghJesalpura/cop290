#ifndef graphic_class_hpp
#define graphic_class_hpp

#include <iostream>
#include <string>
#include <memory>
#include <QPainter>
#include "point.hpp"

namespace mainSpace{
/*This is the main superclass which will be inherited into the different shapes*/
class GraphicClass{
    protected:
        int id_;
        std::string strokeClr_;
        double strokeWt_;
        std::string fillClr_;
        //this is for the bounding box
        Point position_;//top left corner of the bounding box for the shape
        double width_;
        double height_;
        int tool_;

    public:
        GraphicClass(int m_id, int m_tool, double x = 0, double y = 0, double m_width = 0, double m_height = 0);
        virtual ~GraphicClass() = default;
        
        void set_stroke_clr(std::string m_strokeClr);
        void set_stroke_wt(double m_strokeWt);
        void set_fill_clr(std::string m_newClr);    
        void set_width(double m_width);
        void set_height(double m_height);
        void set_position(double x, double y);//will take in x, y format only
        int get_tool() const;
        std::string get_stroke_clr() const;
        double get_stroke_wt() const;
        std::string get_fill_clr() const;
        double get_width() const;
        double get_height() const;
        QRectF getBoundingBox() const;//to get the bounding box of the shape for selection and resizing purposes

        Point get_position() const;//stores central point for the shape: to be used for move and resize operations
        //move and resize will be shape specific
        virtual std::unique_ptr<GraphicClass> clone() const = 0;//not sure about the parameters this will require : will be used for copy paste undo redo I think  
        virtual std::string to_svg() = 0;
        bool contains_point(const QPoint& point) const;//to check if the point is within the shape or not : will be used for selection of shapes
        virtual void draw(QPainter& painter) = 0;
        int get_id() const;
};
}

#endif