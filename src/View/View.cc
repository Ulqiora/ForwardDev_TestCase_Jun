#include "View.h"

#include "../Controller/Controller.h"

void View::show() {
    showFileConfigConsole();
    showSetTemperatureConsole();
    showSetTest();
}
void View::showFileConfigConsole() {
    std::string filename;
    std::cout << "Enter file configuration path of engine:";
    while (std::cin >> filename) {
        if (controller_->setFileConfig(filename)) {
            break;
        } else {
            std::cout << "File path is not correct or file is not valid.\n";
            std::cout << "Enter file configuration path of engine:";
        }
    }
}
void View::showSetTemperatureConsole() {
    std::string temperature;
    size_t pos = 0;
    double temperature_v;
    std::cout << "Enter file ambient temperature:";
    while (true) {
        std::cin >> temperature;
        try {
            temperature_v = std::stod(temperature,&pos);
            std::cout<<pos<<"  "<<temperature.size()<<'\n';
            if(pos == 0 || pos != temperature.size())
                throw std::invalid_argument("");
            break;
        } catch (const std::exception& ignore) {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Error! Retry enter ambient temperature: ";
        }
    }
    controller_->setAmbientTemperature(temperature_v);
}
void View::showSetTest() {
    std::string choose_s;
    size_t pos = 0, choose;
    std::cout << "Choose test:\n";
    std::cout << "1. Engine heating test.\n";
    std::cout << "2. Engine maximum power test.\n";
    while (true) {
        std::cin >> choose_s;
        try {
            choose = std::stod(choose_s,&pos);
            std::cout<<pos<<"  "<<choose_s.size()<<'\n';
            if(pos == 0 || pos != choose_s.size())
                throw std::invalid_argument("Error! Founded incorrect symbols! Retry: ");
            if(choose != 1 && choose != 2)
                throw std::invalid_argument("Error! Choose 1 or 2: ");
            break;
        } catch (const std::exception& e) {
            std::cin.clear();
            std::cin.ignore();
            std::cout << e.what();
        }
    }
    controller_->setTest(static_cast<Test>(choose));
    controller_->startTest();
}