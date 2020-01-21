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


    if(!mainWindow->Open("Vengance"))
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

bool VWindowManager::NewWindow(std::string windowName)
{
    VWindow* newWin = new VWindow();

    windows_vector.push_back(newWin);

    if(!newWin->Open("Vengance: Child Window"))
    {
        return false;
    }

    return true;
}

void VWindowManager::CloseWindow(VWindow* windowToRemove)
{
    for(int i = 0; i < int(windows_vector.size()); i++)
    {
        if(windows_vector[i] == windowToRemove)
        {
            windows_vector[i]->Close();
            delete windows_vector[i];
            windows_vector.erase(windows_vector.begin() + i - 1);
        }
    }
}

VWindow* VWindowManager::getWindowFromID(Uint32 id)
{
    VWindow* foundWindow = nullptr;

    for(int i = 0; i < int(windows_vector.size()); i++)
    {
        if(windows_vector[i]->getID() == id)
        {
            foundWindow = windows_vector[i];
            break;
        }
    }

    if(foundWindow == nullptr)
    {
        VLogger::LogToConsole("Could not find window from ID!", Critical::Warning);
    }

    return foundWindow;
}
