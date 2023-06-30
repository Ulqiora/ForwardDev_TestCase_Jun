#include "EngineHeatingTest.h"

#include <chrono>
#include <cmath>
#include <iostream>

#include "../ModelEngineForward.h"

EngineHeatingTest::EngineHeatingTest(double val) : ambientTemp_(val) {}

void EngineHeatingTest::VisitModelEngineForward(ModelEngineForward* engine) {
    engine->setCurrTemp(ambientTemp_);
    engine->setRotationSpeed(0.0);
    std::chrono::seconds seconds(0);
    double torque, acceleration, coolingSpeed, heatingSpeed;
    while (std::fabs(engine->getCurrTemp() - engine->getPickTemp()) > 1e-3 &&
           engine->getCurrTemp() < engine->getPickTemp()) {
        torque = engine->getMotorTorque();
        acceleration = torque / engine->getMotorInertia();
        coolingSpeed = engine->getCoolingCoefficient() *
                            (ambientTemp_ - engine->getCurrTemp());
        heatingSpeed =
            torque * engine->getHm() +
            std::pow(engine->getRotationSpeed(), 2.0) * engine->getHv();
        engine->setCurrTemp(engine->getCurrTemp() + coolingSpeed +
                            heatingSpeed);
        engine->setRotationSpeed(engine->getRotationSpeed() + acceleration);
        seconds++;
    }
    printResult(seconds.count());
}

void EngineHeatingTest::printResult(unsigned long seconds){
    std::cout<<"Result testing of heating engine! Seconds = "<<seconds<<'\n';
}