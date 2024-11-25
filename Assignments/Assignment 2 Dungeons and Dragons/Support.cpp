#include "Support.h"

Support::Support(std::string name, int health, int power, int speed, int mana) : Player(name, health, power, speed)
{
    this->mana = mana;
};

Support::Support(const Support &other) : Player(other)
{
    this->mana = other.mana;
};



Support &Support::operator=(const Support &other)
{
    if (this == &other)
        return *this;

    Player::operator=(other);
    this->mana = other.mana;

    return *this;
};

Player *Support::clone() const
{
    //   Support *newSupport = new Support(this->name, health, power, speed, mana);
    return new Support(*this);
};



Support::~Support() {};

Support::operator std::string() const
{
    std::stringstream ss;
    ss << "Support:" << Player::operator std::string()
       << ",mana=" << mana;
    return ss.str();
};

void Support::operator>>(const Party &otherParty) const
{
    int numparty = otherParty.getNumMembers();

    if (numparty == 0)
        return;

    int numActions = speed;

    int target = 0;
   

    for (int i = 0; i < numActions; i++)
    {

        int dicenum = dice->nextInt(); int damage = 0;

        if (dicenum == 20)
        {
            damage = 2 * power;
        }
        else if (dicenum >= 6)
        {
            damage = power;
        }

        // otherParty[target]->changeHealth(-damage);

        std::cout << name << " rolled a " << dicenum << " and does " << damage << " damage to " << otherParty[target]->getName() << std::endl;
        target++;
        target = (target) % numparty;
    }
    // dice->lockDiceRoll(dicenum);
}

void Support::operator>>=(Party &otherParty)
{
    int numActions = speed;

    int numparty = otherParty.getNumMembers();
    int target = 0;
    if (numparty == 0)
        return;

    for (int i = 0; i < numActions; i++)
    {

        int dicenum = dice->nextInt();

        int damage = 0;
        if (dicenum == 20)
        {
            damage = 2 * power;
        }
        else if (dicenum >= 6 && dicenum <= 19)
        {
            damage = 1 * power;
        }

        otherParty[target]->changeHealth(-damage);

        std::cout << name << " rolled a " << dicenum << " and does " << damage << " damage to " << otherParty[target]->getName() << std::endl;
        target++;
        target = (target) % numparty;
    }
    //  dice->lockDiceRoll(dicenum);
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

void Support::operator<<(const Party &otherParty) const
{
    int numActions = speed;
    // int dicenum;
    int numparty = otherParty.getNumMembers();
    int target = 0;
    if (numparty == 0)
        return;

    int mag = mana;

    for (int i = 0; i < numActions; i++)
    {

        int dicenum = dice->nextInt();

        if (mag > 0)
        {
            int heals = 0;

            if (dicenum == 20)
            {
                heals = 3 * power;
            }
            else if (dicenum >= 11 && dicenum <= 19)
            {
                heals = 2 * power;
            }
            else if (dicenum >= 2 && dicenum <= 10)
            {
                heals = 1 * power;
            }

            // otherParty[target]->changeHealth(heals);
            //   mana--;
            // this->

            std::cout << name << " rolled a " << dicenum << " and heals "
                      << otherParty[target]->getName() << " by " << heals << std::endl;

            mag--;
        }
        else
        {
            if (mag == 0)
            {

                mag = (dicenum / 4) + 1;
                //  mana += restoredMana;

                std::cout << name << " rolled a " << dicenum << " and restored "
                          << mag << " mana" << std::endl;
            }
        }

        target++;
        target = (target) % numparty;
    }
    //  dice->lockDiceRoll(dicenum);
}

void Support::operator<<=(Party &otherParty)
{
    int numActions = speed;

    int numparty = otherParty.getNumMembers();
    int target = 0;
    if (numparty == 0)
        return;
    for (int i = 0; i < numActions; i++)
    {

        int dicenum = dice->nextInt();

        if (mana > 0)
        {
            int heals = 0;

            if (dicenum == 20)
            {
                heals = 3 * power;
            }
            else if (dicenum >= 11 && dicenum <= 19)
            {
                heals = 2 * power;
            }
            else if (dicenum >= 2 && dicenum <= 10)
            {
                heals = 1 * power;
            }

            otherParty[target]->changeHealth(heals);
            mana--;

            std::cout << name << " rolled a " << dicenum << " and heals "
                      << otherParty[target]->getName() << " by " << heals << std::endl;
        }
        else
        {
            mana = (dicenum / 4) + 1;

            std::cout << name << " rolled a " << dicenum << " and restored "
                      << mana << " mana" << std::endl;
        }

        target++;
        target = (target) % numparty;
    }
    // dice->lockDiceRoll(dicenum);
}
