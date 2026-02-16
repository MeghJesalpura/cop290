#ifndef doc_manager_hpp
#define doc_manager_hpp
#include "vec_manager.hpp"
class DocManager{
    //this class will store the pointers and will be used to do two things: 1) Undo/Redo 2) Cut/Copy/Paste
    private:
        VecManager vec_manager;
        std::unique_ptr<mainSpace::GraphicClass> clipboard_shape; //to store the shape for cut/copy/paste operations - will do undo redo in action_manager
        std::unique_ptr<mainSpace::GraphicClass> selected_shape;
        int current_shape_id;
    public:
        DocManager(); //initially no shape is selected
        void add_shape(std::unique_ptr<mainSpace::GraphicClass> shape);
        mainSpace::GraphicClass* get_shape(int id);
        void remove_shape(int id);
        const std::vector<std::unique_ptr<mainSpace::GraphicClass>>& get_all_shapes() const;
        std::vector<std::unique_ptr<mainSpace::GraphicClass>>& get_all_shapes_mutable();
        void set_current_shape_id(int m_shape_id);
        int get_current_shape_id();
        mainSpace::GraphicClass* get_selected_shape(int m_shape_id);
        int get_new_id();
        void cut_shape(int id);
        void copy_shape(int id);
        void paste_shape(double x, double y);
};

#endif