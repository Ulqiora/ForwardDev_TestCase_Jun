#pragma once
#include "../Controller/Controller.h"
class View{
    public:
    View(ControllerView* c) : controller_(c){}
    void show();
    private:
    void showFileConfigConsole();
    void showSetTemperatureConsole();
    void showSetTest();
    void showErrorMessage(std::string message);
    ControllerView* controller_;
};