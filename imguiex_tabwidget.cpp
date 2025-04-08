#include "imguiex_tabwidget.h"
#include "imgui.h"

namespace imguiex {

TabWidget::TabWidget(const std::string& name) 
    : cur_tab(0), Widget(name) {
}

TabWidget::~TabWidget() {
}

void TabWidget::Render() {
    if (ImGui::BeginTabBar(this->Name().c_str())) {
        for (size_t i = 0; i < tab_names_.size(); ++i) {
            if (ImGui::BeginTabItem(tab_names_[i].c_str())) {
                tabs_[i]->Render();
                ImGui::EndTabItem();
            }
        }
        ImGui::EndTabBar();
    }
}

void TabWidget::AddTab(const std::string& tab_name, WidgetPtr tab) {
    tab_names_.emplace_back(tab_name);
    tabs_.emplace_back(tab);
}

} // namespace imguiex