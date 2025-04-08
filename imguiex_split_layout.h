#ifndef IMGUIEX_SPLIT_LAYOUT_H_
#define IMGUIEX_SPLIT_LAYOUT_H_

#include "imguiex_layout.h"
#include "imguiex_widget.h"

namespace ImGuiEx {

class SplitLayout : public Layout {
    public:
    enum Orientation { Horizontal, Vertical };
    SplitLayout(Orientation orientation, float split_ration, WidgetPtr left_or_top, WidgetPtr right_or_bottom)
        : orientation_(orientation), split_ration_(split_ration),
        left_or_top_(left_or_top), right_or_bottom_(right_or_bottom), Layout(nullptr) {
    }

    virtual void Render() override {
        ImVec2 size = ImGui::GetContentRegionAvail();
        float splitPos = (orientation_ == Horizontal) ? size.x * split_ration_ : size.y * split_ration_;

        if (orientation_ == Horizontal) {
            ImGui::BeginChild(left_or_top_->Name().c_str(), ImVec2(splitPos, 0), true);
            left_or_top_->Render();
            ImGui::EndChild();

            // ImGui::SameLine();
            ImGui::SameLine();
            ImVec2 old = ImGui::GetCursorScreenPos();
            ImVec2 padding = ImGui::GetStyle().ItemSpacing;

            ImGui::SetCursorScreenPos(ImVec2(old.x - padding.x, old.y));
            ImGui::Button("##splitter", ImVec2(padding.x, -1.0f));

            if (ImGui::IsItemActive() && ImGui::IsMouseDragging(0)) {
                float delta = ImGui::GetIO().MouseDelta.x / size.x;
                split_ration_ += delta;
                split_ration_ = std::clamp(split_ration_, 0.0001f, 1.0f);
            }

            ImGui::SameLine();

            ImGui::SetCursorScreenPos(old);
            ImGui::BeginChild(right_or_bottom_->Name().c_str(), ImVec2(0, 0), true);
            right_or_bottom_->Render();
            ImGui::EndChild();
        }
        else {
            ImGui::BeginChild(left_or_top_->Name().c_str(), ImVec2(0, splitPos), true);
            left_or_top_->Render();
            ImGui::EndChild();

            ImVec2 old = ImGui::GetCursorScreenPos();
            ImVec2 padding = ImGui::GetStyle().ItemSpacing;

            ImGui::SetCursorScreenPos(ImVec2(old.x, old.y - padding.y));
           
            ImGui::InvisibleButton("##splitter", ImVec2(-1.0f, padding.y));
            if (ImGui::IsItemActive() && ImGui::IsMouseDragging(0)) {
                float delta = ImGui::GetIO().MouseDelta.y / size.y;
                split_ration_ += delta;
                split_ration_ = std::clamp(split_ration_, 0.01f, 0.99f);
            }

            ImGui::SetCursorScreenPos(old);

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

} // namespace ImGuiEx

#endif // IMGUIEX_SPLIT_LAYOUT_H_