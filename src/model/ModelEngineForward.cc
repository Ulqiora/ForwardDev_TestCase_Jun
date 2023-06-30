#include "ModelEngineForward.h"

#include "Test/TestVisitor.h"

ModelEngineForward::ModelEngineForward(const EngineInfo& info) : info_(info) {}

void ModelEngineForward::accept(TestVisitor* visitor) {
    visitor->VisitModelEngineForward(this);
}

double ModelEngineForward::getCoolingCoefficient() const { return info_.C; }
double ModelEngineForward::getPickTemp() { return info_.upLimitTemperature_; }
double ModelEngineForward::getMotorInertia() {
    return info_.motorMomentOfInertia_;
}

double ModelEngineForward::getHm() { return info_.Hm_; }
double ModelEngineForward::getHv() { return info_.Hv_; }
double ModelEngineForward::getC() { return info_.C; }

double ModelEngineForward::getMotorTorque() {
    auto temp = std::find_if(
        info_.SpeedPoints_.begin(), info_.SpeedPoints_.end(),
        [temp = getRotationSpeed()](double a) { return a > temp; });
    if (temp == info_.SpeedPoints_.end())
        return info_.MotorTorquePoints_.back();
    auto index = std::distance(info_.SpeedPoints_.begin(), temp);
    double a = (info_.MotorTorquePoints_[index] -
                info_.MotorTorquePoints_[index - 1]) /
               (info_.SpeedPoints_[index] - info_.SpeedPoints_[index - 1]);
    return info_.MotorTorquePoints_[index] -
           (info_.SpeedPoints_[index] - getRotationSpeed()) * a;
}