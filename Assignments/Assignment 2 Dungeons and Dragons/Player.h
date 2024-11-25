#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <sstream>
#include <string>

#include "Party.h"
#include "RandomNumberGenerator.h"

class Player {
    friend class Party;

   private:
    virtual void operator>>(const Party& otherParty) const = 0;
    virtual void operator>>=(Party& otherParty) = 0;

    virtual void operator<<(const Party& otherParty) const = 0;
    virtual void operator<<=(Party& otherParty) = 0;

   protected:
    std::string name;
    int health;
    int power;
    int speed;

   public:
    RandomNumberGenerator* dice;
    Player(std::string name, int health, int power, int speed);
    Player(const Player& other);
    Player& operator=(const Player& other);
    virtual Player* clone() const = 0;
    virtual ~Player();

    friend std::ostream& operator<<(std::ostream& os, const Player& player);
    virtual operator std::string() const;

    virtual void changeHealth(int change);
    void changePower(int change);
    void changeSpeed(int change);
    std::string getName();
    int getHealth();
};

#endif