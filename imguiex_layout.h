#ifndef IMGUIEX_LAYOUT_H_
#define IMGUIEX_LAYOUT_H_

#include "imguiex_object.h"
#include <memory>

namespace imguiex {

class Layout : public Object {
public:
    Layout(const std::string& name) : Object(name) {}

};

using LayoutPtr = std::shared_ptr<Layout>;

} // namespace imguiex

#endif // IMGUIEX_LAYOUT_H_