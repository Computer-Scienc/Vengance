#ifndef WINDOW_H
#define WINDOW_H

#include "Object.h"

#include "Librarys/Library_SDL2.h"

class VWindow : public VObject
{
    public:
        VWindow();
        virtual ~VWindow();

        bool Open();
        void Update();
        void Close();

        SDL_Window* sdl_window;

    protected:

    private:
};

#endif // WINDOW_H
