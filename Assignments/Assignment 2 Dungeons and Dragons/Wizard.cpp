#include "Wizard.h"

Wizard::Wizard(std::string name, int health, int power, int speed, int numShots, int mana)
    : Ranger(name, health, power, speed, numShots)
{
    this->mana = mana;
}

Wizard::Wizard(const Wizard &other)
    : Ranger(other)
{
    this->mana = other.mana;
}

Wizard &Wizard::operator=(const Wizard &other)
{
    if (this == &other)
    {
        return *this;
    }

    Ranger::operator=(other);
    this->mana = other.mana;

    return *this;
}

Player *Wizard::clone() const
{
    // Wizard *newWizard = new Wizard(this->name, this->health, this->power, this->speed, this->numShots, this->mana);
    return new Wizard(*this);
}

Wizard::~Wizard() {}

Wizard::operator std::string() const
{
    std::stringstream ss;
    ss << "Wizard:" << static_cast<std::string>(Ranger::operator std::string())
       << ",mana=" << mana;
    return ss.str();
}

void Wizard::operator>>(const Party &otherParty) const
{
    int numActions = numShots * speed;
    int dicenum;
    int mag= mana;
    int numparty = otherParty.getNumMembers();
    int target = 0;
    //   Wizard copy(*this);
    for (int i = 0; i < numActions; i++)
    {
        if (numparty == 0)
        {
            return;
        }
        else
        {
            //  dice->unlockDiceRoll();
            dicenum = dice->nextInt();
            int damage = 0;

            if (mag > 0)
            {
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
                else if (dicenum >= 1 && dicenum <= 5)
                {
                    damage = 1 * power;
                }

                //  otherParty[target]->changeHealth(-damage);
                std::cout << name << " rolled a " << dicenum << " and does " << damage << " damage to " << otherParty[target]->getName() << std::endl;

                mag--;
            }
            else
            {
                if (mag==0)
                {
                    mag = dicenum / 4 + 1;
                   
                    std::cout << name << " rolled a " << dicenum << " and restored " << mag << " mana" << std::endl;
                }
            }

            target++;
            target = (target) % numparty;
        }
    }
    // dice->lockDiceRoll(dicenum);
}

void Wizard::operator>>=(Party &otherParty)
{
    int numActions = numShots * speed;
    int dicenum;
    int numparty = otherParty.getNumMembers();
    int target = 0;

    for (int i = 0; i < numActions; i++)
    {
        if (numparty == 0)
        {
            return;
        }
        else
        {
            //   dice->unlockDiceRoll();
            dicenum = dice->nextInt();
            int damage = 0;

            if (mana > 0)
            {
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
                else if (dicenum >= 1 && dicenum <= 5)
                {
                    damage = 1 * power;
                }

                otherParty[target]->changeHealth(-damage);
                std::cout << this->name << " rolled a " << dicenum << " and does " << damage << " damage to " << otherParty[target]->getName() << std::endl;

                this->mana -= 1;
            }
            else
            {
                if (mana == 0)
                {
                    int newmana = dicenum / 4 + 1;
                    this->mana += newmana;
                    std::cout << this->name << " rolled a " << dicenum << " and restored " << newmana << " mana" << std::endl;
                }
            }

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

void Wizard::operator<<(const Party &otherParty) const
{
    int numActions = speed;
    int dicenum;
    int numparty = otherParty.getNumMembers();
    int target = 0;

    for (int i = 0; i < numActions; i++)
    {
        if (numparty == 0)
        {
            return;
        }
        else
        {
            //   dice->unlockDiceRoll();
            dicenum = dice->nextInt();

            if (dicenum >= 13)
            {
                //  otherParty[target]->changeSpeed(1);
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

void Wizard::operator<<=(Party &otherParty)
{
    int numActions = speed;
    int dicenum;
    int numparty = otherParty.getNumMembers();
    int target = 0;

    for (int i = 0; i < numActions; i++)
    {
        if (numparty == 0)
        {
            return;
        }
        else
        {
            //  dice->unlockDiceRoll();
            dicenum = dice->nextInt();

            if (dicenum >= 13)
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
    // dice->lockDiceRoll(dicenum);
}