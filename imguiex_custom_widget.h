#ifndef IMGUIEX_CUSTOM_WIDGET_H_
#define IMGUIEX_CUSTOM_WIDGET_H_

#include "imguiex_widget.h"
#include <functional>

namespace ImGuiEx {

class CustomWidget : public Widget {
public:
    using RenderCallback = std::function<void(CustomWidget& ctx)>;

    CustomWidget(RenderCallback render_callback, const char* name = nullptr)
        :  render_callback_(render_callback), Widget(name) {}

    virtual void Render() override {
        if (render_callback_) {
            render_callback_(*this);
        }
    }

private:
    RenderCallback render_callback_;
};

} // namespace ImGuiEx


#endif // IMGUIEX_CUSTOM_WIDGET_H_