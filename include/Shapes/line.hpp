#ifndef line_hpp
#define line_hpp

#include "graphic_class.hpp"
#include <string>
#include "point.hpp"

namespace mainSpace{
    class line : public mainSpace::GraphicClass{
        private:
            double x2;
            double y2;
            //add private members if needed
        public:
            line(double x1, double y1, double x2, double y2, int m_id);
            virtual ~line() = default;
            void move_shape(double x, double y);
            void resize(double new_x2, double new_y2);
            virtual std::unique_ptr<GraphicClass> clone() const override;
            virtual std::string to_svg() override;
            virtual void draw(QPainter& painter) override;
            int get_mode(const QPoint& point) const;//to determine whether the point is in move region or resize region
            void set_x2(double m_x2);
            void set_y2(double m_y2);
            double get_x2() const;
            double get_y2() const;
    };
}
#endif