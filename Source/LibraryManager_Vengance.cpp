#include "LibraryManager_Vengance.h"

#include "Engine/Librarys/Library_SDL2.h"
#include "Engine/Librarys/Library_GLEW.h"

VLibraryManager_Vengance::VLibraryManager_Vengance()
{
    //ctor
    librarys = std::vector<VLibrary*> { new VLibrary_SDL2(), new VLibrary_GLEW() };
}

VLibraryManager_Vengance::~VLibraryManager_Vengance()
{
    //dtor
}
