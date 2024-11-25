#include "fleet.h"
#include <iostream>
std::string stringCopy(const std::string &source, int start, int end)
{
    return source.substr(start, end - start + 1);
}
Fleet::Fleet(int size, std::string path):maxSize(size)
{
    

    std::ifstream TXT(path.c_str());

    std::string line;

    cars = new Car *[maxSize];
    buses = new Bus *[maxSize];
    trucks = new Truck *[maxSize];

    for (int i = 0; i < maxSize; i++)
    {
        cars[i] = NULL;
        buses[i] = NULL;
        trucks[i] = NULL;
    }
    currBuses = 0;
    currCars = 0;
    currTrucks = 0;

    while (getline(TXT, line))
    {

        std::string first, second, third, fourth, fifth;
        std::stringstream oss;

        int start = 0, end = 0;

        end = line.find('#', start);

        first = stringCopy(line, start, end - 1);

        if (first == "Car"&&currCars<maxSize)
        {

            start = end + 1;
            end = line.find('#', start);

            second = stringCopy(line, start, end - 1);

            start = end + 1;
            end = line.find('#', start);

            third = stringCopy(line, start, end - 1);

            std::stringstream othird(third);
            double thirdd;
            othird >> thirdd;

            start = end + 1;
            end = line.find('#', start);

            fourth = stringCopy(line, start, end - 1);

            std::stringstream ofour(fourth);
            double forth;
            ofour >> forth;

            start = end + 1;
            end = line.find('#', start);

            fifth = stringCopy(line, start, end - 1);

            std::stringstream os(fifth);
            int fife;
            os >> fife;

            cars[currCars] = new Car(second, thirdd, forth, fife);
            currCars++;
        }
        else if (first == "Bus"&&currBuses<maxSize)
        {

            start = end + 1;
            end = line.find('#', start);

            second = stringCopy(line, start, end - 1);

            start = end + 1;
            end = line.find('#', start);

            third = stringCopy(line, start, end - 1);

            std::stringstream othird(third);
            double thirdd;
            othird >> thirdd;

            start = end + 1;
            end = line.find('#', start);

            fourth = stringCopy(line, start, end - 1);

            std::stringstream ofour(fourth);
            double forth;
            ofour >> forth;

            start = end + 1;
            end = line.find('#', start);

            fifth = stringCopy(line, start, end - 1);

            std::stringstream os(fifth);
            int fife;
            os >> fife;

            buses[currBuses] = new Bus(second, thirdd, forth, fife);
            currBuses++;
        }
        else if (first == "Truck"&&(currTrucks<maxSize))
        {

            start = end + 1;
            end = line.find('#', start);

            second = stringCopy(line, start, end - 1);

            start = end + 1;
            end = line.find('#', start);

            third = stringCopy(line, start, end - 1);

            std::stringstream othird(third);
            double thirdd;
            othird >> thirdd;

            start = end + 1;
            end = line.find('#', start);

            fourth = stringCopy(line, start, end - 1);

            std::stringstream ofour(fourth);
            double forth;
            ofour >> forth;

            start = end + 1;
            end = line.find('#', start);

            fifth = stringCopy(line, start, end - 1);

            std::stringstream os(fifth);
            double fife;
            os >> fife;

            trucks[currTrucks] = new Truck(second, thirdd, forth, fife);
            currTrucks++;
        }
    }
};
Fleet::Fleet(const Fleet *toCopy)
{

    currBuses = toCopy->getCurrentBuses();
    currCars = toCopy->getCurrentCars();
    currTrucks = toCopy->getCurrentTrucks();
    maxSize = toCopy->getMaxsize();

    cars = new Car *[maxSize];
    buses = new Bus *[maxSize];
    trucks = new Truck *[maxSize];

    for (int i = 0; i < maxSize; i++)
    {
        cars[i] = NULL;
        buses[i] = NULL;
        trucks[i] = NULL;
    }

    for (int i = 0; i < currCars; i++)
    {
        cars[i] = new Car(toCopy->getCars()[i]->getRegistration(),
                          toCopy->getCars()[i]->getGasUsage(),
                          toCopy->getCars()[i]->getMileage(),
                          toCopy->getCars()[i]->getTopSpeed());
    }

    for (int i = 0; i < currBuses; i++)
    {
        buses[i] = new Bus(toCopy->getBuses()[i]->getRegistration(),
                           toCopy->getBuses()[i]->getGasUsage(),
                           toCopy->getBuses()[i]->getMileage(),
                           toCopy->getBuses()[i]->getSeats());
    }

    for (int i = 0; i < currTrucks; i++)
    {
        trucks[i] = new Truck(toCopy->getTrucks()[i]->getRegistration(),
                              toCopy->getTrucks()[i]->getGasUsage(),
                              toCopy->getTrucks()[i]->getMileage(),
                              toCopy->getTrucks()[i]->getCarry());
    }

    // currBuses = toCopy->getCurrentBuses();
    // currCars = toCopy->getCurrentCars();
    // currTrucks = toCopy->getCurrentTrucks();
    // maxSize = toCopy->getMaxsize();
    // cars = new Car *[maxSize];
    // buses = new Bus *[maxSize];
    // trucks = new Truck *[maxSize];

    // // for (int i = 0; i < currBuses; i++)
    // // {
    // //     delete buses[i];
    // // }

    // // for (int i = 0; i < currCars; i++)
    // // {
    // //     delete cars[i];
    // // }
    // // for (int i = 0; i < currTrucks; i++)
    // // {

    // //     delete trucks[i];
    // // }

    // for (int i = 0; i < maxSize; i++)
    // {

    //     cars[i] = NULL;
    //     buses[i] = NULL;
    //     trucks[i] = NULL;
    // }
    // // delete[] cars;
    // // delete[] buses;
    // // delete[] trucks;

    // for (int i = 0; i < currCars; i++)
    // {
    //     cars[i] = new Car(toCopy->getCars()[i]->getRegistration(), toCopy->getCars()[i]->getGasUsage(), toCopy->getCars()[i]->getMileage(), toCopy->getCars()[i]->getTopSpeed());
    // }

    // for (int i = 0; i < currBuses; i++)
    // {
    //     buses[i] = new Bus(toCopy->getBuses()[i]->getRegistration(), toCopy->getBuses()[i]->getGasUsage(), toCopy->getBuses()[i]->getMileage(), toCopy->getBuses()[i]->getSeats());
    // }

    // for (int i = 0; i < currTrucks; i++)
    // {
    //     trucks[i] = new Truck(toCopy->getTrucks()[i]->getRegistration(), toCopy->getTrucks()[i]->getGasUsage(), toCopy->getTrucks()[i]->getMileage(), toCopy->getTrucks()[i]->getCarry());
    // }

    //  std::cout << "copy constructor done" << std::endl;
};
Fleet::~Fleet()
{

    for (int i = 0; i < currCars; i++)
    {
        if (cars[i] != NULL)
            delete cars[i];
        cars[i] = NULL;
    }
    for (int i = 0; i < currBuses; i++)
    {
        if (buses[i] != NULL)
            delete buses[i];
        buses[i] = NULL;
    }
    for (int i = 0; i < currTrucks; i++)
    {
        if (trucks[i] != NULL)
            delete trucks[i];
        trucks[i] = NULL;
    }
    delete[] cars;
    cars = NULL;
    delete[] buses;
    buses = NULL;

    delete[] trucks;
    trucks = NULL;
};
Car **Fleet::getCars() const { return cars; };
Bus **Fleet::getBuses() const { return buses; };
Truck **Fleet::getTrucks() const { return trucks; };

int Fleet::getCurrentCars() const { return currCars; };
int Fleet::getCurrentBuses() const { return currBuses; };
int Fleet::getCurrentTrucks() const { return currTrucks; };

int Fleet::getMaxsize() const { return maxSize; };
bool Fleet::addCar(const Car *carToAdd)
{
    if (currCars == maxSize || carToAdd == NULL)
        return false;
    else
    {
        cars[currCars++] = new Car(carToAdd->getRegistration(),
                                   carToAdd->getGasUsage(),
                                   carToAdd->getMileage(),
                                   carToAdd->getTopSpeed());
        return true;
    }
};
bool Fleet::addBus(const Bus *busToAdd)
{

    if (currBuses == maxSize || busToAdd == NULL)
        return false;
    else
    {
        buses[currBuses++] = new Bus(busToAdd->getRegistration(),
                                     busToAdd->getGasUsage(),
                                     busToAdd->getMileage(),
                                     busToAdd->getSeats());
        return true;
    }
};
bool Fleet::addTruck(const Truck *truckToAdd)
{

    if (currTrucks == maxSize || truckToAdd == NULL)
        return false;
    else
    {
        trucks[currTrucks++] = new Truck(truckToAdd->getRegistration(),
                                         truckToAdd->getGasUsage(),
                                         truckToAdd->getMileage(),
                                         truckToAdd->getCarry());
        return true;
    }
};

std::string Fleet::fleetInfo()
{

    std::stringstream os;

    os << "Cars:\n";
    for (int i = 0; i < currCars; i++)
    {
        os << "Registration: " << cars[i]->getRegistration() << " Mileage: " << cars[i]->getMileage() << " Top Speed: " << cars[i]->getTopSpeed() << "\n";
    }

    os << "\nBuses:\n";

    for (int i = 0; i < currBuses; i++)
    {
        os << "Registration: " << buses[i]->getRegistration() << " Mileage: " << buses[i]->getMileage() << " Seats: " << buses[i]->getSeats() << "\n";
    }
    os << "\nTrucks:\n";
    for (int i = 0; i < currTrucks; i++)
    {
        os << "Registration: " << trucks[i]->getRegistration() << " Mileage: " << trucks[i]->getMileage() << " Carry: ";
        double carry = trucks[i]->getCarry();
        os << carry;
        os << "\n";
    }

    return os.str();
};