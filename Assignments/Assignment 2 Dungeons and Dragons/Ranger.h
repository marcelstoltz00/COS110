#ifndef RANGER_H
#define RANGER_H

#include "Player.h"

class Ranger : public Player {
   private:
    virtual void operator>>(const Party& otherParty) const;
    virtual void operator>>=(Party& otherParty);

    virtual void operator<<(const Party& otherParty) const;
    virtual void operator<<=(Party& otherParty);

   protected:
    int numShots;

   public:
    Ranger(std::string name, int health, int power, int speed, int numShots);
    Ranger(const Ranger& other);
    Ranger& operator=(const Ranger& other);
    virtual Player* clone() const;
    virtual ~Ranger();

    virtual operator std::string() const;
};

#endif