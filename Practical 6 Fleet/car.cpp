#include "car.h"
Car::Car(std::string registration, double gasUsage, double mileage, int topSpeed) : Vehicle(registration, gasUsage, mileage)
{

    this->topSpeed = topSpeed;
};
Car::~Car() {};
int Car::getTopSpeed() const { return topSpeed; };
void Car::calculateCost()
{
    double decay = 0.015;
    double basecost = 0;
    if (topSpeed > 150 && topSpeed <= 200)
        basecost = 12000;
    else
    {
        if (topSpeed <= 150)
            basecost = 6000;
        else
            basecost = 20000;
    }

   double costMil = basecost * std::exp(-1 * (getMileage())*decay);

    double newcost = std::max(costMil, basecost);
    Vehicle::setCost(newcost + (500 / (Vehicle::getGasUsage())));
};
std::string Car::vehicleInfo()
{

   std::stringstream os;
   
   os<<"R: "<<Vehicle::getRegistration()<<" G: "<<Vehicle::getGasUsage() <<" M: "<<Vehicle::getMileage()<<" S: "<<topSpeed;

    return os.str();
};