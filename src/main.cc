#include "Controller/Controller.h"
#include <filesystem>
#include <fstream>
#include <iostream>

#include "View/View.h"
int main(){
    ControllerView c;
    View v(&c);
    v.show();
    return 0;
}