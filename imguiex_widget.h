#ifndef IMGUIEX_WIDGET_H_
#define IMGUIEX_WIDGET_H_

#include "imguiex_object.h"
#include <memory>

namespace ImGuiEx {

class Widget : public Object {
public:
    Widget(const char* name = nullptr) : Object(name) {}
    virtual ~Widget() = default;
    virtual void Render() = 0;
};


}


#endif // IMGUIEX_WIDGET_H_