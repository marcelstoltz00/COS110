#include "Ranger.h"

Ranger::Ranger(std::string name, int health, int power, int speed, int numShots) : Player(name, health, power, speed)
{

    this->numShots = numShots;
};
Ranger::Ranger(const Ranger &other) : Player(other)
{

    this->numShots = other.numShots;
};
Ranger &Ranger::operator=(const Ranger &other)
{
    if (this == &other)
        return *this;

    Player::operator=(other);

    this->numShots = other.numShots;

    return *this;
};
Player *Ranger::clone() const
{

    // Ranger *newestRang = new Ranger(this->name, health, power, speed, numShots);

    // return newestRang;

    return new Ranger(*this);
};
Ranger::~Ranger() {};

Ranger::operator std::string() const
{

    std::stringstream ss;
    ss << "Ranger:" << Player::operator std::string()
       << ",numShots=" << numShots;
    return ss.str();
};

void Ranger::operator>>(const Party &otherParty) const
{
    int dicenum;

    Ranger copy(*this);
    int numActions = copy.numShots * copy.speed;
    int numparty = otherParty.getNumMembers();
    int target = 0;

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
                damage = 3 * copy.power;
            }
            else if (dicenum >= 13 && dicenum <= 19)
            {
                damage = 2 * copy.power;
            }
            else if (dicenum >= 6 && dicenum <= 12)
            {
                damage = 1 * copy.power;
            }

            //  otherParty[target]->changeHealth(-damage);

            std::cout << copy.name << " rolled a " << dicenum << " and does " << damage << " damage to " << otherParty[target]->getName() << std::endl;
            target++;
            target = (target) % numparty;
        }
    }
    //    dice->lockDiceRoll(dicenum);
    // for (int i = 0; i < numparty; i++)
    // {
    //     if (otherParty[i]->getHealth() <= 0)
    //     {
    //         otherParty.operator-(i);
    //     }
    // }
}

void Ranger::operator>>=(Party &otherParty)
{

    int numActions = numShots * speed;
    int dicenum;
    int numparty = otherParty.getNumMembers();
    int target = 0;

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
    // dice->lockDiceRoll(dicenum);
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

void Ranger::operator<<(const Party &otherParty) const
{
    int numActions = speed;
    int dicenum;
    int numparty = otherParty.getNumMembers();
    int target = 0;
    if (numparty == 0)
        return;
    for (int i = 0; i < numActions; i++)
    {

        // else
        {

            dicenum = dice->nextInt();

           // int damage = 0;

            if (dicenum == 20)
            {
                //   otherParty[target]->changeSpeed(1);
                std::cout << name << " rolled a " << dicenum << " and sped up " << otherParty[target]->getName() << std::endl;
            }
            else
            {
                std::cout << name << " rolled a " << dicenum << " and failed to speed up " << otherParty[target]->getName() << std::endl;
            }

            target++;
            target = (target) % numparty;
        }
    }
    //   dice->lockDiceRoll(dicenum);
}

void Ranger::operator<<=(Party &otherParty)
{
    int numActions = speed;
    int dicenum;
    int numparty = otherParty.getNumMembers();
    int target = 0;

    for (int i = 0; i < numActions; i++)
    {
        if (numparty == 0)
            return;
        else
        {

            dicenum = dice->nextInt();

            //  int damage = 0;

            if (dicenum == 20)
            {
                otherParty[target]->changeSpeed(1);
                std::cout << name << " rolled a " << dicenum << " and sped up " << otherParty[target]->getName() << std::endl;
            }
            else
            {
                std::cout << name << " rolled a " << dicenum << " and failed to speed up " << otherParty[target]->getName() << std::endl;
            }

            target++;
            target = (target) % numparty;
        }
    }
}