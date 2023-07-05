#include "EngineMaxPowerTest.h"

#include <chrono>
#include <cmath>
#include <iostream>
#include "../IModelEngine.h"

EngineMaxPowerTest::EngineMaxPowerTest(double ambientTemp)
    : ambientTemp_(ambientTemp) {}

void EngineMaxPowerTest::start(IModelEngine* engine){
    engine->setAmbientTemperature(ambientTemp_);
    engine->setSimulationStep(1.0);
    engine->start();
    double lastSpeedOfMaxPower = 0.0, maxPower = 0.0;
    do {
        engine->calcNextStep();
        if (maxPower < engine->getPower()) {
            maxPower = engine->getPower();
            lastSpeedOfMaxPower = engine->getRotationSpeed();
        }
    }while (std::fabs(engine->getAcceleration()) > 1e-4 );
    printResult(maxPower,lastSpeedOfMaxPower);
}

void EngineMaxPowerTest::printResult(double maxPower, double speed){
    std::cout<<"Max power = "<<maxPower<<"kW, then Speed of engine = "<<speed<<"rad/s.\n";
}
