#pragma once
#include <vector>

struct EngineInfo{
    double motorMomentOfInertia_;
    std::vector<double> MotorTorquePoints_;
    std::vector<double> SpeedPoints_;
    double upLimitTemperature_;
    double Hm_;
    double Hv_;
    double C;
};