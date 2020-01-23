#ifndef RENDER_H
#define RENDER_H

#include "Object.h"

#include <string>

class VWindow;
class VGraph;
class ImGuiContext;

struct ImGuiIO;

//Every window object has a renderer object that will have its own gl context and many other things.
class VRender : public VObject
{
    public:
        VRender();
        virtual ~VRender();

        void Init();
        void Draw();
        void Shutdown();

        VWindow* renderWindow;


    protected:

    private:
        std::string glsl_version;

        ImGuiContext* imguiContext;
        ImGuiIO* io;
        VGraph* grph;
};

#endif // RENDER_H
