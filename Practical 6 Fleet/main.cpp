#include <cstdio>
#include <iostream>

#include "rental.h"

void testClasses()
{

    Car car("CAR999", 8.5, 15000, 160);

    if (car.getRegistration() == "CAR999")
        std::cout << "Test 1: Passed\n";
    else
        std::cout << "Test 1: Failed\n";

    if (fabs(car.getGasUsage() - 8.5) == 0)
        std::cout << "Test 2: Passed\n";
    else
        std::cout << "Test 2: Failed\n";

    if (fabs(car.getMileage() - 15000) == 0)
        std::cout << "Test 3: Passed\n";
    else
        std::cout << "Test 3: Failed\n";

    if (car.getTopSpeed() == 160)
        std::cout << "Test 4: Passed\n";
    else
        std::cout << "Test 4: Failed\n";

    car.calculateCost();
    double carCost = car.getCost();
    double expectedCarCost = std::max(6000.0 * exp(-15000 * 0.015), 6000.0) + (500.0 / 8.5);
    if (fabs(carCost - expectedCarCost) == 0)
        std::cout << "Test 5: Passed\n";
    else
        std::cout << "Test 5: Failed\n";

    if (car.vehicleInfo() == "R: CAR999 G: 8.5 M: 15000 S: 160")
        std::cout << "Test 6: Passed\n";
    else
        std::cout << "Test 6: Failed\n";

    Bus bus("BUS888", 18.0, 6000, 35);

    if (bus.getRegistration() == "BUS888")
        std::cout << "Test 7: Passed\n";
    else
        std::cout << "Test 7: Failed\n";

    if (fabs(bus.getGasUsage() - 18.0) == 0)
        std::cout << "Test 8: Passed\n";
    else
        std::cout << "Test 8: Failed\n";

    if (fabs(bus.getMileage() - 6000) == 0)
        std::cout << "Test 9: Passed\n";
    else
        std::cout << "Test 9: Failed\n";

    if (bus.getSeats() == 35)
        std::cout << "Test 10: Passed\n";
    else
        std::cout << "Test 10: Failed\n";

    bus.calculateCost();
    double busCost = bus.getCost();
    double expectedBusCost = std::max(30000.0 * exp(-6000 * 0.025), 30000.0) + (500.0 / 18.0);
    if (fabs(busCost - expectedBusCost) == 0)
        std::cout << "Test 11: Passed\n";
    else
        std::cout << "Test 11: Failed\n";

    if (bus.vehicleInfo() == "R: BUS888 G: 18 M: 6000 S: 35")
        std::cout << "Test 12: Passed\n";
    else
        std::cout << "Test 12: Failed\n";

    Truck truck("TRK777", 9.0, 25000, 4.0);

    if (truck.getRegistration() == "TRK777")
        std::cout << "Test 13: Passed\n";
    else
        std::cout << "Test 13: Failed\n";

    if (fabs(truck.getGasUsage() - 9.0) == 0)
        std::cout << "Test 14: Passed\n";
    else
        std::cout << "Test 14: Failed\n";

    if (fabs(truck.getMileage() - 25000) == 0)
        std::cout << "Test 15: Passed\n";
    else
        std::cout << "Test 15: Failed\n";

    if (fabs(truck.getCarry() - 4.0) == 0)
        std::cout << "Test 16: Passed\n";
    else
        std::cout << "Test 16: Failed\n";

    truck.calculateCost();
    double truckCost = truck.getCost();
    double expectedTruckCost = std::max(52000.0 * exp(-25000 * 0.01), 52000.0) + 1000.0 / 9.0;
    if (fabs(truckCost - expectedTruckCost) == 0)
        std::cout << "Test 17: Passed\n";
    else
        std::cout << "Test 17: Failed\n";

    if (truck.vehicleInfo() == "R: TRK777 G: 9 M: 25000 C: 4.0")
        std::cout << "Test 18: Passed\n";
    else
        std::cout << truck.vehicleInfo();
}

void testRental()
{

    Rental rental(5, 10, "fleet.txt");
  //  std::cout<<"here"<<std::endl;

    std::cout << "Test 1: Booking Summary Initial\n";
    std::cout << rental.bookingSummary();

    Fleet *newFleet = new Fleet(10, "vehicles.txt");

    std::cout << "\nTest 2: New Booking\n";
    std::cout << (rental.newBooking(newFleet) ? "New booking added.\n" : "Failed to add new booking.\n");

    std::cout << "\nTest 3: Booking Summary After New Booking\n";
    std::cout << rental.bookingSummary();

    std::cout << "\nTest 4: Cancel Booking\n";
    std::cout << (rental.cancelBooking(0) ? "Booking cancelled.\n" : "Failed to cancel booking.\n");

    std::cout << "\nTest 5: Booking Summary After Cancellation\n";
    std::cout << rental.bookingSummary();

    std::cout << "\nTest 6: Calculate Booking Cost\n";
    std::cout << "Booking Cost for index 0: " << rental.calculateBookingCost(0) << "\n";




};
void testFleet()
{
   
    Fleet f1(10, "fleet.txt");
    std::cout << "Test 1: ";
    std::cout << f1.getCurrentCars() << std::endl
              << f1.getCurrentBuses() << std::endl
              << f1.getCurrentTrucks() << std::endl;
    std::cout << "Test 2: ";
    Car *newCar = new Car("NEW123", 10.0, 1000, 150);
    std::cout << (f1.addCar(newCar) ? "Passed\n" : "Failed\n");

    std::cout << "Test 3: ";
    Bus *newBus = new Bus("BUS123", 15.0, 2000, 30);
    std::cout << (f1.addBus(newBus) ? "Passed\n" : "Failed\n");

    std::cout << "Test 4: ";
    Truck *newTruck = new Truck("TRK123", 20.0, 3000, 500);
    std::cout << (f1.addTruck(newTruck) ? "Passed\n" : "Failed\n");

    std::cout << "Test 5: ";
    std::string info = f1.fleetInfo();
    std::cout << info;

    Fleet f2(&f1);
   std::cout << "Test 6: ";




  std::cout << ((f2.getCurrentCars() == f1.getCurrentCars() && f2.getCurrentBuses() == f1.getCurrentBuses() && f2.getCurrentTrucks() == f1.getCurrentTrucks()) ? "Passed\n" : "Failed\n");

   //    std::cout << "Test 6 after ";
};
int main()
{
    // Happy Testing
 testClasses();
  testFleet();
 testRental();
    return 0;
}