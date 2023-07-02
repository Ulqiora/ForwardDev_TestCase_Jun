#include "EngineMaxPowerTest.h"

#include <chrono>
#include <cmath>
#include <iostream>
#include "../ModelEngineForward.h"

EngineMaxPowerTest::EngineMaxPowerTest(double ambientTemp)
    : ambientTemp_(ambientTemp) {}

void EngineMaxPowerTest::VisitModelEngineForward(ModelEngineForward* engine){
    engine->setCurrTemp(ambientTemp_);
    engine->setRotationSpeed(0.0);
    double torque;
    double acceleration = -1.0;
    double lastSpeedOfMaxPower,maxPower,power;
    while (std::fabs(acceleration) > 1e-4 ) {
        torque = engine->getMotorTorque();
        power = torque*engine->getRotationSpeed()/1000.0;
        if (power > maxPower)
            maxPower = power, lastSpeedOfMaxPower = engine->getRotationSpeed();
        acceleration = torque / engine->getMotorInertia();
        engine->setRotationSpeed(engine->getRotationSpeed() + acceleration);
    }
    printResult(maxPower,lastSpeedOfMaxPower);
}

void EngineMaxPowerTest::printResult(double maxPower, double speed){
    std::cout<<"Max power = "<<maxPower<<"kW, then Speed of engine = "<<speed<<"rad/s.\n";
}
