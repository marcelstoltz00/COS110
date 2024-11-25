#ifndef DRUID_H
#define DRUID_H

#include "Support.h"

class Druid : public Support {
   private:
    virtual void operator>>(const Party& otherParty) const;
    virtual void operator>>=(Party& otherParty);

    virtual void operator<<(const Party& otherParty) const;
    virtual void operator<<=(Party& otherParty);

   protected:
    int* treeants;
    int numTreeants;

   public:
    Druid(std::string name, int health, int power, int speed, int mana);
    Druid(const Druid& other);
    Druid& operator=(const Druid& other);
    virtual Player* clone() const;
    virtual ~Druid();

    virtual operator std::string() const;
};

#endif