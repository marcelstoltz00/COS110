#ifndef BARBARIAN_H
#define BARBARIAN_H

#include "MeleeWarrior.h"

class Barbarian : public MeleeWarrior {
   private:
    virtual void operator>>(const Party& otherParty) const;
    virtual void operator>>=(Party& otherParty);

    virtual void operator<<(const Party& otherParty) const;
    virtual void operator<<=(Party& otherParty);

   protected:
    int* rageMeters;

   public:
    Barbarian(std::string name, int health, int power, int speed, int armor);
    Barbarian(const Barbarian& other);
    Barbarian& operator=(const Barbarian& other);
    virtual Player* clone() const;
    virtual ~Barbarian();

    virtual operator std::string() const;
};

#endif