#ifndef IMGUIEX_SPLIT_LAYOUT_H_
#define IMGUIEX_SPLIT_LAYOUT_H_

#include "imguiex_layout.h"
#include "imguiex_widget.h"

namespace imguiex {

class SplitLayout : public Layout {
    public:
    enum Orientation { Horizontal, Vertical };
    SplitLayout(Orientation orientation, float split_ration, WidgetPtr left_or_top, WidgetPtr right_or_bottom)
        : orientation_(orientation), split_ration_(split_ration),
        left_or_top_(left_or_top), right_or_bottom_(right_or_bottom), Layout("xxx") {
    }

    virtual void Render() override {
        ImVec2 size = ImGui::GetContentRegionAvail();
        float splitPos = (orientation_ == Horizontal) ? size.x * split_ration_ : size.y * split_ration_;

        if (orientation_ == Horizontal) {
            ImGui::BeginChild(left_or_top_->Name().c_str(), ImVec2(splitPos - 4, 0), true);
            left_or_top_->Render();
            ImGui::EndChild();

            ImGui::SameLine();

            // // === 拖拉条 ===
            // ImGui::PushStyleColor(ImGuiCol_Button, IM_COL32(128, 128, 128, 255));
            // ImGui::PushStyleColor(ImGuiCol_ButtonHovered, IM_COL32(160, 160, 160, 255));
            // ImGui::PushStyleColor(ImGuiCol_ButtonActive, IM_COL32(192, 192, 192, 255));
            ImVec2 old = ImGui::GetCursorScreenPos();
            ImGui::SetCursorScreenPos(ImVec2(splitPos - 4, 0));
            ImGui::Button("##splitter", ImVec2(6.0f, -1.0f));

            ImGui::SetCursorScreenPos(old);
            if (ImGui::IsItemActive() && ImGui::IsMouseDragging(0)) {
                float delta = ImGui::GetIO().MouseDelta.x / size.x;
                split_ration_ += delta;
                split_ration_ = std::clamp(split_ration_, 0.1f, 0.9f);
            }
            // ImGui::PopStyleColor(3);

            ImGui::SameLine();
            ImGui::BeginChild(right_or_bottom_->Name().c_str(), ImVec2(0, 0), true);
            right_or_bottom_->Render();
            ImGui::EndChild();
        }
        else {
            ImGui::BeginChild(left_or_top_->Name().c_str(), ImVec2(0, splitPos), true);
            left_or_top_->Render();
            ImGui::EndChild();

            // // === 拖拉条 ===
            // ImGui::PushStyleColor(ImGuiCol_Button, IM_COL32(128, 128, 128, 255));
            // ImGui::PushStyleColor(ImGuiCol_ButtonHovered, IM_COL32(160, 160, 160, 255));
            // ImGui::PushStyleColor(ImGuiCol_ButtonActive, IM_COL32(192, 192, 192, 255));
            ImGui::InvisibleButton("##splitter", ImVec2(-1.0f, 6.0f));
            if (ImGui::IsItemActive() && ImGui::IsMouseDragging(0)) {
                float delta = ImGui::GetIO().MouseDelta.y / size.y;
                split_ration_ += delta;
                split_ration_ = std::clamp(split_ration_, 0.1f, 0.9f);
            }
            // ImGui::PopStyleColor(3);

            ImGui::BeginChild(right_or_bottom_->Name().c_str(), ImVec2(0, 0), true);
            right_or_bottom_->Render();
            ImGui::EndChild();
        }
    }

private:
    Orientation orientation_;
    float split_ration_;
    WidgetPtr left_or_top_;
    WidgetPtr right_or_bottom_;
};

} // namespace imguiex

#endif // IMGUIEX_SPLIT_LAYOUT_H_