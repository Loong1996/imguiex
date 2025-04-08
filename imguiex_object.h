#ifndef IMGUIEX_OBJECT_H_
#define IMGUIEX_OBJECT_H_

#include <memory>
#include <string>
#include <cstdint>

namespace ImGuiEx {

class Object {
public:
    explicit Object(const char* name = nullptr);
    virtual ~Object() = default;
    virtual void Render() = 0;

    const std::string& Name() const { return name_; }

private:
    static std::string AllocDynaName();
    static uint64_t dyna_name_counter_;

protected:
    std::string name_;
};

using ObjectPtr = std::shared_ptr<Object>;

class Layout;
using LayoutPtr = std::shared_ptr<Layout>;

class Widget;
using WidgetPtr = std::shared_ptr<Widget>;
}


#endif // IMGUIEX_OBJECT_H_