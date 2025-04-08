#ifndef IMGUIEX_WIDGET_H_
#define IMGUIEX_WIDGET_H_

#include "imguiex_object.h"
#include <memory>

namespace imguiex {

class Widget : public Object {
public:
    Widget(const std::string& name) : Object(name) {}
    virtual ~Widget() = default;
    virtual void Render() = 0;
};

using WidgetPtr = std::shared_ptr<Widget>;

}


#endif // IMGUIEX_WIDGET_H_