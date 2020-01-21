#ifndef VLIBRARY_GLEW_H
#define VLIBRARY_GLEW_H

#include "../Library.h"

#include <GL/glew.h>

//The engine requires this library for imgui and advanced opengl usage.
class VLibrary_GLEW : public VLibrary
{
    public:
        VLibrary_GLEW();
        virtual ~VLibrary_GLEW();

        bool Init() override;
        void Shutdown() override;


    protected:

    private:
};

#endif // VLIBRARY_GLEW_H
