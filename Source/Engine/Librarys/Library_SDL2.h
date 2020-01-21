#ifndef VLIBRARY_SDL2_H
#define VLIBRARY_SDL2_H

#include "Engine/Library.h"

#include <SDL2/SDL.h>


//The engine relies on SDL2 so it is included
class VLibrary_SDL2 : public VLibrary
{
    public:
        VLibrary_SDL2();
        virtual ~VLibrary_SDL2();

        bool Init() override;
        void Shutdown() override;

    protected:

    private:
};

#endif // VLIBRARY_SDL2_H
