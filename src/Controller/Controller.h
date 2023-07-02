#pragma once
#include "../model/Config/LoaderConfig.h"
#include "../model/ModelEngineForward.h"
#include "../model/Test/EngineHeatingTest.h"
#include "../model/Test/EngineMaxPowerTest.h"
enum class Test { HEATING, MAX_POWER };

class ControllerView {
   public:
    ControllerView()
        : test_(nullptr), engine_(nullptr), loader_(new LoaderConfig()) {}
    bool setFileConfig(std::string filename);
    bool setAmbientTemperature(double temperature);
    void setTest(Test test);
    bool startTest();
    virtual ~ControllerView() {
        if (test_ != nullptr) delete test_;
        if (engine_ != nullptr) delete engine_;
        if (loader_ != nullptr) delete loader_;
    }

   private:
    TestVisitor* test_;
    IModelEngine* engine_;
    ILoaderConfig* loader_;
    double temperature_;
};