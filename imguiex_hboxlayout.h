#ifndef IMGUIEX_HBOXLAYOUT_H_
#define IMGUIEX_HBOXLAYOUT_H_

#include "imguiex_layout.h"
#include <list>

namespace ImGuiEx {

class HBoxLayout : public Layout {
public:
    explicit HBoxLayout(const char* name = nullptr) : Layout(name) {}

public:
    void AddWidget(WidgetPtr ptr);
    void AddLayout(LayoutPtr ptr);
    virtual void Render() override;

private:
    std::list<WidgetPtr> widgets_;
};

} // namespace ImGuiEx

#endif // IMGUIEX_HBOXLAYOUT_H_