#pragma once

#include "TestVisitor.h"

class EngineMaxPowerTest: public TestVisitor{
    public:
    EngineMaxPowerTest(double);
    EngineMaxPowerTest() = default;
    EngineMaxPowerTest(EngineMaxPowerTest&& ) = default;
    EngineMaxPowerTest(const EngineMaxPowerTest&) = default;
    EngineMaxPowerTest& operator=(EngineMaxPowerTest&&) = default;
    EngineMaxPowerTest& operator=(const EngineMaxPowerTest&) = default;
    virtual ~EngineMaxPowerTest(){}

    virtual void VisitModelEngineForward(ModelEngineForward* engine) override;
    private:

    void printResult(double maxPower, double speed);

    double ambientTemp_;
};