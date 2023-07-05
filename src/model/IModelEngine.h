#pragma once

class IModelEngine {
public:
	virtual void start() = 0;
	virtual void setSimulationStep(double step) = 0;
	virtual void calcNextStep() = 0;
	virtual double getPower() const = 0;
	virtual double getRotationSpeed() const = 0;
	virtual double getAcceleration() const = 0;
	virtual double getTemperature() const = 0;
	virtual void setAmbientTemperature(double temperature) = 0;
	virtual bool overheated() const = 0;
	virtual ~IModelEngine() = default;
};
