#pragma once
class TestVisitor;

class IModelEngine{
    public:
    virtual void accept(TestVisitor* visitor) = 0;
    double getCurrTemp() const {return currentTemp_;}
    double getRotationSpeed() const {return rotationSpeed_;}
    void setRotationSpeed(double speed) {rotationSpeed_ = speed;}
    void setCurrTemp(double temperature = 20.0) { currentTemp_ = temperature; }
    virtual ~IModelEngine() = default;
   private:
    double currentTemp_;
    double rotationSpeed_;
};