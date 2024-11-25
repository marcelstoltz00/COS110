#ifndef MELEEWARRIOR_H
#define MELEEWARRIOR_H

#include "Player.h"

class MeleeWarrior : public Player {
   private:
    virtual void operator>>(const Party& otherParty) const;
    virtual void operator>>=(Party& otherParty);

    virtual void operator<<(const Party& otherParty) const;
    virtual void operator<<=(Party& otherParty);

   protected:
    int armor;

   public:
    MeleeWarrior(std::string name, int health, int power, int speed, int armor);
    MeleeWarrior(const MeleeWarrior& other);
    MeleeWarrior& operator=(const MeleeWarrior& other);
    virtual Player* clone() const;
    virtual ~MeleeWarrior();

    virtual operator std::string() const;

    virtual void changeHealth(int change);
};

#endif