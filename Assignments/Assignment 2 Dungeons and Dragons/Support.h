#ifndef SUPPORT_H
#define SUPPORT_H

#include "Player.h"
class Support : public Player {
   private:
    virtual void operator>>(const Party& otherParty) const;
    virtual void operator>>=(Party& otherParty);

    virtual void operator<<(const Party& otherParty) const;
    virtual void operator<<=(Party& otherParty);

   protected:
    int mana;

   public:
    Support(std::string name, int health, int power, int speed, int mana);
    Support(const Support& other);
    Support& operator=(const Support& other);
    virtual Player* clone() const;
    virtual ~Support();

    virtual operator std::string() const;
};

#endif