#pragma once
#include "../model/Config/LoaderConfig.h"
#include "../model/ModelEngineForward.h"
#include "../model/Test/EngineHeatingTest.h"
#include "../model/Test/EngineMaxPowerTest.h"
enum class TestType { HEATING = 1, MAX_POWER = 2 };

class ControllerView {
   public:
    ControllerView()
        : test_(nullptr), engine_(nullptr), loader_(new LoaderConfig()),temperature_(20.0){}
    bool setFileConfig(std::string filename);
    bool setAmbientTemperature(double temperature);
    void setTest(TestType test);
    bool startTest();
    virtual ~ControllerView() {
        if (test_ != nullptr) delete test_;
        if (engine_ != nullptr) delete engine_;
        if (loader_ != nullptr) delete loader_;
    }

   private:
    Test* test_;
    IModelEngine* engine_;
    ILoaderConfig* loader_;
    double temperature_;
};