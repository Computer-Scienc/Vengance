#include "Graph.h"

#include <fstream>

#include "Node_JSON.h"
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
    ImGui::End();
}

void VGraph::Shutdown()
{

}
