#include "Barbarian.h"

Barbarian::Barbarian(std::string name, int health, int power, int speed, int armor)
    : MeleeWarrior(name, health, power, speed, armor)
{
    rageMeters = new int[speed];
    for (int i = 0; i < speed; i++)
    {
        rageMeters[i] = 0;
    }
}

Barbarian::Barbarian(const Barbarian &other)
    : MeleeWarrior(other)
{
    rageMeters = new int[speed];
    for (int i = 0; i < speed; i++)
    {
        rageMeters[i] = other.rageMeters[i];
    }
}

Barbarian &Barbarian::operator=(const Barbarian &other)
{
    if (this == &other)
    {
        return *this;
    }
    MeleeWarrior::operator=(other);
    int newspeed = other.speed;

    delete[] rageMeters;
    rageMeters = new int[newspeed];
    for (int i = 0; i < newspeed; i++)
    {
        rageMeters[i] = other.rageMeters[i];
    }

    return *this;
}

Player *Barbarian::clone() const
{
    return new Barbarian(*this);
}

Barbarian::~Barbarian()
{
    delete[] rageMeters;
}

Barbarian::operator std::string() const
{
    std::ostringstream ss;
    ss << "Barbarian:" << MeleeWarrior::operator std::string()
       << ",rageMeters=[";

    for (int i = 0; i < speed; i++)
    {
        // if (rageMeters)
        ss << rageMeters[i];
        if (i != speed - 1)
        {
            ss << ",";
        }
    }
    //  ss << rageMeters[speed - 2]<<","<<rageMeters[speed-1];

    ss << "]";
    return ss.str();
}

void Barbarian::operator>>(const Party &otherParty) const
{
    int numActions = speed;
    int numparty = otherParty.getNumMembers();
    int target = 0;
    //   Barbarian copy(*this);
    int *nrageMeters = new int[speed];
    for (int i = 0; i < speed; i++)
    {
        nrageMeters[i] = rageMeters[i];
    }

    for (int i = 0; i < numActions; i++)
    {
        if (otherParty.getNumMembers() == 0)
        {
            return;
        }

        int valofRage = 0;

        for (int k = 0; k < speed; k++)
        {
            if (nrageMeters[k] > 0)
            {
                valofRage += nrageMeters[k];
            }
        }
        int dicenum = dice->nextInt();
        int damage = 0;
        if (dicenum == 20)
        {
            damage = 4 * power * valofRage;
        }
        else if (dicenum >= 13)
        {
            damage = 3 * power * valofRage;
        }
        else if (dicenum >= 6)
        {
            damage = 2 * power * valofRage;
        }
        else
        {
            damage = 1 * power * valofRage;
        }

        std::cout << name << " rolled a " << dicenum << " and does " << damage << " damage to " << otherParty[target]->getName() << std::endl;
        target++;
        target = target % numparty;

        for (int pp = 0; pp < speed; pp++)
        {
            int nextroll = dice->nextInt();
            nrageMeters[pp] += (nextroll / 4) - 2;
        }
    }

    delete[] nrageMeters;
}

void Barbarian::operator<<(const Party &otherParty) const
{
    int numActions = speed;
    int numPartyMembers = otherParty.getNumMembers();
    int target = 0;

    for (int i = 0; i < numActions; i++)
    {
        if (numPartyMembers == 0)
        {
            return;
        }

        int dicenum = dice->nextInt();

        if (dicenum >= 15)
        {
            //   otherParty[target]->changePower(1);
            std::cout << name << " rolled a " << dicenum << " and powered up " << otherParty[target]->getName() << std::endl;
        }
        else
        {
            std::cout << name << " rolled a " << dicenum << " and failed to power up " << otherParty[target]->getName() << std::endl;
        }

        target = (target + 1) % numPartyMembers;
    }
}

void Barbarian::operator>>=(Party &otherParty)
{
    int numActions = speed;
    int numparty = otherParty.getNumMembers();
    int target = 0;

    for (int i = 0; i < numActions; i++)
    {
        if (otherParty.getNumMembers() == 0)
        {
            return;
        }
        int dicenum = dice->nextInt();
        int valofRage = 0;

        for (int k = 0; k < speed; k++)
        {
            if (rageMeters[k] > 0)
            {
                valofRage += rageMeters[k];
            }
        }

        int damage = 0;
        if (dicenum == 20)
        {
            damage = 4 * power * valofRage;
        }
        else if (dicenum >= 13)
        {
            damage = 3 * power * valofRage;
        }
        else if (dicenum >= 6)
        {
            damage = 2 * power * valofRage;
        }
        else
        {
            damage = 1 * power * valofRage;
        }

        otherParty[target]->changeHealth(-damage);
        std::cout << name << " rolled a " << dicenum << " and does " << damage << " damage to " << otherParty[target]->getName() << std::endl;
        target = (target + 1) % numparty;

        for (int pp = 0; pp < speed; pp++)
        {
            int nextroll = dice->nextInt();
            rageMeters[pp] += (nextroll / 4) - 2;
        }
    }

    for (int i = 0; i < otherParty.getNumMembers(); i++)
    {
        if (otherParty[i])
        {
            if (otherParty[i]->getHealth() <= 0)
            {
                otherParty.operator-=(i);
                i--;
            }
        }
    }
}

void Barbarian::operator<<=(Party &otherParty)
{
    int numActions = speed;
    int numPartyMembers = otherParty.getNumMembers();
    int target = 0;

    for (int i = 0; i < numActions; i++)
    {
        if (numPartyMembers == 0)
        {
            return;
        }

        int dicenum = dice->nextInt();

        if (dicenum >= 15)
        {
            //  otherParty[target]->changePower(1);
            std::cout << name << " rolled a " << dicenum << " and powered up " << otherParty[target]->getName() << std::endl;
        }
        else
        {
            std::cout << name << " rolled a " << dicenum << " and failed to power up " << otherParty[target]->getName() << std::endl;
        }

        target = (target + 1) % numPartyMembers;
    }
}
