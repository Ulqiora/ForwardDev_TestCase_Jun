#pragma once
#include "../Controller/Controller.h"
class View{
    public:
    View() = delete;
    View(View&&) = delete;
    View(const View&) = delete;
    View& operator=(View&&) = delete;
    View& operator=(const View&) = delete;
    View(ControllerView* c) : controller_(c){}
    void show();
    private:
    void showFileConfigConsole();
    void showSetTemperatureConsole();
    void showSetTest();
    void showErrorMessage(std::string message);
    ControllerView* controller_;
};