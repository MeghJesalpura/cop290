#ifndef rectangle_hpp
#define rectangle_hpp

#include "graphic_class.hpp"
#include <string>
#include "point.hpp"
namespace mainSpace{
    class Rectangle : public mainSpace::GraphicClass{
        private:
            double width_r;
            double height_r;
            //add private members if needed
        public:
            Rectangle(double x, double y, double width, double height, int m_id);
            virtual ~Rectangle() = default;
            void move_shape(double x, double y);
            void resize(double new_width, double new_height);
            virtual std::unique_ptr<GraphicClass> clone() const override;
            virtual std::string to_svg() override;
            virtual void draw(QPainter& painter) override;
            int get_mode(const QPoint& point) const;//to determine whether the point is in move region or resize region
            void set_width(double m_width);
            void set_height(double m_height);
            double get_width() const;
            double get_height() const;
    };
}

#endif