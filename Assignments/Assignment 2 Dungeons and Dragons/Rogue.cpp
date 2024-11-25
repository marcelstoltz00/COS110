#include "Rogue.h"

Rogue::Rogue(std::string name, int health, int power, int speed, int armor, int stealthTimer)
    : MeleeWarrior(name, health, power, speed, armor)
{

    this->stealthTimer = stealthTimer;
}

Rogue::Rogue(const Rogue &other) : MeleeWarrior(other)
{

    this->stealthTimer = other.stealthTimer;
}

Rogue &Rogue::operator=(const Rogue &other)
{
    if (this == &other)
        return *this;

    MeleeWarrior::operator=(other);
    stealthTimer = other.stealthTimer;
    return *this;
}

Player *Rogue::clone() const
{
    return new Rogue(*this);
}

Rogue::~Rogue() {}

Rogue::operator std::string() const
{
    std::stringstream ss;
    ss << "Rogue:" << static_cast<std::string>(MeleeWarrior::operator std::string()) << ",stealthTimer=" << stealthTimer;
    return ss.str();
}

void Rogue::changeHealth(int change)
{
    stealthTimer += 1;
    stealthTimer = stealthTimer % (2 * speed);
    if (!(change >= 0))
        if (!(stealthTimer <= speed))
            MeleeWarrior::changeHealth(change);
        else
            MeleeWarrior::changeHealth(change / 2);
    else
    {
        health = health + change;
    }
}

void Rogue::operator>>(const Party &otherParty) const
{
    // int copystealthtime = stealthTimer;
    int dicenum;
    int numActions = speed;
    Rogue copy(*this);
    int numparty = otherParty.getNumMembers();
    int target = 0;
    for (int i = 0; i < numActions; i++)
    {
        if (otherParty.getNumMembers() == 0)
        {
            return;
        }
        copy.stealthTimer = (copy.stealthTimer + 1) % (2 * speed);
        bool icheckdoubledamage = speed >= copy.stealthTimer;
        int dicenum = dice->nextInt();
        int damage = 0;

        //  if (copy.stealthTimer <= copy.speed)
        {
            if (dicenum == 20)
            {
                damage = 4 * power;
            }
            else if (dicenum >= 13)
            {
                damage = 3 * power;
            }
            else if (dicenum >= 6)
            {
                damage = 2 * power;
            }
            else
            {
                damage = 1 * power;
            }
        }
        if (icheckdoubledamage)
        {
            damage = damage * 2;
        }

        //   for (int kk = 0; kk < otherParty.getNumMembers(); kk++)
        {

            std::cout << name << " rolled a " << dicenum << " and does " << damage << " damage to " << otherParty[target]->getName() << std::endl;
        }
        target++;
        target = target % numparty;
    }
}

void Rogue::operator>>=(Party &otherParty)
{
    int dicenum;
    int numActions = speed;

    int numparty = otherParty.getNumMembers();
    int target = 0;
    for (int i = 0; i < numActions; i++)
    {
        if (otherParty.getNumMembers() == 0)
        {
            return;
        }
        stealthTimer = (stealthTimer + 1) % (2 * speed);
        bool icheckdoubledamage = speed >= stealthTimer;
        int dicenum = dice->nextInt();
        int damage = 0;

        //  if (stealthTimer <= speed)
        {
            if (dicenum == 20)
            {
                damage = 4 * power;
            }
            else if (dicenum >= 13)
            {
                damage = 3 * power;
            }
            else if (dicenum >= 6)
            {
                damage = 2 * power;
            }
            else
            {
                damage = 1 * power;
            }
        }
        if (icheckdoubledamage)
        {
            damage = damage * 2;
        }

        {
            otherParty[target]->changeHealth(-damage);
            std::cout << name << " rolled a " << dicenum << " and does " << damage << " damage to " << otherParty[target]->getName() << std::endl;
        }
        target++;
        target = target % numparty;
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

void Rogue::operator<<(const Party &otherParty) const
{
    // int copystealthtime = stealthTimer;
    Rogue copy(*this);
    int target = 0;
    for (int i = 0; i < copy.speed; i++)
    {
        if (otherParty.getNumMembers() == 0)
        {
            return;
        }
        copy.stealthTimer = (copy.stealthTimer + 1) % (2 * copy.speed);
        bool icheckdoubledamage = copy.speed >= copy.stealthTimer;
        int dicenum = dice->nextInt();
        if (icheckdoubledamage)
        {
            if (dicenum >= 10)
            {

                // otherParty[target]->changePower(1);
                std::cout << copy.name << " rolled a " << dicenum << " and powered up "
                          << otherParty[target]->getName() << std::endl;
            }
            else
            {
                std::cout << copy.name << " rolled a " << dicenum << " and failed to power up "
                          << otherParty[target]->getName() << std::endl;
            }
        }
        else
        {
            if (dicenum >= 15)
            {
                // otherParty[target]->changePower(1);
                std::cout << copy.name << " rolled a " << dicenum << " and powered up "
                          << otherParty[target]->getName() << std::endl;
            }
            else
            {
                std::cout << copy.name << " rolled a " << dicenum << " and failed to power up "
                          << otherParty[target]->getName() << std::endl;
            }
        }
        target++;

        target = target % otherParty.getNumMembers();
    }
}

void Rogue::operator<<=(Party &otherParty)
{
    // operator<<(otherParty);
    int target = 0;
    for (int i = 0; i < speed; i++)
    {
        if (otherParty.getNumMembers() == 0)
        {
            return;
        }
        stealthTimer = (stealthTimer + 1) % (2 * speed);
        bool icheckdoubledamage = speed >= stealthTimer;
        int dicenum = dice->nextInt();

        if (icheckdoubledamage)
        {
            if (dicenum >= 10)
            {
                otherParty[target]->changePower(1);
                std::cout << name << " rolled a " << dicenum << " and powered up "
                          << otherParty[target]->getName() << std::endl;
            }
            else
            {
                std::cout << name << " rolled a " << dicenum << " and failed to power up "
                          << otherParty[target]->getName() << std::endl;
            }
        }
        else
        {
            if (dicenum >= 15)
            {
                otherParty[target]->changePower(1);
                std::cout << name << " rolled a " << dicenum << " and powered up "
                          << otherParty[target]->getName() << std::endl;
            }
            else
            {
                std::cout << name << " rolled a " << dicenum << " and failed to power up "
                          << otherParty[target]->getName() << std::endl;
            }
        }
        target++;
        target = target % otherParty.getNumMembers();
    }
}