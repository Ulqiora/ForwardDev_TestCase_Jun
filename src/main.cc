#include "model/Config/LoaderConfig.h"
#include "model/ModelEngineForward.h"
#include "model/Test/EngineHeatingTest.h"
#include "model/Test/EngineMaxPowerTest.h"
#include <filesystem>
#include <fstream>
#include <iostream>
int main(){
    std::string filename="/mnt/d/GitHub/ForwardDev_TestCase_Jun/Config";
    ILoaderConfig* lc = new LoaderConfig();
    std::fstream file(filename);
    if(!file.is_open()) std::cout<< "File is not opened!";
    lc->load(file);
    IModelEngine* model = new ModelEngineForward(lc->getResult());
    TestVisitor* visitor = new EngineMaxPowerTest(20);
    model->accept(visitor);
    return 0;
}