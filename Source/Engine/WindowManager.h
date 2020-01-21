#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include "Object.h"

#include "Window.h"

//Manages windows (eg. initalizes, updates, shuts down windows)
//Relies on SDL2
class VWindowManager : public VObject
{
    public:
        VWindowManager();
        virtual ~VWindowManager();

        //Creates main window
        bool Init();
        void Update();
        void Draw();
        void Shutdown();

        VWindow* mainWindow;
        std::vector<VWindow*> windows_vector;

    protected:

    private:
};

#endif // WINDOWMANAGER_H
