/* Need to decide the dependencies on what need to be imported */
#ifndef qt_canvas_hpp 
#define qt_canvas_hpp
#include <QWidget>
#include <vector>
#include <memory>
#include "../graphic_class.hpp"
class Canvas : public QWidget {
    Q_OBJECT //this is a macro that is included for functionality of signals and slots in Qt
    private:
        std::string state_fill_clr;
        std::string state_bdr_clr;
        double state_bdr_wt;
        int current_shape_id;
        int tot_id;
        int current_tool; //-1 for none, 0 for Select, 1 for Rectangle, 2 for Rounded Rectangle, ... and so on as per the order in toolbar
        int current_mode; // 0 for move, 1 for resize - only used when current_tool is -1 or 0 i.e. select tool is active
        bool mouse_pressed;
        QPoint last_point; //to keep track of the last point for drawing and moving shapes
        std::vector<std::unique_ptr<mainSpace::GraphicClass>> lshapes; //list of all the shapes on the canvas
        mainSpace::GraphicClass* selected_shape;

    public:
        Canvas(QWidget* parent = nullptr);
        //now need to override some standard methods
        void set_fill_clr(std::string m_fill_clr);
        void set_bdr_clr(std::string m_bdr_clr);
        void set_bdr_wt(double m_bdr_wt);
        void set_current_tool(int m_tool);
        void set_current_shape_id(int m_shape_id);
        void paintEvent(QPaintEvent* event) override;
        void mousePressEvent(QMouseEvent* event) override;
        void mouseMoveEvent(QMouseEvent* event) override; 
        void mouseReleaseEvent(QMouseEvent* event) override;
};
#endif