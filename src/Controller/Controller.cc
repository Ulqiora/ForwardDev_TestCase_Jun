#include "Controller.h"

#include <cassert>
#include <fstream>
bool ControllerView::setFileConfig(std::string filename) {
    std::fstream file(filename);
    if (!file.is_open()) return false;
    bool result = loader_->load(file);
    file.close();
    if (!result) return false;
    engine_ = new ModelEngineForward(loader_->getResult());
    return true;
}
bool ControllerView::setAmbientTemperature(double temperature) {
    temperature_ = temperature;
    return true;
}
void ControllerView::setTest(TestType test) {
    if (test_ != nullptr) {
        delete test_;
        test_ = nullptr;
    }
    if (test == TestType::HEATING) {
        test_ = new EngineHeatingTest(temperature_);
    } else {
        test_ = new EngineMaxPowerTest(temperature_);
    }
}

bool ControllerView::startTest() {
    if (test_ == nullptr) return false;
    if (engine_ == nullptr) return false;
    test_->start(engine_);
    return true;
}