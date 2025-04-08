#ifndef IMGUIEX_TABWIDGET_H_
#define IMGUIEX_TABWIDGET_H_

#include "imguiex_widget.h"
#include <memory>
#include <vector>

namespace imguiex {

class TabWidget : public Widget {
public:
    TabWidget(const std::string& name);
    virtual ~TabWidget() override;
    virtual void Render() override;
    void AddTab(const std::string& tab_name, WidgetPtr tab);

private:
    std::vector<std::string> tab_names_;
    std::vector<WidgetPtr> tabs_;
    int cur_tab;
};

}


#endif // IMGUIEX_TABWIDGET_H_