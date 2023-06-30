#pragma once

#include <algorithm>
#include <iostream>
#include "Config/EngineInfo.h"
#include "IModelEngine.h"

class ModelEngineForward : public IModelEngine {
   public:
    ModelEngineForward() = delete;
    ModelEngineForward(const EngineInfo&);
    ModelEngineForward(ModelEngineForward&&) = default;
    ModelEngineForward(const ModelEngineForward&) = default;
    ModelEngineForward& operator=(ModelEngineForward&&) = default;
    ModelEngineForward& operator=(const ModelEngineForward&) = default;
    virtual ~ModelEngineForward(){}

    virtual void accept(TestVisitor* visitor) override;

    // double calcCurrentAcceleration() const;

    double getC();
    double getHv();
    double getHm();
    double getPickTemp();
    double getMotorTorque();
    double getMotorInertia();
    double getCoolingCoefficient() const;
   private:

    EngineInfo info_;
};