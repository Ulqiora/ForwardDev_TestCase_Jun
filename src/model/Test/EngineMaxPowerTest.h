#pragma once

#include "Test.h"
class IModelEngine;
class EngineMaxPowerTest: public Test{
    public:
    EngineMaxPowerTest(double);
    virtual ~EngineMaxPowerTest(){}
    virtual void start(IModelEngine* engine) override;
    private:
    void printResult(double maxPower, double speed);
    double ambientTemp_;
};