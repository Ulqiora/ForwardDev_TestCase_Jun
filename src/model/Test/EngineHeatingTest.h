#pragma once

#include "Test.h"
class ModelEngineForward;

class EngineHeatingTest : public Test {
    public:
    EngineHeatingTest(double);
    virtual ~EngineHeatingTest(){}
    virtual void start(IModelEngine* engine) override;
    private:
    void printResult(unsigned long seconds);
    double ambientTemp_;
};