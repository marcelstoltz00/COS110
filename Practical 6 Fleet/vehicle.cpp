#include "vehicle.h"

Vehicle::Vehicle(std::string registration, double gasUsage, double mileage)
{

    this->gasUsage = gasUsage;
    this->mileage = mileage;
    this->registration = registration;
    cost = -1.0;
};
Vehicle::~Vehicle() {};
std::string Vehicle::getRegistration() const
{

    return registration;
};
double Vehicle::getGasUsage() const { return gasUsage; };
double Vehicle::getMileage() const { return mileage; };
double Vehicle::getCost() const
{
    return cost;
};
void Vehicle::setCost(double cost) { this->cost = cost; };

