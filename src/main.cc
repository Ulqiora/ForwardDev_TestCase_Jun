#include "model/Config/LoaderConfig.h"
#include <filesystem>
#include <fstream>
#include <iostream>
int main(){
    std::string filename="/mnt/d/GitHub/ForwardDev_TestCase_Jun/Config";
    ILoaderConfig* lc = new LoaderConfig();
    std::fstream file(filename);
    if(!file.is_open()) std::cout<< "File is not opened!";
    std::cout<<lc->load(file);
    return 0;
}