#include "Library_GLEW.h"

VLibrary_GLEW::VLibrary_GLEW()
{
    //ctor
    Name = "GLEW";
    customInit = true;
}

VLibrary_GLEW::~VLibrary_GLEW()
{
    //dtor
}

bool VLibrary_GLEW::Init()
{
    if (glewInit() != GLEW_OK)
    {
        return false;
    }

    return true;
}

void VLibrary_GLEW::Shutdown()
{

}
