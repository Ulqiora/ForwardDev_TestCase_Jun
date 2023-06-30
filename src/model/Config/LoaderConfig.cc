#include "LoaderConfig.h"

#include <string>
#include <iostream>
bool LoaderConfig::load(std::basic_istream<char>& stream){
    info_ = EngineInfo();
    size_t numberOfPoints=0;
    if(!(stream>>info_.motorMomentOfInertia_)) return false;
    if(!(stream>>numberOfPoints)) return false;
    info_.SpeedPoints_.resize(numberOfPoints);
    info_.MotorTorquePoints_.resize(numberOfPoints);
    for(size_t i = 0; i < numberOfPoints; i++){
        if(!(stream>>info_.MotorTorquePoints_[i])) return false;
        if ((i < (numberOfPoints - 1) && stream.peek() == ',') ||
            (i == (numberOfPoints - 1) && stream.peek() == '\n'))
            stream.ignore();
        else return false;
    }
    for(size_t i = 0; i < numberOfPoints; i++){
        if(!(stream>>info_.SpeedPoints_[i])) return false;
        if ((i < (numberOfPoints - 1) && stream.peek() == ',') ||
            (i == (numberOfPoints - 1) && stream.peek() == '\n'))
            stream.ignore();
        else return false;
    }
    if(!(stream>>info_.upLimitTemperature_)) return false;
    if(!(stream>>info_.Hm_)) return false;
    if(!(stream>>info_.Hv_)) return false;
    if(!(stream>>info_.C)) return false;
    return true;
}

const EngineInfo& LoaderConfig::getResult() const{
    return info_;
}