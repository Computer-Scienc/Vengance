#ifndef AGRAPH_H
#define AGRAPH_H

#include "Drawable.h"

#include "imgui/imgui.h"
#include "imgui/imnodes.h"

class VGraph : public VDrawable
{
    public:
        VGraph();
        virtual ~VGraph();

        virtual void Init() override;
        virtual void Draw() override;
        virtual void Shutdown() override;



    protected:

    private:
        bool settingWinToMousePos = true;

};

#endif // AGRAPH_H
