#ifndef circle_hpp
#define circle_hpp

#include "graphic_class.hpp"
#include "string"
#include "point.hpp"

namespace mainSpace{
    class Circle : public GraphicClass{
        private:
            double radius_;
            Point center_;
        public:
            Circle(Point& center, double m_radius, int m_id);
            virtual ~Circle() = default;
            void move_shape(double x, double y) override;
            void resize(double new_radius) override;

            void set_radius(double m_radius);
            double get_radius();
            virtual std::unique_ptr<GraphicClass> clone() const override;
            virtual std::string to_svg() override;
            virtual void draw(QPainter& painter) override;
    };
}

#endif