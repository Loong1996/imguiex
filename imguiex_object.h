#ifndef IMGUIEX_OBJECT_H_
#define IMGUIEX_OBJECT_H_

#include <memory>
#include <string>

namespace imguiex {

class Object {
public:
    Object(const std::string& name) : name_(name) {}
    virtual ~Object() = default;
    virtual void Render() = 0;

    const std::string& Name() const { return name_; }

protected:
    std::string name_;
};

using ObjectPtr = std::shared_ptr<Object>;

}


#endif // IMGUIEX_OBJECT_H_