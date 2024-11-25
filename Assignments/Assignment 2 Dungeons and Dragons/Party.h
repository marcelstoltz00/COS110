#ifndef PARTY_H
#define PARTY_H

#include <iostream>
#include <sstream>
#include <string>

class Player;

class Party {
   protected:
    Player** members;
    int numMembers;

   public:
    Party();
    Party(const Player& player);
    Party(const Party& other);
    Party& operator=(const Party& other);
    ~Party();
    friend std::ostream& operator<<(std::ostream& os, const Party& party);

    int getNumMembers() const;
    Player* operator[](int index) const;
    Player* operator[](int index);

    Party operator+(Player& player) const;
    Party& operator+=(Player& player);
    Party operator-(int index) const;
    Party& operator-=(int index);

    Party operator>>(const Party& otherParty) const;
    Party& operator>>=(Party& otherParty);

    Party operator<<(const Party& otherParty) const;
    Party& operator<<=(Party& otherParty);
};

#endif