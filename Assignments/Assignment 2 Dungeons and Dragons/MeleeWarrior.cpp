#include "MeleeWarrior.h"

MeleeWarrior::MeleeWarrior(std::string name, int health, int power, int speed, int armor)
    : Player(name, health, power, speed)
{
    this->armor = armor;
};

MeleeWarrior::MeleeWarrior(const MeleeWarrior &other)
    : Player(other)
{
    this->armor = other.armor;
};

MeleeWarrior &MeleeWarrior::operator=(const MeleeWarrior &other)
{
    if (this == &other)
        return *this;

    Player::operator=(other);
    this->armor = other.armor;

    return *this;
};

Player *MeleeWarrior::clone() const
{
    // MeleeWarrior *newMelee = new MeleeWarrior(this->name, health, power, speed, armor);
    return new MeleeWarrior(*this);
};

MeleeWarrior::~MeleeWarrior() {};

MeleeWarrior::operator std::string() const
{
    std::stringstream ss;
    ss << "MeleeWarrior:" << static_cast<std::string>(Player::operator std::string())
       << ",armor=" << armor;
    return ss.str();
};

void MeleeWarrior::operator>>(const Party &otherParty) const
{
    int numActions = speed;
    int numparty = otherParty.getNumMembers();
    int target = 0;
    int dicenum;

    for (int i = 0; i < numActions; i++)
    {
        if (numparty == 0)
            return;
        else
        {

            dicenum = dice->nextInt();

            int damage = 0;

            if (dicenum == 20)
            {
                damage = 3 * power;
            }
            else if (dicenum >= 13 && dicenum <= 19)
            {
                damage = 2 * power;
            }
            else if (dicenum >= 6 && dicenum <= 12)
            {
                damage = 1 * power;
            }

            //  otherParty[target]->changeHealth(-damage);

            std::cout << this->name << " rolled a " << dicenum << " and does " << damage << " damage to " << otherParty[target]->getName() << std::endl;
            target++;
            target = (target) % numparty;
        }
    }
    // dice->lockDiceRoll(dicenum);
    // for (int i = 0; i < numparty; i++)
    // {
    //     if (otherParty[i]->getHealth() <= 0)
    //     {
    //        // otherParty.operator-(i);
    //     }
    // }
}

void MeleeWarrior::operator>>=(Party &otherParty)
{
    int numActions = speed;
    int numparty = otherParty.getNumMembers();
    int target = 0;
    int dicenum;
    for (int i = 0; i < numActions; i++)
    {
        if (numparty == 0)
            return;
        else
        {

            dicenum = dice->nextInt();

            int damage = 0;

            if (dicenum == 20)
            {
                damage = 3 * power;
            }
            else if (dicenum >= 13 && dicenum <= 19)
            {
                damage = 2 * power;
            }
            else if (dicenum >= 6 && dicenum <= 12)
            {
                damage = 1 * power;
            }

            otherParty[target]->changeHealth(-damage);

            std::cout << this->name << " rolled a " << dicenum << " and does " << damage << " damage to " << otherParty[target]->getName() << std::endl;
            target++;
            target = (target) % numparty;
        }
    }

    for (int i = 0; i < numparty; i++)
    {
        if (otherParty[i])
        {

            if (otherParty[i]->getHealth() <= 0)
            {
                otherParty.operator-=(i);
                i = 0;
            }
        }
    }
}

void MeleeWarrior::operator<<(const Party &otherParty) const
{
    int numActions = speed;
    int numparty = otherParty.getNumMembers();
    int target = 0;
    int dicenum;
    for (int i = 0; i < numActions; i++)
    {
        if (numparty == 0)
            return;
        else
        {

            dicenum = dice->nextInt();

            if (dicenum == 20)
            {
                // otherParty[target]->changePower(1);
                std::cout << name << " rolled a " << dicenum << " and powered up " << otherParty[target]->getName() << std::endl;
            }
            else
            {
                std::cout << name << " rolled a " << dicenum << " and failed to power up " << otherParty[target]->getName() << std::endl;
            }

            target++;
            target = (target) % numparty;
        }
    }
}

void MeleeWarrior::operator<<=(Party &otherParty)
{
    int numActions = speed;
    int numparty = otherParty.getNumMembers();
    int target = 0;
    int dicenum;
    for (int i = 0; i < numActions; i++)
    {
        if (numparty == 0)
            return;
        else
        {

            dicenum = dice->nextInt();

            if (dicenum == 20)
            {
                otherParty[target]->changePower(1);
                std::cout << name << " rolled a " << dicenum << " and powered up " << otherParty[target]->getName() << std::endl;
            }
            else
            {
                std::cout << name << " rolled a " << dicenum << " and failed to power up " << otherParty[target]->getName() << std::endl;
            }

            target++;
            target = (target) % numparty;
        }
    }
}

void MeleeWarrior::changeHealth(int change)
{
    if (change >= 0)
    {
        health += change;
    }
    else
    {
        int newhealth = armor + change;
        if (change < -armor && change < 0)
        {
            health += newhealth;
        }
        else
        {
        }
    }
}