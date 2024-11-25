#ifndef WIZARD_H
#define WIZARD_H

#include "Ranger.h"
class Wizard : public Ranger {
   private:
    virtual void operator>>(const Party& otherParty) const;
    virtual void operator>>=(Party& otherParty);

    virtual void operator<<(const Party& otherParty) const;
    virtual void operator<<=(Party& otherParty);

   protected:
    int mana;

   public:
    Wizard(std::string name, int health, int power, int speed, int numShots, int mana);
    Wizard(const Wizard& other);
    Wizard& operator=(const Wizard& other);
    virtual Player* clone() const;
    virtual ~Wizard();

    virtual operator std::string() const;
};

#endif