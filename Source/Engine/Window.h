#ifndef WINDOW_H
#define WINDOW_H

#include "Object.h"

#include "Librarys/Library_SDL2.h"

class VRender;

class VWindow : public VObject
{
    public:
        VWindow();
        VWindow(std::string winName);
        virtual ~VWindow();

        bool Open(std::string winName);
        void Update();
        void Close();

        Uint32 getID() { return SDL_GetWindowID(sdl_window); }

        SDL_Window* sdl_window;
        SDL_GLContext sdl_glcontext;

        VRender* renderer;

    protected:

    private:
};

#endif // WINDOW_H
