#include "Window.h"

VWindow::VWindow()
{
    //ctor
}

VWindow::~VWindow()
{
    //dtor
}

bool VWindow::Open()
{
    // Create an application window with the following settings:
    sdl_window = SDL_CreateWindow(
        "Vengance",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE                  // flags - see below
    );

    if(sdl_window == nullptr )
    {
        VLogger::LogToConsole("Could not open window!", Critical::Error);
        return false;
    }

    return true;
}

void VWindow::Close()
{
    SDL_DestroyWindow(sdl_window);

}

void VWindow::Update()
{

}
