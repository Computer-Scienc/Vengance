#include "WindowManager.h"

#include "Logger.h"

VWindowManager::VWindowManager()
{
    //ctor
}

VWindowManager::~VWindowManager()
{
    //dtor
}

bool VWindowManager::Init()
{

    mainWindow = new VWindow();
    windows_vector.push_back(mainWindow);


    if(!mainWindow->Open())
    {
        return false;
    }

    return true;
}

void VWindowManager::Shutdown()
{
    for(int i = 0; i < int(windows_vector.size()); i++)
    {
        windows_vector[i]->Close();
    }
}

void VWindowManager::Update()
{
    for(int i = 0; i < int(windows_vector.size()); i++)
    {
        windows_vector[i]->Update();
        SDL_GL_SwapWindow(windows_vector[i]->sdl_window);
    }
}
