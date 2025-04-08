#include "imguiex_vboxlayout.h"
#include "imguiex_custom_widget.h"
#include "imgui.h"

namespace ImGuiEx {

void VBoxLayout::AddWidget(WidgetPtr ptr) {
    widgets_.push_back(ptr);
}

void VBoxLayout::AddLayout(LayoutPtr ptr) {
    auto w = std::make_shared<CustomWidget>([ptr](auto& ctx) { 
        ImGui::BeginChild(ctx.Name().c_str(), ImVec2(0, 0),  ImGuiChildFlags_ResizeY);
        ptr->Render();
        ImGui::EndChild();
    });

    widgets_.push_back(w);
}

void VBoxLayout::Render() {
    for (auto& widget : widgets_) {
        widget->Render();
    }
}

}