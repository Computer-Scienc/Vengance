#ifndef RENDER_H
#define RENDER_H

#include "Object.h"

//Every window object has a renderer object that will have its own gl context and many other things.
class VRender : public VObject
{
    public:
        VRender();
        virtual ~VRender();

        void Init();
        void Draw();
        void Shutdown();

    protected:

    private:
};

#endif // RENDER_H
