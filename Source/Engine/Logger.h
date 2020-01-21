#ifndef VLOGGER_H
#define VLOGGER_H

#include "Object.h"

#include <string>

#include "Engine/Data/Enum.h"


VENUM(Critical, Info, Warning, Error);

class VLogger : public VObject
{
    public:
        VLogger();
        virtual ~VLogger();

        //Debugging only.
        static void LogToConsole(std::string Message, Critical crit);

        //Works in release but it is slow, only use it for critical errors.
        static void LogToFile(std::string Message, Critical crit);

        //You should run this at the beginning of the session
        static void ClearLog();

    protected:

    private:
};

#endif // VLOGGER_H
