#include "ModelEngineForward.h"

#include <cmath>

#include "Test/Test.h"

ModelEngineForward::ModelEngineForward(const EngineInfo& info) : info_(info) {
    power_ = 0.0;
    rotationStep_ = 0.0;
    acceleration_ = 0.0;
    temperature_ = 0.0;
    modelingStep_ = 0.0;
    torque_ = 0.0;
    coolingSpeed_ = 0.0;
    heatingSpeed_ = 0.0;
    ambientTemperature_ = 0.0;
}

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

void ModelEngineForward::start() {
    power_ = 0.0;
    rotationStep_ = 0.0;
    acceleration_ = 0.0;
    temperature_ = 0.0;
}
void ModelEngineForward::setSimulationStep(double step = 1.0) {
    modelingStep_ = step;
}
void ModelEngineForward::calcNextStep() {
    torque_ = getMotorTorque();
    acceleration_ = torque_ / info_.motorMomentOfInertia_;
    coolingSpeed_ = info_.C * (ambientTemperature_ - temperature_);
    heatingSpeed_ =
        torque_ * info_.Hm_ + std::pow(rotationStep_, 2.0) * info_.Hv_;
    temperature_ += (heatingSpeed_ + coolingSpeed_) * modelingStep_;
    rotationStep_ += acceleration_ * modelingStep_;
    power_ = torque_ * rotationStep_ / 1000.0;
}
double ModelEngineForward::getPower() const { return power_; }
double ModelEngineForward::getRotationSpeed() const { return rotationStep_; }
double ModelEngineForward::getAcceleration() const { return acceleration_; }
double ModelEngineForward::getTemperature() const { return temperature_; }

void ModelEngineForward::setAmbientTemperature(double temperature) {
    ambientTemperature_ = temperature;
}
bool ModelEngineForward::overheated() const {
    return !(std::fabs(temperature_ - info_.upLimitTemperature_) > 1e-4 ||
             temperature_ > info_.upLimitTemperature_);
}