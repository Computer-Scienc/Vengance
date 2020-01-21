#include "Library_SDL2.h"

VLibrary_SDL2::VLibrary_SDL2()
{
    //ctor
    Name = "SDL2";
}

VLibrary_SDL2::~VLibrary_SDL2()
{
    //dtor
}

bool VLibrary_SDL2::Init()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {

        VLogger::LogToConsole(SDL_GetError(), Critical::Error);

        return false;
    }

    return true;

}

void VLibrary_SDL2::Shutdown()
{
    SDL_Quit();
}
