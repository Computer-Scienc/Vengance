#include "LibraryManager_Vengance.h"

#include "Library_SDL2.h"

VLibraryManager_Vengance::VLibraryManager_Vengance()
{
    //ctor
    librarys = std::vector<VLibrary*> { new VLibrary_SDL2() };
}

VLibraryManager_Vengance::~VLibraryManager_Vengance()
{
    //dtor
}
