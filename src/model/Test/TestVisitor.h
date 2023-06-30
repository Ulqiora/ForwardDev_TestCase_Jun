#pragma once
class ModelEngineForward;

class TestVisitor{
    public:
    virtual void VisitModelEngineForward(ModelEngineForward* engine) = 0;
    virtual ~TestVisitor(){}
};