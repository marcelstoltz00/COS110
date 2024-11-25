#ifndef RENTAL_H
#define RENTAL_H

#include "fleet.h"
#include <string>

class Rental
{
private:
    int maxBookings;
    int currBookings;
    Fleet **bookings;

public:
    Rental(int maxBookings, int bookingSize, std::string path);
    ~Rental();
    Fleet **getBookings()const;
    int getMaxBookings() const;
    int getCurrentBookings() const;
    bool newBooking(Fleet *bookingFleet);
    bool cancelBooking(int index);
    std::string bookingSummary();
    double calculateBookingCost(int index);
};

#endif