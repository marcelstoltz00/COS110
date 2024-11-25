#include "Party.h"
#include "Player.h"
Party::Party()
{
    numMembers = 0;
    members = NULL;
};
Party::Party(const Player &player)
{

    numMembers = 1;

    members = new Player *[numMembers];

    members[0] = player.clone();
};
Party::Party(const Party &other)
{
    numMembers = other.numMembers;

    members = new Player *[numMembers];

    for (int i = 0; i < numMembers; i++)
    {
        members[i] = other.members[i]->clone();
    }
};
Party &Party::operator=(const Party &other)
{
    if (this == &other)
        return *this;

    for (int i = 0; i < numMembers; i++)
    {
        delete members[i];
    }
    delete[] members;
    this->numMembers = other.numMembers;

    members = new Player *[numMembers];

    for (int i = 0; i < numMembers; i++)
    {
        members[i] = other.members[i]->clone();
    }

    return *this;
};
Party::~Party()
{

    for (int i = 0; i < numMembers; i++)
    {
        delete members[i];
    }
    delete[] members;
};
std::ostream &operator<<(std::ostream &os, const Party &party)
{
    if (party.getNumMembers() > 0)
    {

        for (int i = 0; i < party.getNumMembers() - 1; i++)
        {
            if (party.members[i])
                os << *party.members[i] << std::endl;
        }
        os << *party.members[party.getNumMembers() - 1];
    }
    return os;
};

int Party::getNumMembers() const
{

    return numMembers;
};
Player *Party::operator[](int index) const
{

    if (index < 0 || index >= numMembers)
        return NULL;

    return members[index];
};
Player *Party::operator[](int index)
{

    if (index < 0 || index >= numMembers)
        return NULL;

    return members[index];
};

Party Party::operator+(Player &player) const
{
    Party newparty;
    newparty.numMembers = numMembers + 1;

    newparty.members = new Player *[numMembers + 1];

    for (int i = 0; i < numMembers; i++)
    {
        newparty.members[i] = members[i]->clone();
    }

    newparty.members[numMembers] = player.clone();

    return newparty;
};
Party &Party::operator+=(Player &player)
{
    *this = *this + player;
    return *this;
};
Party Party::operator-(int index) const
{
    if (index < 0 || index >= numMembers)
        return *this;

    Party newparty(*this);

    for (int i = index; i < newparty.numMembers - 1; i++)
    {
        if (newparty.members[i])
        {
            delete newparty.members[i];
        }

        newparty.members[i] = newparty.members[i + 1]->clone();
    }

    delete newparty.members[newparty.numMembers - 1];
    newparty.members[newparty.numMembers - 1] = NULL;
    newparty.numMembers--;

    return newparty;
}
Party &Party::operator-=(int index)
{

    if (index < numMembers && index >= 0)
    {

        int ic = 0;
        Player **memNew = new Player *[numMembers - 1];
        for (int i = 0; i < numMembers; i++)
        {
            if (i == index)
            {
                //  delete members[i];
            }
            else
            {
                memNew[ic++] = members[i];
            }
        }
        delete members[index];
        delete[] members;
        --numMembers;
        members = memNew;
    }

    return *this;
};

Party Party::operator>>(const Party &otherParty) const
{
    Party np(*this);

    for (int i = 0; i < numMembers; i++)
    {

        *np.members[i] >> otherParty;
    }

    return np;
};
Party &Party::operator>>=(Party &otherParty)
{

    for (int i = 0; i < numMembers; i++)
    {

        *members[i] >>= otherParty;
    }

    return *this;
};

Party Party::operator<<(const Party &otherParty) const
{
    Party np(*this);

    for (int i = 0; i < numMembers; i++)
    {

        *np.members[i] << otherParty;
    }

    return np;
};
Party &Party::operator<<=(Party &otherParty)
{

    for (int i = 0; i < numMembers; i++)
    {

        *members[i] <<= otherParty;
    }

    return *this;
};