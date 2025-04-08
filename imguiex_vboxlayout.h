#ifndef IMGUIEX_VBOXLAYOUT_H_
#define IMGUIEX_VBOXLAYOUT_H_

#include "imguiex_layout.h"
#include <list>

namespace ImGuiEx {

class VBoxLayout : public Layout {
public:
    explicit VBoxLayout(const char* name = nullptr) : Layout(name) {}

public:
    void AddWidget(WidgetPtr ptr);
    void AddLayout(LayoutPtr ptr);
    virtual void Render() override;

private:
    std::list<WidgetPtr> widgets_;
};

} // namespace ImGuiEx

#endif // IMGUIEX_VBOXLAYOUT_H_