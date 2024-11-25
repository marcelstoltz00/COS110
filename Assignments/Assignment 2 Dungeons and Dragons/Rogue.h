#ifndef ROGUE_H
#define ROGUE_H

#include "MeleeWarrior.h"
class Rogue : public MeleeWarrior {
   private:
    virtual void operator>>(const Party& otherParty) const;
    virtual void operator>>=(Party& otherParty);

    virtual void operator<<(const Party& otherParty) const;
    virtual void operator<<=(Party& otherParty);

   protected:
    int stealthTimer;

   public:
    Rogue(std::string name, int health, int power, int speed, int armor, int stealthTimer);
    Rogue(const Rogue& other);
    Rogue& operator=(const Rogue& other);
    virtual Player* clone() const;
    virtual ~Rogue();

    virtual operator std::string() const;

    virtual void changeHealth(int change);
};

#endif