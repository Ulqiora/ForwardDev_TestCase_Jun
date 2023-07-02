#include "View.h"

#include "../Controller/Controller.h"

void View::show(){
    showFileConfigConsole();
    showSetTemperatureConsole();
    showSetTest();
}
void View::showFileConfigConsole(){
    std::string filename;
    std::cout<<"Enter file configuration path of engine:";
    std::cin>>filename;
    while (!controller_->setFileConfig(filename)) {
        std::cout<<"File path is not correct\n";
        std::cout<<"Enter file configuration path of engine:";
    }
}
void View::showSetTemperatureConsole(){
    int temperature;
    std::cout<<"Enter file ambient temperature:";
    std::cin>>temperature;
    while(!std::cin) {
        std::cout<<"Error! Retry enter ambient temperature: ";
        std::cin>>temperature;
    }
    controller_->setAmbientTemperature(temperature);
}
void View::showSetTest(){
    int choose;
    std::cout<<"Choose test:\n";
    std::cout<<"1. Engine maximum power test.\n";
    std::cout<<"2. Engine heating test.\n";
    std::cin>>choose;
    while(!std::cin && (choose!= 1 || choose !=2)) {
        std::cout<<"Error! Enter file ambient temperature: ";
        std::cin>>choose;
    }
    controller_->setTest(static_cast<Test>(choose));
    controller_->startTest();
}