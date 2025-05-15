#include "node_editor.h"
#include <imnodes.h>
#include <imgui.h>

namespace example
{
namespace
{
class HelloWorldNodeEditor
{
public:
    void show()
    {
        ImGui::Begin("simple node editor", nullptr, ImGuiWindowFlags_MenuBar);

        if (ImGui::BeginMenuBar())
        {
            if (ImGui::BeginMenu("View"))
            {
                if (ImGui::MenuItem("Reset Panning"))
                    ImNodes::EditorContextResetPanning(ImVec2());

                if (ImGui::MenuItem("Reset Zoom"))
                    ImNodes::EditorContextSetZoom(1.0f);

                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("Debug"))
            {
                ImGui::MenuItem("Show Debug Info", NULL, &m_show_debug_info);
                ImGui::EndMenu();
            }

            ImGui::EndMenuBar();
        }

        if (m_show_debug_info)
        {
            if (ImGui::Begin("Debug Info", &m_show_debug_info))
            {
                ImNodes::EditorContextDrawDebugInfo();
            }
            ImGui::End();
        }

        ImNodes::BeginNodeEditor();
        ImNodes::BeginNode(1);

        ImNodes::BeginNodeTitleBar();
        ImGui::TextUnformatted("simple node :)");
        ImNodes::EndNodeTitleBar();

        ImNodes::BeginInputAttribute(2);
        ImGui::Text("input");
        ImNodes::EndInputAttribute();

        ImNodes::BeginOutputAttribute(3);
        ImGui::Indent(40);
        ImGui::Text("output");
        ImNodes::EndOutputAttribute();

        ImNodes::EndNode();
        ImNodes::EndNodeEditor();

        ImGui::End();
    }
private:
    bool m_show_debug_info = false;
};

static HelloWorldNodeEditor editor;
} // namespace

void NodeEditorInitialize() { ImNodes::SetNodeGridSpacePos(1, ImVec2(200.0f, 200.0f)); }

void NodeEditorShow() { editor.show(); }

void NodeEditorShutdown() {}

} // namespace example
