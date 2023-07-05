#pragma once
#include "../IModelEngine.h"

class Test{
    public:
    virtual void start(IModelEngine* engine) = 0;
    virtual ~Test(){}
};