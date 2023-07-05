#include "LoaderConfig.h"

#include <iostream>
#include <string>
bool LoaderConfig::load(std::basic_istream<char>& stream) {
	info_ = EngineInfo();
	size_t numberOfPoints = 0;
	if (!(stream >> info_.motorMomentOfInertia_)) return false;
	if (!(stream >> numberOfPoints)) return false;
	info_.SpeedPoints_.reserve(numberOfPoints);
	info_.MotorTorquePoints_.reserve(numberOfPoints);
	double temp = 0.0;
	for (size_t i = 0; i < numberOfPoints; i++) {
		if (!(stream >> temp)) return false;
		info_.MotorTorquePoints_.push_back(temp);
		if ((i < (numberOfPoints - 1) && stream.peek() == ',') ||
			(i == (numberOfPoints - 1) && stream.peek() == '\n'))
			stream.ignore();
		else
			return false;
	}
	for (size_t i = 0; i < numberOfPoints; i++) {
		if (!(stream >> temp)) return false;
		info_.SpeedPoints_.push_back(temp);
		if ((i < (numberOfPoints - 1) && stream.peek() == ',') ||
			(i == (numberOfPoints - 1) && stream.peek() == '\n'))
			stream.ignore();
		else
			return false;
	}
	if (!(stream >> info_.upLimitTemperature_)) return false;
	if (!(stream >> info_.Hm_)) return false;
	if (!(stream >> info_.Hv_)) return false;
	if (!(stream >> info_.C)) return false;
	return true;
}

const EngineInfo& LoaderConfig::getResult() const { return info_; }

bool  LoaderConfig::validate() {
	if (info_.MotorTorquePoints_.size() != info_.SpeedPoints_.size()) return false;
	for (auto i : info_.MotorTorquePoints_) {
		if (i < 0.0) return false;
	}
	for (auto i : info_.SpeedPoints_) {
		if (i < 0.0) return false;
	}
	if (info_.upLimitTemperature_ < 0.0) return false;
	if (info_.Hm_ < 0.0) return false;
	if (info_.Hv_ < 0.0) return false;
	if (info_.C < 0.0) return false;
	return true;
}