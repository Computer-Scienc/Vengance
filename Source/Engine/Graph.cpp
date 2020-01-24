#include "Graph.h"

#include <fstream>

#include <string>

#include <json.hpp>
using namespace nlohmann;

VGraph::VGraph()
{
    //ctor
}

VGraph::~VGraph()
{
    //dtor
}

void VGraph::Init()
{

}



void VGraph::Draw()
{
    const int hardcoded_node_id = 1;
    imnodes::SetNodeName(hardcoded_node_id, "TEST NODE");

    ImGui::Begin("Node Editor");




    imnodes::BeginNodeEditor();

    imnodes::BeginNode(hardcoded_node_id);
    const int output_attr_id = 2;
    imnodes::BeginOutputAttribute(output_attr_id);
    // in between Begin|EndAttribute calls, you can call ImGui
    // UI functions
    ImGui::Text("output pin");
    imnodes::EndAttribute();

    imnodes::BeginInputAttribute(1);
    ImGui::Text("input pin");
    imnodes::EndAttribute();

    imnodes::EndNode();

    imnodes::EndNodeEditor();

        if(settingWinToMousePos)
        {
            ImGui::SetNextWindowPos(ImGui::GetMousePos());
            settingWinToMousePos = false;
        }
      const bool open_popup =
            ImGui::IsMouseClicked(1);



        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(8.f, 8.f));



        if (!ImGui::IsAnyItemHovered() && open_popup)
        {
            ImGui::OpenPopup("Add Node");
        }

        //ImGuiWindowFlags_

        if (ImGui::BeginPopup("Add Node", ))
        {
            ImVec2 click_pos = ImGui::GetMousePosOnOpeningCurrentPopup();

            int num = 0;
            int numOfNodes = 65;

//            if(ImGui::InputText("Test"))
 //           {

           // }


            for(int i = 0; i < numOfNodes; i++)
            {
                if (ImGui::MenuItem(std::string(std::string("Num: ") + std::to_string(i)).c_str()));
                {

                }
            }

            ImGui::EndPopup();
        }
        else
        {
                settingWinToMousePos = true;
        }

        ImGui::PopStyleVar();

    ImGui::End();
}

void VGraph::Shutdown()
{

}
