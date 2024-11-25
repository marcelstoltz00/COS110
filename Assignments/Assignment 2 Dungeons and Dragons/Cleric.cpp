#include "Cleric.h"

Cleric::Cleric(std::string name, int health, int power, int speed, int mana, int faith)
    : Support(name, health, power, speed, mana) { this->faith = faith; }

Cleric::Cleric(const Cleric &other)
    : Support(other)
{
    this->faith = other.faith;
}

Cleric &Cleric::operator=(const Cleric &other)
{
    if (this == &other)
        return *this;
    Support::operator=(other);
    this->faith = other.faith;
    return *this;
}

Player *Cleric::clone() const
{
    return new Cleric(*this);
}

Cleric::~Cleric() {}

Cleric::operator std::string() const
{
    std::stringstream ss;
    ss << "Cleric:" << static_cast<std::string>(Support::operator std::string())
       << ",faith=" << faith;
    return ss.str();
}

void Cleric::operator>>(const Party &otherParty) const
{
    int numActions = speed;
    int diceRoll;
    int numparty = otherParty.getNumMembers();
    int target = 0;

    for (int i = 0; i < numActions; i++)
    {
        if (numparty == 0)
            return;

        diceRoll = dice->nextInt();
        int damage = 0;

        if (diceRoll == 20)
        {
            damage = 4 * power;
        }
        else if (diceRoll >= 13 && diceRoll <= 19)
        {
            damage = 3 * power;
        }
        else if (diceRoll >= 6 && diceRoll <= 12)
        {
            damage = 2 * power;
        }
        else
        {
            damage = 1 * power;
        }

        //   otherParty[target]->changeHealth(-damage);
        std::cout << this->name << " rolled a " << diceRoll
                  << " and does " << damage << " damage to "
                  << otherParty[target]->getName() << std::endl;

        target++;
        target = target % numparty;
    }
    //  dice->lockDiceRoll(diceRoll);
    // for (int i = 0; i < numparty; i++)
    // {
    //     if (otherParty[i]->getHealth() <= 0)
    //     {
    //         otherParty.operator-(i);

    //     }
    // }
}

void Cleric::operator>>=(Party &otherParty)
{
    int numActions = speed;
    int dicenum;
    int numparty = otherParty.getNumMembers();
    int target = 0;

    for (int i = 0; i < numActions; i++)
    {
        if (numparty == 0)
            return;

        dicenum = dice->nextInt();
        int damage = 0;

        if (dicenum == 20)
        {
            damage = 4 * power;
        }
        else if (dicenum >= 13 && dicenum <= 19)
        {
            damage = 3 * power;
        }
        else if (dicenum >= 6 && dicenum <= 12)
        {
            damage = 2 * power;
        }
        else
        {
            damage = 1 * power;
        }

        otherParty[target]->changeHealth(-damage);
        std::cout << this->name << " rolled a " << dicenum
                  << " and does " << damage << " damage to "
                  << otherParty[target]->getName() << std::endl;

        target++;
        target = target % numparty;
    }
    //  dice->lockDiceRoll(diceRoll);
    for (int i = 0; i < numparty; i++)
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

void Cleric::operator<<(const Party &otherParty) const
{
    int numActions = speed;
    int dicenum;
    int numparty = otherParty.getNumMembers();
    int target = 0;

    int mag = mana;

    for (int i = 0; i < numActions; i++)
    {
        if (numparty == 0)
            return;

        dicenum = dice->nextInt();

        if (mag > 0)
        {
            int healing = 0;
            if (dicenum == 20)
            {
                healing = 4 * power * faith;
            }
            else if (dicenum >= 11 && dicenum <= 19)
            {
                healing = 3 * power * faith;
            }
            else if (dicenum >= 2 && dicenum <= 10)
            {
                healing = 2 * power * faith;
            }
            else
            {
                healing = 1 * faith;
            }

            otherParty[target]->changeHealth(healing);
            std::cout << name << " rolled a " << dicenum
                      << " and heals " << otherParty[target]->getName()
                      << " by " << healing << std::endl;
            mag--;
        }
        else
        {
           mag = (dicenum / 4) + 1;
        //   mag += newmana;
            std::cout << name << " rolled a " << dicenum
                      << " and restored " << mag << " mana" << std::endl;
        }

        target++;
        target = target % numparty;
    }
}

void Cleric::operator<<=(Party &otherParty)
{
    int numActions = speed;
    int dicenum;
    int numparty = otherParty.getNumMembers();
    int target = 0;

    for (int i = 0; i < numActions; i++)
    {
        if (numparty == 0)
            return;

        dicenum = dice->nextInt();

        if (mana > 0)
        {
            int healing = 0;
            if (dicenum == 20)
            {
                healing = 4 * power * faith;
            }
            else if (dicenum >= 11 && dicenum <= 19)
            {
                healing = 3 * power * faith;
            }
            else if (dicenum >= 2 && dicenum <= 10)
            {
                healing = 2 * power * faith;
            }
            else
            {
                healing = 1 * faith;
            }

            otherParty[target]->changeHealth(healing);
            std::cout << name << " rolled a " << dicenum
                      << " and heals " << otherParty[target]->getName()
                      << " by " << healing << std::endl;
            mana--;
        }
        else
        {
            int newmana = (dicenum / 4) + 1;
            mana += newmana;
            std::cout << name << " rolled a " << dicenum
                      << " and restored " << newmana << " mana" << std::endl;
        }

        target++;
        target = target % numparty;
    }
}