#ifndef VAPPLICATION_VENGANCE_H
#define VAPPLICATION_VENGANCE_H

#include "Engine/Application.h"

#include "LibraryManager_Vengance.h"
#include "Engine/WindowManager.h"

class VApplication_Vengance : public VApplication
{
    public:
        VApplication_Vengance();
        virtual ~VApplication_Vengance();

        void Init() override;
        void Update() override;
        void Shutdown() override;

        VLibraryManager_Vengance libManager;
        VWindowManager winManager;

    protected:

    private:
};

#endif // VAPPLICATION_VENGANCE_H
