#ifndef IMGUIEX_TEXT_WIDGET_H_
#define IMGUIEX_TEXT_WIDGET_H_

#include "imguiex_widget.h"
#include <string>

namespace ImGuiEx {

class Text : public Widget {
public:
    Text(const std::string& text, const char* name = nullptr) 
        : Widget(name) {
        text_ = text;
    }

    virtual ~Text() = default;

    virtual void Render() {
        ImGui::Text("%s", text_.c_str());
    }

private:
    std::string text_;
};

} // namespace ImGuiEx


#endif // IMGUIEX_TEXT_WIDGET_H_