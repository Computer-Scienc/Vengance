#ifndef RENDER_H
#define RENDER_H

#include "Object.h"

#include <string>

class VWindow;

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
        std::string glsl_version;

    protected:

    private:
};

#endif // RENDER_H
