#include "imguiex_hboxlayout.h"
#include "imguiex_custom_widget.h"
#include "imgui.h"

namespace ImGuiEx {

void HBoxLayout::AddWidget(WidgetPtr ptr) {
    widgets_.push_back(ptr);
}

void HBoxLayout::AddLayout(LayoutPtr ptr, ImGuiChildFlags child_flags, ImGuiWindowFlags window_flags) {
    auto w = std::make_shared<CustomWidget>([ptr, child_flags, window_flags](auto& ctx) { 
        ImGui::BeginChild(ctx.Name().c_str(), ImVec2(0, 0), child_flags, window_flags);
        ptr->Render();
        ImGui::EndChild();
    });

    widgets_.push_back(w);
}

void HBoxLayout::Render() {
    size_t count = 0;
    for (auto& widget : widgets_) {
        widget->Render();
        if (++count < widgets_.size()) {
            ImGui::SameLine();
        }
    }
}

}