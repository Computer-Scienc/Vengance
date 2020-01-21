#ifndef VLIBRARY_H
#define VLIBRARY_H

#include "Object.h"

#include "Logger.h"
//Initializes a library and shuts down a library.
//Anytime a library's must be included it includes the Library_LIBNAME.h file.
//This keeps consistency and doesn't hurt any code.
class VLibrary : public VObject
{
    public:
        VLibrary();
        virtual ~VLibrary();

        virtual bool Init() { return false; }
        virtual void Shutdown() { }

        std::string Name = "Unknown Library";
    protected:

    private:

};

#endif // VLIBRARY_H
