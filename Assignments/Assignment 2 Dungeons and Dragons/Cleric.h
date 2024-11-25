#ifndef CLERIC_H
#define CLERIC_H

#include "Support.h"

class Cleric : public Support {
   private:
    virtual void operator>>(const Party& otherParty) const;
    virtual void operator>>=(Party& otherParty);

    virtual void operator<<(const Party& otherParty) const;
    virtual void operator<<=(Party& otherParty);

   protected:
    int faith;

   public:
    Cleric(std::string name, int health, int power, int speed, int mana, int faith);
    Cleric(const Cleric& other);
    Cleric& operator=(const Cleric& other);
    virtual Player* clone() const;
    virtual ~Cleric();

    virtual operator std::string() const;
};

#endif