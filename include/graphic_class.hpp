#ifndef graphic_class_hpp
#define graphic_class_hpp

#include <iostream>
#include <string>
#include "point.hpp"

namespace mainSpace{
/*This is the main superclass which will be inherited into the different shapes*/
class GraphicClass{
    protected:
        int id_;
        std::string strokeClr_;
        double strokeWt_;
        std::string fillClr_;
        Point position_;
        double width_;
        double height_;

    public:
        GraphicClass(int m_id);
        virtual ~GraphicClass() = default;
        
        void set_stroke_clr(std::string m_strokeClr);
        void set_stroke_wt(double m_strokeWt);
        void set_fill_clr(std::string m_newClr);
        void set_width(double m_width);
        void set_height(double m_height);
        void set_position(double x, double y);//will take in x, y format only

        std::string get_stroke_clr();
        double get_stroke_wt();
        std::string get_fill_clr();
        double get_width();
        double get_height();

        Point get_position();//stores central point for the shape: to be used for move and resize operations
        virtual void move_shape() = 0;//to be done as per each shape's requirement
        virtual void resize() = 0;//again to be done like move_shape
        virtual std::unique_ptr<GraphicClass> clone() const = 0;//not sure about the parameters this will require : will be used for copy paste undo redo I think  
        virtual std::string to_svg() = 0;

        virtual void draw(QPainter& painter) = 0;
};
}

#endif