#ifndef SIEGEWEAPON_H
#define SIEGEWEAPON_H

#include "Ranger.h"
class SiegeWeapon : public Ranger {
   private:
    virtual void operator>>(const Party& otherParty) const;
    virtual void operator>>=(Party& otherParty);

    virtual void operator<<(const Party& otherParty) const;
    virtual void operator<<=(Party& otherParty);

   protected:
    int** ammo;

   public:
    SiegeWeapon(std::string name, int health, int power, int speed, int numShots);
    SiegeWeapon(const SiegeWeapon& other);
    SiegeWeapon& operator=(const SiegeWeapon& other);
    virtual Player* clone() const;
    virtual ~SiegeWeapon();

    virtual operator std::string() const;
};

#endif