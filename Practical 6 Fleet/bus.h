#ifndef BUS_H
#define BUS_H

#include "vehicle.h"

class Bus : public Vehicle
{
private:
    int seats;

public:
    Bus(std::string registration, double gasUsage, double mileage, int seats);
    ~Bus();
    int getSeats() const;
    void calculateCost();
    std::string vehicleInfo();
};

#endif
