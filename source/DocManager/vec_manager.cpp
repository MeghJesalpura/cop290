#include "../../include/DocManager/vec_manager.hpp"
//essentially this will live inside doc_manager and this will be responsible for managing the vector for modularity
void VecManager::add_shape(std::unique_ptr<mainSpace::GraphicClass> shape){
    lshapes.push_back(std::move(shape));
}
void VecManager::remove_shape(int id){
    for(auto it = lshapes.begin(); it != lshapes.end(); it++){
        if((*it) -> get_id() == id){
            lshapes.erase(it);
            break;
        }
    }
}
mainSpace::GraphicClass* VecManager::get_shape(int id){
    for(auto& shape : lshapes){
        if(shape -> get_id() == id){
            return shape.get();
        }
    }
    return nullptr;
}
const std::vector<std::unique_ptr<mainSpace::GraphicClass>>& VecManager::get_all_shapes() const{
    return lshapes;
}
std::vector<std::unique_ptr<mainSpace::GraphicClass>>& VecManager::get_all_shapes_mutable(){
    return lshapes;//in case we need a mutable reference to vector of all shapes
}
std::vector<std::unique_ptr<mainSpace::GraphicClass>> VecManager::clone_shapes() const{
    std::vector<std::unique_ptr<mainSpace::GraphicClass>> cloned_shapes;
    for(const auto& shape : lshapes){
        cloned_shapes.push_back(shape -> clone());//will be used for copy paste and stuff
    }
    return cloned_shapes;
}
void VecManager::clear_shapes(){
    lshapes.clear();
}
void VecManager::restore_shapes(std::vector<std::unique_ptr<mainSpace::GraphicClass>>& shapes){
    lshapes = std::move(shapes);
}
int VecManager::get_new_id(){
    int next_id = 0;
    if(lshapes.size() > 0){
        next_id = lshapes.back() -> get_id() + 1;
    }
    return next_id;
}