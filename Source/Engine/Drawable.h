#ifndef VDRAWABLE_H
#define VDRAWABLE_H

#include "Object.h"


class VDrawable : public VObject
{
    public:
        VDrawable();
        virtual ~VDrawable();

        virtual void Init() {}
        virtual void Draw() {}
        virtual void Shutdown() {}

    protected:

    private:
};

#endif // VDRAWABLE_H
