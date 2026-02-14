#ifndef graphic_class_hpp
#define graphic_class_hpp

#include <iostream>
#include <string>
#include "point.hpp"

namespace mainObj{
/*This is the main superclass which will be inherited into the different shapes*/
class GraphicClass{
    protected:
        int id_;
        string strokeClr_;
        double strokeWt_;
        string fillClr_;
        Point position_;
        double width_;
        double height_;

    public:
        GraphicClass();
        virtual ~GraphicClass() = default;
        
        void set_stroke_clr(string m_strokeClr);
        void set_stroke_wt(double m_strokeWt);
        void set_fill_clr(string m_newClr);
        void set_width(double m_width);
        void set_height(double m_height);
        void set_position(double x, double y);//will take in x, y format only

        string get_stroke_clr();
        double get_stroke_wt();
        string get_fill_clr();
        double get_width();
        double get_height();

        Point get_position();//stores central point for the shape: to be used for move and resize operations
        virtual void move_shape();//to be done as per each shape's requirement
        virtual void resize();//again to be done like move_shape
        void clone();//not sure about the parameters this will require : will be used for copy paste undo redo I think  
};
}

#endif