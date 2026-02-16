#include "../../include/DocManager/doc_manager.hpp"
#include "../../include/DocManager/shape_positioner.hpp"
DocManager::DocManager(){
    current_shape_id = -1; //initially no shape is selected
}
void DocManager::add_shape(std::unique_ptr<mainSpace::GraphicClass> shape){
    vec_manager.add_shape(std::move(shape));
}
void DocManager::remove_shape(int id){
    vec_manager.remove_shape(id);
}
mainSpace::GraphicClass* DocManager::get_shape(int id){
    return vec_manager.get_shape(id);
}
const std::vector<std::unique_ptr<mainSpace::GraphicClass>>& DocManager::get_all_shapes() const{
    return vec_manager.get_all_shapes();
}
std::vector<std::unique_ptr<mainSpace::GraphicClass>>& DocManager::get_all_shapes_mutable(){
    return vec_manager.get_all_shapes_mutable();
}
void DocManager::set_current_shape_id(int m_shape_id){
    current_shape_id = m_shape_id;
}
int DocManager::get_current_shape_id(){
    return current_shape_id;
}
int DocManager::get_new_id(){
    return vec_manager.get_new_id();
}
mainSpace::GraphicClass* DocManager::get_selected_shape(int m_shape_id){
    return vec_manager.get_shape(m_shape_id);
}
void DocManager::cut_shape(int id){
    mainSpace::GraphicClass* tempshape = vec_manager.get_shape(id);
    if(tempshape != nullptr){
        clipboard_shape = tempshape -> clone();//storing a copy of the shape in the clipboard
        vec_manager.remove_shape(id); //removing the shape from the document
        current_shape_id = -1; //deselecting the shape
    }
}
void DocManager::copy_shape(int id){
    mainSpace::GraphicClass* tempshape = vec_manager.get_shape(id);
    if(tempshape != nullptr){
        clipboard_shape = tempshape -> clone();//storing a copy of the shape in the clipboard
    }
}
void DocManager::paste_shape(double x, double y){
    if(clipboard_shape != nullptr){
        std::unique_ptr<mainSpace::GraphicClass> new_shape = clipboard_shape -> clone(); //creating a new shape object from the clipboard shape
        ShapePositioner::move_shape_to(new_shape.get(), x, y); //moving the shape to the cursor position
        new_shape -> set_position(x, y); //setting as per top left corner for ease
        new_shape -> set_id(vec_manager.get_new_id()); //assigning a new id to the pasted shape

        vec_manager.add_shape(std::move(new_shape)); //adding the new shape
    }
}