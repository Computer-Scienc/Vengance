#include "Application.h"

#include <Logger.h>

VApplication::VApplication()
{
    //ctor
}

VApplication::VApplication(int argc, char** argv)
{
    VLogger::ClearLog();
    VLogger::LogToFile("Starting...", Critical::Info);


    //Gets the args and does things with them
    for(int i = 0; i < argc; i++)
    {
        //if()
    }

}

VApplication::~VApplication()
{
    //dtor
}

void VApplication::Init()
{
    //Init Librarys



    //Create Window

}

void VApplication::Update()
{
// Game Loop

}

void VApplication::Shutdown()
{

}
