#ifndef NODE_JSON_H
#define NODE_JSON_H

#include "imgui/addons/imguinodegrapheditor/imguinodegrapheditor.h"

#define MNT_JSON_NODE 6

class Node_JSON : public ImGui::Node
{
    protected:
    typedef ImGui::Node Base;  //Base Class
    typedef Node_JSON ThisClass;
    Node_JSON() : Base() {}
    static const int TYPE = MNT_JSON_NODE;

    // Support static method for enumIndex (the signature is the same used by ImGui::Combo(...))

    virtual const char* getTooltip() const {return "ComplexNode tooltip.";}
    virtual const char* getInfo() const {return "ComplexNode info.\n\nThis is supposed to display some info about this node.";}
    virtual void getDefaultTitleBarColors(ImU32& defaultTitleTextColorOut,ImU32& defaultTitleBgColorOut,float& defaultTitleBgColorGradientOut) const {
        // [Optional Override] customize Node Title Colors [default values: 0,0,-1.f => do not override == use default values from the Style()]
        defaultTitleTextColorOut = IM_COL32(220,220,220,255);defaultTitleBgColorOut = IM_COL32(125,35,0,255);defaultTitleBgColorGradientOut = -1.f;
    }

    public:

    // create:
    static ThisClass* Create(const ImVec2& pos) {
        // 1) allocation
        // MANDATORY (NodeGraphEditor::~NodeGraphEditor() will delete these with ImGui::MemFree(...))
        // MANDATORY even with blank ctrs.  Reason: ImVector does not call ctrs/dctrs on items.
        ThisClass* node = (ThisClass*) ImGui::MemAlloc(sizeof(ThisClass));IM_PLACEMENT_NEW(node) ThisClass();

        // 2) main init
        node->init("ComplexNode",pos,"in1;in2;in3;in4","out1;out2",TYPE);


        // addFieldEnum(...) [2] (items_count + item_names)
        //static const char* FruitNames[3] = {"APPLE","LEMON","ORANGE"};
        //node->fields.addFieldEnum(&node->enumIndex,3,FruitNames,"Fruit","Choose your favourite");
        // addFieldEnum(...) [3] (zero_separated_item_names)
        //node->fields.addFieldEnum(&node->enumIndex,"APPLE\0LEMON\0ORANGE\0\0","Fruit","Choose your favourite");

        node->fields.addField("EXEC", "Execution");
        // 4) set (or load) field values

        return node;
    }

    // helper casts:
    inline static ThisClass* Cast(Node* n) {return Node::Cast<ThisClass>(n,TYPE);}
    inline static const ThisClass* Cast(const Node* n) {return Node::Cast<ThisClass>(n,TYPE);}
};

#endif // NODE_JSON_H
