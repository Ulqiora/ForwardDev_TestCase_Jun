#pragma once
#include <vector>

struct EngineInfo{
    EngineInfo() {}
    double motorMomentOfInertia_ = 0.0;
    std::vector<double> MotorTorquePoints_;
    std::vector<double> SpeedPoints_;
    double upLimitTemperature_ = 0.0;
    double Hm_ = 0.0;
    double Hv_ = 0.0;
    double C = 0.0;
};