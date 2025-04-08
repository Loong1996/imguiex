#ifndef IMGUIEX_CUSTOM_WIDGET_H_
#define IMGUIEX_CUSTOM_WIDGET_H_

#include "imguiex_widget.h"
#include <functional>

namespace imguiex {

class CustomWidget : public Widget {
public:
    using RenderCallback = std::function<void()>;

    CustomWidget(const std::string& name, RenderCallback render_callback)
        : Widget(name), render_callback_(render_callback) {}

    virtual void Render() override {
        if (render_callback_) {
            render_callback_();
        }
    }

private:
    RenderCallback render_callback_;
};

} // namespace imguiex


#endif // IMGUIEX_CUSTOM_WIDGET_H_