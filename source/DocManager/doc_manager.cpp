#include "../../include/DocManager/doc_manager.hpp"

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
//now for cut copy paste and undo redo - TO IMPLEMENT