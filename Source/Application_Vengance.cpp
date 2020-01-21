#include "Application_Vengance.h"

VApplication_Vengance::VApplication_Vengance()
{
    //ctor
}

VApplication_Vengance::~VApplication_Vengance()
{
    //dtor
}

void VApplication_Vengance::Init()
{
    //Init Library's
    libManager.Init();

    //Create Window
    winManager.Init();
}

void VApplication_Vengance::Update()
{
    bool mainWindowOpen = true;

    //Game Loop
    while(mainWindowOpen)
    {
        SDL_Event e;
        while (SDL_PollEvent(&e)){
            /*
            if (e->type == SDL_WINDOWEVENT)
            {

                if(e->type == SDL_WINDOWEVENT)
                {
                    if(e->window.event == SDL_WINDOWEVENT_FOCUS_GAINED)
                    {
                        e->window.windowID
                    }
                }

            }
            */
            if( e.type == SDL_QUIT )
            {
                Uint32 mainWindowID = SDL_GetWindowID(winManager.mainWindow->sdl_window);
                if( e.window.windowID ==  mainWindowID)
                {
                    VLogger::LogToConsole("Closing main window.", Critical::Info);
                }
            }
        }
    }
}

void VApplication_Vengance::Shutdown()
{

    winManager.Shutdown();

    //UnInit Library's
    libManager.Shutdown();
}
