#include "EngineHeatingTest.h"

#include <chrono>
#include <cmath>
#include <iostream>

#include "../ModelEngineForward.h"

EngineHeatingTest::EngineHeatingTest(double val) : ambientTemp_(val) {}

void EngineHeatingTest::start(IModelEngine* engine) {
    unsigned long  count = 0.0;
    engine->setAmbientTemperature(ambientTemp_);
    engine->setSimulationStep(1.0);
    engine->start();
    while (!engine->overheated()) {
        engine->calcNextStep();
        count++;
    }
    printResult(count);
}

void EngineHeatingTest::printResult(unsigned long seconds){
    std::cout<<"Result testing of heating engine! Seconds = "<<seconds<<'\n';
}