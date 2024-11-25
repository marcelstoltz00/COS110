#include "rental.h"
#include <iostream>
Rental::Rental(int maxBookings, int bookingSize, std::string path)
{
    this->maxBookings = maxBookings;
    bookings = new Fleet *[maxBookings];
    currBookings = 0;
    for (int i = 0; i < maxBookings; i++)
    {
        bookings[i] = NULL;
    }
    bookings[currBookings] = new Fleet(bookingSize, path);
    currBookings++;
};
Rental::~Rental()
{
    for (int i = 0; i < currBookings; i++)
    {
        if (bookings[i] == NULL)
        {
        }
        else
        {
            delete bookings[i];
            bookings[i] = NULL;
        }
    }
    delete[] bookings;
    bookings = NULL;
};
Fleet **Rental::getBookings() const { return bookings; };
int Rental::getCurrentBookings() const { return currBookings; };
int Rental::getMaxBookings() const { return maxBookings; };
bool Rental::newBooking(Fleet *bookingFleet)
{

    if (maxBookings == currBookings || bookingFleet == NULL)
        return false;
    else
    {
        bookings[currBookings] = new Fleet(bookingFleet);
        currBookings++;
        return true;
        // Fleet **fleetnew = new Fleet *[maxBookings];

        // for (int i = 0; i < maxBookings; i++)
        // {
        //     if (i != currBookings)
        //     {
        //         fleetnew[i] = bookings[i];
        //     }
        //     else
        //     {
        //         fleetnew[i] = new Fleet(bookingFleet);
        //     }
        // }

        // delete[] bookings;
        // currBookings++;

        // bookings = fleetnew;
        // return true;

        // return true;
    }
};
bool Rental::cancelBooking(int index)
{
    if (index < currBookings && index >= 0 && index < maxBookings)
    {

        Fleet **fleetnew = new Fleet *[maxBookings];

        for (int j = 0; j < index; j++)
        {

            fleetnew[j] = bookings[j];
        }
        delete bookings[index];

        for (int k = index + 1; k < maxBookings; k++)
        {

            fleetnew[k - 1] = bookings[k];
        }
        int p = maxBookings - 1;
        fleetnew[p] = NULL;

        delete [] bookings;

        currBookings--;
        bookings = fleetnew;
        return true;
    }
    return false;
};
std::string Rental::bookingSummary()
{
    std::stringstream os;
    // std::cout << "here" << std::endl;
    for (int i = 0; i < currBookings; i++)
    {

        if (bookings[i] != NULL)
        {
            // { std::cout << "here1" << std::endl;
            os << "Booking: " << i;
            // std::cout << "here2" << std::endl;
            os << " Cars: " << bookings[i]->getCurrentCars();
            // std::cout << "here3" << std::endl;
            os << " Buses: " << bookings[i]->getCurrentBuses() << " Trucks: ";
            // std::cout << "here4" << std::endl;
            os << bookings[i]->getCurrentTrucks();
            //    std::cout << "here5" << std::endl;
            os << " Total Cost: " << calculateBookingCost(i) << "\n";
        }
    }
    return os.str();
};
double Rental::calculateBookingCost(int index)
{
    double cost = 0;

    if (index < currBookings && index >= 0)
    {
        for (int i = 0; i < bookings[index]->getCurrentCars(); i++)
        {

            bookings[index]->getCars()[i]->calculateCost();
            cost += bookings[index]->getCars()[i]->getCost();
        }
        for (int i = 0; i < bookings[index]->getCurrentBuses(); i++)
        {

            bookings[index]->getBuses()[i]->calculateCost();
            cost += bookings[index]->getBuses()[i]->getCost();
        }
        for (int i = 0; i < bookings[index]->getCurrentTrucks(); i++)
        {

            bookings[index]->getTrucks()[i]->calculateCost();
            cost += bookings[index]->getTrucks()[i]->getCost();
        }

        return cost;
    }
    else
        return -100;
};