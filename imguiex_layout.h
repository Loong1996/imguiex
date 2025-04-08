#ifndef IMGUIEX_LAYOUT_H_
#define IMGUIEX_LAYOUT_H_

#include "imguiex_object.h"
#include <list>

namespace ImGuiEx {

class Layout : public Object {
public:
    explicit Layout(const char* name = nullptr) : Object(name) {}
};

// class VBoxLayout : public Layout {
// public:
//     explicit VBoxLayout(const char* name = nullptr) : Layout(name) {}

// public:
//     void AddWidget(WidgetPtr ptr) {
//         widgets_.push_back(ptr);
//     }

//     virtual void Render() override {
//         for (auto& widget : widgets_) {
//             widget->Render();
//         }
//     }

// private:
//     std::list<WidgetPtr> widgets_;
// };

} // namespace ImGuiEx

#endif // IMGUIEX_LAYOUT_H_