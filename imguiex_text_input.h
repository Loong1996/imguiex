#ifndef IMGUIEX_TEXT_INPUT_WIDGET_H_
#define IMGUIEX_TEXT_INPUT_WIDGET_H_

#include "imguiex_widget.h"
#include <string>

namespace ImGuiEx {

class TextInput : public Widget {
public:
    TextInput(const std::string& default_str = "", size_t size_limit = 1, const char* name = nullptr) 
        : Widget(name) {
        text_ = default_str;
        if (default_str.size() >= size_limit) {
            size_limit = default_str.size() + 1;
        }

        if (size_limit > 0) {
            text_.resize(size_limit);
        }
    }

    virtual ~TextInput() = default;

    virtual void Render() {

        // 检查是否为隐藏标签（以 "##" 开头）
        bool hidden_label = this->Name().size() >= 2 && this->Name().substr(0, 2) == "##";
        if (hidden_label) {
            // 设置输入框宽度为整个可用宽度
            float availWidth = ImGui::GetContentRegionAvail().x;
            ImGui::PushItemWidth(availWidth);
        }

        ImGui::InputText(this->Name().c_str(), &text_[0], text_.size());

        if (hidden_label) {
            ImGui::PopItemWidth();
        }
    }

private:
    std::string text_;
};

} // namespace ImGuiEx


#endif // IMGUIEX_TEXT_INPUT_WIDGET_H_