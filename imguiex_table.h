#ifndef IMGUIEX_TABLE_WIDGET_H_
#define IMGUIEX_TABLE_WIDGET_H_

#include "imguiex_widget.h"
#include <memory>
#include <vector>

namespace ImGuiEx {

class Table : public Widget {
public:
    using HeaderData = std::vector<std::string>;
    using RowData = std::vector<WidgetPtr>;

    explicit Table(const char* name = nullptr) : Widget(name) {}
    
    virtual ~Table() override = default;
    
    virtual void Render() override {
        if (ImGui::BeginTable(this->Name().c_str(), headers_.size())) {
            // 渲染表头
            for (const auto& header : headers_) {
                ImGui::TableSetupColumn(header.c_str());
            }
            ImGui::TableHeadersRow();

            // 渲染行
            for (const auto& row : rows_) {
                ImGui::TableNextRow();
                for (size_t col = 0; col < row.size() && col < headers_.size(); ++col) {
                    ImGui::TableSetColumnIndex(col);
                    if (row[col]) {
                        row[col]->Render(); // 渲染单元格中的控件
                    }
                }
            }

            ImGui::EndTable();
        }
    }

    // 添加表头
    void SetHeaders(const HeaderData& headers) {
        headers_ = headers;
    }

    // 添加行数据
    void AddRow(const RowData& row) { 
        rows_.push_back(row);
    };

private:
    std::vector<std::string> headers_;
    std::vector<RowData> rows_;
    int cur_tab;
};

} // namespace ImGuiEx


#endif // IMGUIEX_TABLE_WIDGET_H_