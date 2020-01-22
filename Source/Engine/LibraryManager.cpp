#include "LibraryManager.h"

#include "Library.h"
#include "Logger.h"

VLibraryManager::VLibraryManager()
{
    //ctor
}

VLibraryManager::~VLibraryManager()
{
    //dtor
}

bool VLibraryManager::Init()
{
    bool init = true;

    for(int i = 0; i < int(librarys.size()); i++)
    {
        if(!librarys[i]->customInit && librarys[i]->Init() != true)
        {
            VLogger::LogToConsole(std::string(librarys[i]->Name + " could not initalize."), Critical::Error);
            init = false;
            break;
        }
    }

    return init;
}

void VLibraryManager::Shutdown()
{
    for(int i = 0; i < int(librarys.size()); i++)
    {
        librarys[i]->Shutdown();
    }
}

VLibrary* VLibraryManager::GetLibrary(std::string LibName)
{
    //TODO: Feels inefficent

    VLibrary* libFound = nullptr;

    for(int i = 0; i < int(librarys.size()); i++)
    {
        if(librarys[i]->Name == LibName)
        {
            libFound = librarys[i];
        }
    }

    if(libFound == nullptr)
    {
        VLogger::LogToConsole(std::string("Could not find library " + LibName + "."), Critical::Warning);
        return nullptr;
    }
    else
    {
        return libFound;
    }



}
