#include "imguiex_object.h"

namespace ImGuiEx {

uint64_t Object::dyna_name_counter_ = 0;

Object::Object(const char* name) {
    if (nullptr != name) {
        name_ = *name;
    } else {
        name_ = this->AllocDynaName();
    }
}

std::string Object::AllocDynaName() {
    std::string name = "##imguiex_inner_obj_";
    name += std::to_string(dyna_name_counter_);
    dyna_name_counter_++;
    return name;
}

}