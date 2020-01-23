#ifndef AGRAPH_H
#define AGRAPH_H

#include "Drawable.h"

#include "imgui/imgui.h"
#include "imgui/addons/imguinodegrapheditor/imguinodegrapheditor.h"

class VGraph : public VDrawable
{
    public:
        VGraph();
        virtual ~VGraph();

        virtual void Init() override;
        virtual void Draw() override;
        virtual void Shutdown() override;

        static ImGui::Node* NodeFactory(int nodeNum, const ImVec2& pos, const ImGui::NodeGraphEditor& /*nge*/);


    protected:

    private:
        ImGui::NodeGraphEditor nge;
};

#endif // AGRAPH_H
