/* Need to decide the dependencies on what need to be imported */
#ifndef qt_canvas_hpp 
#define qt_canvas_hpp
#include <QWidget>
class Canvas : public QWidget {
    Q_OBJECT 
    public:
        Canvas(QWidget* parent = nullptr);
        //now need to override some standard methods
        void paintEvent(QPaintEvent* event) override;
        void mousePressEvent(QMouseEvent* event) override;
        void mouseMoveEvent(QMouseEvent* event) override; 
        void mouseReleaseEvent(QMouseEvent* event) override;
};
#endif