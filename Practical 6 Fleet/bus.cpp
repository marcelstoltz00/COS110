#include "bus.h"

Bus::Bus(std::string registration, double gasUsage, double mileage, int seats) : Vehicle(registration, gasUsage, mileage)
{

    this->seats = seats;
};
Bus::~Bus() {};
int Bus::getSeats() const
{
    return seats;
};
void Bus::calculateCost()
{

    double decay = 0.025;
    double basecost = 0;
    if (seats > 26 && seats <= 40)
        basecost = 30000;
    else
    {
        if (seats <= 26)
            basecost = 20000;
        else
            basecost = 40000;
    }

     double costMil = basecost * std::exp(-1 * (Vehicle::getMileage())*decay);

    double newcost = std::max(costMil, basecost);
    Vehicle::setCost(newcost + (1000/ (Vehicle::getGasUsage())));
};
std::string Bus::vehicleInfo()
{

    std::stringstream os;

    os << "R: " << Vehicle::getRegistration() << " G: " << Vehicle::getGasUsage() << " M: " << Vehicle::getMileage() << " S: " << seats;

    return os.str();
};