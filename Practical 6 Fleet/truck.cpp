#include "truck.h"

Truck::Truck(std::string registration, double gasUsage, double mileage, double carry) : Vehicle(registration, gasUsage, mileage)
{

    this->carry = carry;
};
Truck::~Truck() {};
double Truck::getCarry() const
{
    return carry;
};
void Truck::calculateCost()
{

    double decay = 0.010;
    double basecost = 0;
    if (carry > 2 && carry <= 5)
        basecost = 52000;
    else
    {
        if (carry <= 2)
            basecost = 35000;
        else
            basecost = 78000;
    }

    double costMil = basecost * std::exp(-1 * (Vehicle::getMileage())*decay);

    double newcost = std::max(costMil, basecost);
    Vehicle::setCost(newcost + (10000 / (Vehicle::getGasUsage())));
};
std::string Truck::vehicleInfo()
{

    std::stringstream os;

    os << "R: " << Truck::getRegistration() << " G: " << Truck::getGasUsage() << " M: " << Truck::getMileage();

    double carry = Truck::getCarry();
    if (carry == static_cast<int>(carry))
        os << " C: " << static_cast<int>(carry) << ".0";
    else
        os << " C: " << carry;

    return os.str();
};
