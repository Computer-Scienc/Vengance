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

      const bool open_popup =
            ImGui::IsMouseClicked(1);



    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(8.f, 8.f));

    /*
    if(setWindowPos == false)
    {

        float mouseX = ImGui::GetMousePos().x;
        float mouseY = ImGui::GetMousePos().y;

        ImVec2 newPos = ImVec2(mouseX, mouseY - (mouseY / 2));

        ImGui::SetNextWindowPos(newPos);
        setWindowPos = true;
    }
    */


    if (!ImGui::IsAnyItemHovered() && open_popup)
    {
        ImGui::OpenPopup("Add Node");
    }



    if (ImGui::BeginPopup("Add Node"))
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
        setWindowPos = false;
    }


    ImGui::PopStyleVar();

    ImGui::End();
}

void VGraph::Shutdown()
{

}
