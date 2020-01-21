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
    winManager.NewWindow("");
}

void VApplication_Vengance::Update()
{
    bool mainWindowOpen = true;

    //Game Loop
    while(mainWindowOpen)
    {
        SDL_Event e;
        while (SDL_PollEvent(&e)){


            if(e.type == SDL_WINDOWEVENT)
            {
                if(e.window.event == SDL_WINDOWEVENT_CLOSE)
                {
                    Uint32 mainWindowID = SDL_GetWindowID(winManager.mainWindow->sdl_window);
                    if( e.window.windowID ==  mainWindowID)
                    {
                        VLogger::LogToConsole("Closing main window.", Critical::Info);
                        mainWindowOpen = false;
                    }
                    else
                    {
                        //Save data that was working in other window


                        //Close window
                        VLogger::LogToConsole("Closing child window.", Critical::Info);
                        winManager.getWindowFromID(e.window.windowID)->Close();
                    }
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
