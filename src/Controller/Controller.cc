#include "Controller.h"

#include <cassert>
#include <fstream>
bool ControllerView::setFileConfig(std::string filename) {
    std::fstream file(filename);
    if (!file.is_open()) return false;
    if (!loader_->load(file)) return false;
    engine_ = new ModelEngineForward(loader_->getResult());
    return true;
}
bool ControllerView::setAmbientTemperature(double temperature) {
    temperature_ = temperature;
    return true;
}
void ControllerView::setTest(Test test) {
    if (test_ != nullptr) {
        delete test_;
        test_ = nullptr;
    }
    if (test == Test::HEATING) {
        test_ = new EngineHeatingTest(temperature_);
    } else {
        test_ = new EngineMaxPowerTest(temperature_);
    }
}

bool ControllerView::startTest() {
    if (test_ == nullptr) return false;
    if (engine_ == nullptr) return false;
    engine_->accept(test_);
    return true;
}