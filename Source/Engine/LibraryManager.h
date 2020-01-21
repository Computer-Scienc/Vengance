#ifndef VLIBRARYMANAGER_H
#define VLIBRARYMANAGER_H

#include "Object.h"

#include <string>
#include <vector>

class VLibrary;

//Manages librarys, it initalizes them and shuts them down.
//You can also get pointers to librarys.
class VLibraryManager : public VObject
{
    public:
        //Create librarys in the librarys vector.
        VLibraryManager();
        virtual ~VLibraryManager();

        virtual bool Init();
        virtual void Shutdown();

        VLibrary* GetLibrary(std::string Name);

        std::vector<VLibrary*> librarys;

    protected:

    private:

};

#endif // VLIBRARYMANAGER_H
