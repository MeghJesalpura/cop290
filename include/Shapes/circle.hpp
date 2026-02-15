#ifndef circle_hpp
#define circle_hpp

#include "graphic_class.hpp"
#include <string>
#include "point.hpp"

namespace mainSpace{
    class Circle : public mainSpace::GraphicClass{
        private:
            double radius_;
            Point center_;
        public:
            Circle(double center_x, double center_y, double m_radius, int m_id);
            virtual ~Circle() = default;
            void move_shape(double x, double y);
            void resize(double new_radius);

            void set_radius(double m_radius);
            double get_radius() const;
            virtual std::unique_ptr<GraphicClass> clone() const override;
            virtual std::string to_svg() override;
            virtual void draw(QPainter& painter) override;
            int get_mode(const QPoint& point) const;//to determine whether the point is in move region or resize region
            Point get_center() const;
    };
}

#endif