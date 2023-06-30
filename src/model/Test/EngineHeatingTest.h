#pragma once

#include "TestVisitor.h"
class ModelEngineForward;

class EngineHeatingTest : public TestVisitor {
    
    public:

    EngineHeatingTest(double);
    EngineHeatingTest() = default;
    EngineHeatingTest(EngineHeatingTest&& ) = default;
    EngineHeatingTest(const EngineHeatingTest&) = default;
    EngineHeatingTest& operator=(EngineHeatingTest&&) = default;
    EngineHeatingTest& operator=(const EngineHeatingTest&) = default;
    virtual ~EngineHeatingTest(){}

    virtual void VisitModelEngineForward(ModelEngineForward* engine) override;

    private:

    void printResult(unsigned long seconds);

    double ambientTemp_;
};