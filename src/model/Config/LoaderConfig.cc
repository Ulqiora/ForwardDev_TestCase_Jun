#include "LoaderConfig.h"

#include <string>
#include <iostream>
bool LoaderConfig::load(std::basic_istream<char>& stream){
    info_ = EngineInfo();
    if(!(stream>>info_.motorMomentOfInertia_)) return false;
    if(!(stream>>info_.motorMomentOfInertia_)) return false;
    return true;
}

const EngineInfo& LoaderConfig::getResult() const{
    return info_;
}