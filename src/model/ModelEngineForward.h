#pragma once

#include <algorithm>
#include <iostream>
#include "Config/EngineInfo.h"
#include "IModelEngine.h"

class ModelEngineForward : public IModelEngine {
public:
	ModelEngineForward() = delete;
	ModelEngineForward(const EngineInfo&);
	ModelEngineForward(ModelEngineForward&&) = default;
	ModelEngineForward(const ModelEngineForward&) = default;
	ModelEngineForward& operator=(ModelEngineForward&&) = default;
	ModelEngineForward& operator=(const ModelEngineForward&) = default;
	virtual ~ModelEngineForward() {}

	virtual void start() override;
	virtual void setSimulationStep(double step) override;
	virtual void calcNextStep() override;
	virtual double getPower() const override;
	virtual double getRotationSpeed() const override;
	virtual double getAcceleration() const override;
	virtual double getTemperature() const override;
	virtual void setAmbientTemperature(double temperature) override;
	virtual bool overheated() const override;

	double getMotorTorque();
private:
	double power_ ;
	double rotationStep_ ;
	double acceleration_ ;
	double temperature_ ;
	double modelingStep_ ;
	double torque_ ;
	double coolingSpeed_ ;
	double heatingSpeed_ ;
	double ambientTemperature_;
	EngineInfo info_;
};