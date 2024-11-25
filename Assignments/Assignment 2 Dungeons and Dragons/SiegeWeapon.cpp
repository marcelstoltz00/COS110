#include "SiegeWeapon.h"

SiegeWeapon::SiegeWeapon(std::string name, int health, int power, int speed, int numShots) : Ranger(name, health, power, speed, numShots)
{
    ammo = new int *[numShots];

    for (int i = 0; i < numShots; i++)
    {
        ammo[i] = NULL;
    }
}

SiegeWeapon::SiegeWeapon(const SiegeWeapon &other) : Ranger(other)
{
    ammo = new int *[other.numShots];
    numShots = other.numShots;
    for (int i = 0; i < numShots; i++)
    {
        if (other.ammo[i] == NULL)
        {
            ammo[i] = NULL;
        }
        else
        {
            ammo[i] = new int(*other.ammo[i]);
        }
    }
}

SiegeWeapon &SiegeWeapon::operator=(const SiegeWeapon &other)
{
    if (this == &other)
    {
        return *this;
    }

    if (ammo != NULL)
    {
        for (int i = 0; i < numShots; i++)
        {
            if (ammo[i] != NULL)
            {
                delete ammo[i];
            }
        }
        delete[] ammo;
    }

    Ranger::operator=(other);
    ammo = new int *[other.numShots];
    numShots = other.numShots;
    for (int i = 0; i < other.numShots; i++)
    {
        if (other.ammo[i] == NULL)
        {
            ammo[i] = NULL;
        }
        else
        {
            ammo[i] = new int(*other.ammo[i]);
        }
    }

    return *this;
}

Player *SiegeWeapon::clone() const
{
    return new SiegeWeapon(*this);
}

SiegeWeapon::~SiegeWeapon()
{
    if (ammo != NULL)
    {
        for (int i = 0; i < numShots; ++i)
        {
            if (ammo[i] != NULL)
            {
                delete ammo[i];
            }
        }
        delete[] ammo;
    }
}

SiegeWeapon::operator std::string() const
{
    std::stringstream ss;
    ss << "SiegeWeapon:" << Ranger::operator std::string() << ",ammo=[";
    for (int i = 0; i < numShots; ++i)
    {
        if (ammo != NULL && ammo[i] != NULL)
        {
            ss << *ammo[i];
        }
        else
        {
            ss << "-";
        }
        if (i < numShots - 1)
        {
            ss << ",";
        }
    }
    ss << "]";
    return ss.str();
}

void SiegeWeapon::operator>>(const Party &otherParty) const
{
    if (ammo == NULL)
    {
        return;
    }

    int numActions = speed;
    int numparty = otherParty.getNumMembers();
    int target = 0;
    SiegeWeapon copy(*this);

    for (int i = 0; i < numActions; i++)
    {
        if (otherParty.getNumMembers() == 0 || copy.ammo == NULL)
        {
            return;
        }

        int dicenum = dice->nextInt();
        int damage = 0;
        int refillAmmoIndex = -100;
        int numNULL = 0;

        for (int k = 0; k < numShots; ++k)
        {
            if (copy.ammo[k] == NULL)
            {
                numNULL++;
            }
            else
            {
                refillAmmoIndex = k;
                break;
            }
        }

        if (refillAmmoIndex == -100)
        {
            int a = (dicenum / 4) + 1;
            int b = ((21 - dicenum) / 8) + 1;
            int refilled = 0;
            if (a > numShots)
                a = numShots;

            for (int icount = 0; icount < a; icount++)
            {
                if (copy.ammo[icount] == NULL)
                {
                    copy.ammo[icount] = new int(b);
                    refilled++;
                }
            }

            std::cout << name << " rolled a " << dicenum << " and refilled " << a << " ammo" << std::endl;
        }
        else
        {
            int av = *copy.ammo[refillAmmoIndex];

            if (dicenum == 20)
            {
                damage = 3 * power * av;
            }
            else if (dicenum >= 17)
            {
                damage = 2 * power * av;
            }
            else if (dicenum >= 6)
            {
                damage = power * av;
            }

            delete copy.ammo[refillAmmoIndex];
            copy.ammo[refillAmmoIndex] = NULL;

            for (int i = 0; i < otherParty.getNumMembers(); i++)
            {
                std::cout << name << " rolled a " << dicenum << " and does " << damage << " damage to " << otherParty[target]->getName() << std::endl;
                target = (target + 1) % numparty;
            }
        }
    }
}

void SiegeWeapon::operator>>=(Party &otherParty)
{
    if (ammo == NULL)
    {
        return;
    }

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
        int damage = 0;
        int refillAmmoIndex = -100;
        int numNULL = 0;

        for (int k = 0; k < numShots; ++k)
        {
            if (ammo[k] == NULL)
            {
                numNULL++;
            }
            else
            {
                refillAmmoIndex = k;
                break;
            }
        }

        if (refillAmmoIndex == -100)
        {
            int a = (dicenum / 4) + 1;
            int b = ((21 - dicenum) / 8) + 1;
            int refilled = 0;
            if (a > numShots)
                a = numShots;

            for (int icount = 0; icount < a; icount++)
            {
                if (ammo[icount] == NULL)
                {
                    ammo[icount] = new int(b);
                    refilled++;
                }
            }

            std::cout << name << " rolled a " << dicenum << " and refilled " << a << " ammo" << std::endl;
        }
        else
        {
            int av = *ammo[refillAmmoIndex];

            if (dicenum == 20)
            {
                damage = 3 * power * av;
            }
            else if (dicenum >= 17)
            {
                damage = 2 * power * av;
            }
            else if (dicenum >= 6)
            {
                damage = power * av;
            }

            delete ammo[refillAmmoIndex];
            ammo[refillAmmoIndex] = NULL;

            for (int i = 0; i < otherParty.getNumMembers(); i++)
            {
                otherParty[target]->changeHealth(-damage);
                std::cout << name << " rolled a " << dicenum << " and does " << damage << " damage to " << otherParty[target]->getName() << std::endl;
                target = (target + 1) % numparty;
            }
        }
    }

    for (int i = 0; i < otherParty.getNumMembers(); ++i)
    {
        if (otherParty[i] && otherParty[i]->getHealth() <= 0)
        {
            otherParty.operator-=(i);
            i--;
        }
    }
}

void SiegeWeapon::operator<<(const Party &otherParty) const
{
    if (ammo == NULL)
    {
        return;
    }

    int numActions = speed;
    int dicenum;
    int numparty = otherParty.getNumMembers();
    if (numparty == 0)
    {
        return;
    }
    int target = 0;

    for (int i = 0; i < numActions; ++i)
    {
        dicenum = dice->nextInt();

        if (dicenum >= 13)
        {
            std::cout << name << " rolled a " << dicenum << " and sped up " << otherParty[target]->getName() << std::endl;
        }
        else
        {
            std::cout << name << " rolled a " << dicenum << " and failed to speed up " << otherParty[target]->getName() << std::endl;
        }

        target = (target + 1) % numparty;
    }
}

void SiegeWeapon::operator<<=(Party &otherParty)
{
    if (ammo == NULL)
    {
        return;
    }

    int numActions = speed;
    int dicenum;
    int numparty = otherParty.getNumMembers();
    int target = 0;

    for (int i = 0; i < numActions; ++i)
    {
        if (numparty == 0)
        {
            return;
        }

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

        target = (target + 1) % numparty;
    }
}