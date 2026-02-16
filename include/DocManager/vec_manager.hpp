#ifndef vec_manager_hpp
#define vec_manager_hpp
#include <vector>
#include <memory>
#include "../graphic_class.hpp"
class VecManager{
    private:
        std::vector<std::unique_ptr<mainSpace::GraphicClass>> lshapes;
    public:
        void add_shape(std::unique_ptr<mainSpace::GraphicClass> shape);
        mainSpace::GraphicClass* get_shape(int id);
        void remove_shape(int id);
        const std::vector<std::unique_ptr<mainSpace::GraphicClass>>& get_all_shapes() const;
        std::vector<std::unique_ptr<mainSpace::GraphicClass>>& get_all_shapes_mutable();
        std::vector<std::unique_ptr<mainSpace::GraphicClass>> clone_shapes() const;
        void clear_shapes();
        void restore_shapes(std::vector<std::unique_ptr<mainSpace::GraphicClass>>& shapes);
        int get_new_id();
};
#endif