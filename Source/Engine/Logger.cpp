#include "Logger.h"

#include <iostream>
#include <fstream>

VLogger::VLogger()
{
    //ctor
}

VLogger::~VLogger()
{
    //dtor
}

void VLogger::LogToConsole(std::string Message, Critical crit )
{

    std::cout << crit << ": " << Message << std::endl;

}

void VLogger::LogToFile(std::string Message, Critical crit)
{
    std::ofstream log("Log.txt", std::ios_base::app | std::ios_base::out);

    log << crit << ": " << Message << std::endl;
}

void VLogger::ClearLog()
{
    std::ofstream ofs;
    ofs.open("Log.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}
