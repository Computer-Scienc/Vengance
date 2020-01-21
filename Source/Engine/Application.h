#ifndef VAPPLICATION_H
#define VAPPLICATION_H


#include "Object.h"

class VApplication : public VObject
{
    public:
        VApplication();
        VApplication(int argc, char** argv);
        virtual ~VApplication();

        virtual void Init();
        virtual void Update();
        virtual void Shutdown();

    protected:

    private:
};

#endif // VAPPLICATION_H
