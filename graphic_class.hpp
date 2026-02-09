#ifndef graphic_class.hpp
#define graphic_class.hpp

#include <iostream>
#include <string>

/*This is the main superclass which will be inherited into the different shapes*/
class GraphicClass{
    protected:
        int id_;
        int strokeClr_;
        int strokeWt_;
        int fillClr_;
        int boundLX_;
        int boundLY_;
        int boundRX_;
        int boundRY_; 

    public:
        GraphicClass();
        ~GraphicClass();
        void resize(int m_factor);
        void change_stroke_clr(int m_strokeClr);
        void change_stroke_wt(int m_strokeWt);
        void change_fill_clr(int m_newClr);
        void move_shape(int m_LX, int m_LY, int m_RX, int m_RY);
        void clone();//not sure about the parameters this will require
        
};

#endif