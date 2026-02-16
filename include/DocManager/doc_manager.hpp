#ifndef doc_manager_hpp
#define doc_manager_hpp
#include "vec_manager.hpp"

class DocManager{
    //this class will store the pointers and will be used to do two things: 1) Undo/Redo 2) Cut/Copy/Paste
    private:
        VecManager vec_manager;
    public:
        void add_shape(std::unique_ptr<mainSpace::GraphicClass> shape);
        mainSpace::GraphicClass* get_shape(int id);
        void remove_shape(int id);
        const std::vector<std::unique_ptr<mainSpace::GraphicClass>>& get_all_shapes() const;
        std::vector<std::unique_ptr<mainSpace::GraphicClass>>& get_all_shapes_mutable();
};

#endif