

// #include "Druid.h"

// Druid::Druid(std::string name, int health, int power, int speed, int mana)
//     : Support(name, health, power, speed, mana)
// {

//     numTreeants = 0;
//     treeants = new int[0];
// }

// Druid::Druid(const Druid &other)
//     : Support(other)
// {
//     numTreeants = other.numTreeants;
//     treeants = new int[numTreeants];
//     for (int i = 0; i < numTreeants; i++)
//     {
//         treeants[i] = other.treeants[i];
//     }
// }

// Druid &Druid::operator=(const Druid &other)
// {
//     if (this == &other)
//         return *this;

//     Support::operator=(other);

//     delete[] treeants;
//     numTreeants = other.numTreeants;
//     treeants = new int[numTreeants];
//     for (int i = 0; i < numTreeants; i++)
//     {
//         treeants[i] = other.treeants[i];
//     }

//     return *this;
// }

// Player *Druid::clone() const
// {
//     return new Druid(*this);
// }

// Druid::~Druid()
// {
//     if (treeants)
//         delete[] treeants;
// }

// Druid::operator std::string() const
// {
//     std::stringstream ss;
//     ss << "Druid:" << static_cast<std::string>(Support::operator std::string()) << ",treeants=[";
//     for (int i = 0; i < numTreeants; i++)
//     {
//         ss << treeants[i];
//         if (i < numTreeants - 1)
//             ss << ",";
//     }
//     ss << "]";
//     return ss.str();
// }

// void Druid::operator>>(const Party &otherParty) const
// {
//     if (otherParty.getNumMembers() == 0)
//         return;

//     Druid copy(*this);

//     for (int i = 0; i < speed; i++)
//     {
//         int dicenum = dice->nextInt();
//         int a = dicenum / 8 + 1;

//         std::cout << copy.name << " rolled a " << dicenum << " and summons " << a
//                   << " treeants with a lifetime of " << copy.mana << std::endl;

//         int *newtreeants = new int[copy.numTreeants + a];
//         if (copy.numTreeants > 0 && copy.treeants)
//         {
//             for (int k = 0; k < copy.numTreeants; k++)
//             {
//                 if (copy.treeants)
//                     newtreeants[k] = copy.treeants[k];
//             }
//         }
//         for (int p = 0; p < a; p++)
//         {
//             newtreeants[copy.numTreeants + p] = copy.mana;
//             //  std::cout << "copy mana:" << copy.mana << std::endl;
//         }

//         delete[] copy.treeants;

//         copy.treeants = newtreeants;

//         copy.numTreeants += a;
//     }
//     //  int target = 0;
//     for (int u = 0; u < copy.numTreeants; u++)
//     {
//         int target = u % otherParty.getNumMembers();
//         // std::cout << "target: " << target;
//         int damage = power * copy.treeants[u];
//         // otherParty[target]->changeHealth(-damage);

//         std::cout << copy.name << ": treeant " << u << " does " << damage
//                   << " damage to " << otherParty[target]->getName() << std::endl;

//         //
//         // target++;
//         //  int target = target % otherParty.getNumMembers();
//         copy.treeants[u]--;
//     }
// }

// void Druid::operator>>=(Party &otherParty)
// {

//     if (otherParty.getNumMembers() == 0)
//         return;

//     for (int i = 0; i < speed; i++)
//     {
//         int dicenum = dice->nextInt();
//         int a = dicenum / 8 + 1;

//         std::cout << name << " rolled a " << dicenum << " and summons " << a
//                   << " treeants with a lifetime of " << mana << std::endl;

//         int *newtreeants = new int[numTreeants + a];
//         // if (numTreeants > 0 && treeants)
//         {
//             for (int k = 0; k < numTreeants; k++)
//             {
//                 if (treeants)
//                     newtreeants[k] = treeants[k];
//             }
//         }
//         for (int p = 0; p < a; p++)
//         {
//             newtreeants[numTreeants + p] = mana;
//             //  std::cout << "copy mana:" << mana << std::endl;
//         }

//         delete[] treeants;

//         treeants = newtreeants;

//         numTreeants += a;
//     }
//     for (int u = 0; u < numTreeants; u++)
//     {
//         int target = u % otherParty.getNumMembers();
//         //  std::cout << "target: " << target;
//         int damage = power * treeants[u];
//         otherParty[target]->changeHealth(-damage);

//         std::cout << name << ": treeant " << u << " does " << damage
//                   << " damage to " << otherParty[target]->getName() << std::endl;

//         treeants[u]--;
//     }

//     int kickingants = 0;
//     for (int j = 0; j < numTreeants; ++j)
//     {
//         if (treeants[j] > 0)
//             kickingants++;
//     }

//     int *filt = new int[kickingants];
//     int in = 0;
//     for (int pp = 0; pp < numTreeants; pp++)
//     {
//         if (treeants[pp] > 0)
//         {

//             filt[in] = treeants[pp];
//             in++;
//         }
//     }

//     delete[] treeants;
//     treeants = filt;
//     numTreeants = kickingants;

//     for (int i = 0; i < otherParty.getNumMembers(); i++)
//     { // std::cout<<"here10";
//         if (otherParty[i])
//         {
//             if (otherParty[i]->getHealth() <= 0)
//             {
//                 //  std::cout<<"here11";

//                 otherParty.operator-=(i);
//                 i--;
//             }
//         }
//     }
//     // std::cout<<"here12";
// };

// void Druid::operator<<(const Party &otherParty) const
// {
//     if (otherParty.getNumMembers() == 0)
//         return;

//     Druid copy = Druid(*this);

//     for (int i = 0; i < copy.speed; i++)
//     {
//         int dicenum = dice->nextInt();
//         int a = dicenum / 8 + 1;

//         std::cout << copy.name << " rolled a " << dicenum << " and summons " << a
//                   << " treeants with a lifetime of " << copy.mana << std::endl;

//         int *newtreeants = new int[copy.numTreeants + a];
//         if (copy.numTreeants > 0 && copy.treeants)
//         {
//             for (int k = 0; k < copy.numTreeants; k++)
//             {
//                 if (copy.treeants)
//                     newtreeants[k] = copy.treeants[k];
//             }
//         }
//         for (int p = 0; p < a; p++)
//         {
//             newtreeants[copy.numTreeants + p] = copy.mana;
//             //  std::cout << "copy mana:" << copy.mana << std::endl;
//         }

//         delete copy.treeants;

//         copy.treeants = newtreeants;

//         copy.numTreeants += a;
//     }
//     for (int u = 0; u < copy.numTreeants; u++)
//     {
//         int target = u % otherParty.getNumMembers();
//         //  std::cout << "target: " << target;
//         int heals = copy.power * copy.treeants[u];
//         // otherParty[target]->changeHealth(-heals);

//         std::cout << copy.name << ": treeant " << u << " heals " << otherParty[target]->getName() << " by " << heals << std::endl;

//         // copy.treeants[u]--;
//     }
// };

// void Druid::operator<<=(Party &otherParty)
// {
//     if (otherParty.getNumMembers() == 0)
//         return;

//     Druid copy = Druid(*this);

//     for (int i = 0; i < speed; i++)
//     {
//         int dicenum = dice->nextInt();
//         int a = dicenum / 8 + 1;

//         std::cout << name << " rolled a " << dicenum << " and summons " << a
//                   << " treeants with a lifetime of " << mana << std::endl;

//         int *newtreeants = new int[numTreeants + a];
//         if (numTreeants > 0 && treeants)
//         {
//             for (int k = 0; k < numTreeants; k++)
//             {
//                 if (treeants)
//                     newtreeants[k] = treeants[k];
//             }
//         }
//         for (int p = 0; p < a; p++)
//         {
//             newtreeants[numTreeants + p] = mana;
//             //  std::cout << "copy mana:" << mana << std::endl;
//         }

//         delete[] treeants;

//         treeants = newtreeants;

//         numTreeants += a;
//     }
//     for (int u = 0; u < numTreeants; u++)
//     {
//         int target = u % otherParty.getNumMembers();
//         //  std::cout << "target: " << target;
//         int heals = power * treeants[u];
//         otherParty[target]->changeHealth(heals);

//         std::cout << name << ": treeant " << u << " heals " << otherParty[target]->getName() << " by " << heals << std::endl;

//         treeants[u]--;
//     }

//     int kickingants = 0;
//     for (int j = 0; j < numTreeants; ++j)
//     {
//         if (treeants[j] > 0)
//             kickingants++;
//     }

//     int *filt = new int[kickingants];
//     int in = 0;
//     for (int pp = 0; pp < numTreeants; pp++)
//     {
//         if (treeants[pp] > 0)
//             filt[in] = treeants[pp];
//         in++;
//     }

//     delete[] treeants;
//     treeants = filt;
//     numTreeants = kickingants;
//     //  std::cout<<"heren";
// }

#include "Druid.h"

Druid::Druid(std::string name, int health, int power, int speed, int mana)
    : Support(name, health, power, speed, mana)
{
    numTreeants = 0;
    treeants = new int[0];
}

Druid::Druid(const Druid &other)
    : Support(other)
{
    numTreeants = other.numTreeants;
    treeants = new int[numTreeants];
    if (other.treeants != NULL)
    {
        for (int i = 0; i < numTreeants; i++)
        {
            treeants[i] = other.treeants[i];
        }
    }
}

Druid &Druid::operator=(const Druid &other)
{
    if (this == &other)
        return *this;

    Support::operator=(other);

    if (treeants != NULL)
        delete[] treeants;

    numTreeants = other.numTreeants;
    treeants = new int[numTreeants];
    if (other.treeants != NULL)
    {
        for (int i = 0; i < numTreeants; i++)
        {
            treeants[i] = other.treeants[i];
        }
    }

    return *this;
}

Player *Druid::clone() const
{
    return new Druid(*this);
}

Druid::~Druid()
{
    if (treeants != NULL)

    {
        delete[] treeants;
    }
}

Druid::operator std::string() const
{
    std::stringstream ss;
    ss << "Druid:" << static_cast<std::string>(Support::operator std::string()) << ",treeants=[";
    if (treeants != NULL)
    {
        for (int i = 0; i < numTreeants; i++)
        {
            ss << treeants[i];
            if (i < numTreeants - 1)
                ss << ",";
        }
    }
    ss << "]";
    return ss.str();
}

void Druid::operator>>(const Party &otherParty) const
{
    if (otherParty.getNumMembers() == 0)
        return;

    Druid copy(*this);

    for (int i = 0; i < speed; i++)
    {
        int dicenum = dice->nextInt();
        int a = dicenum / 8 + 1;

        std::cout << copy.name << " rolled a " << dicenum << " and summons " << a
                  << " treeants with a lifetime of " << copy.mana << std::endl;

        int *newtreeants = new int[copy.numTreeants + a];
        if (copy.numTreeants > 0 && copy.treeants != NULL)
        {
            for (int k = 0; k < copy.numTreeants; k++)
            {
                newtreeants[k] = copy.treeants[k];
            }
        }
        for (int p = 0; p < a; p++)
        {
            newtreeants[copy.numTreeants + p] = copy.mana;
        }

        if (copy.treeants != NULL)
            delete[] copy.treeants;

        copy.treeants = newtreeants;

        copy.numTreeants += a;
    }
    for (int u = 0; u < copy.numTreeants; u++)
    {
        int target = u % otherParty.getNumMembers();
        int damage = power * copy.treeants[u];

        std::cout << copy.name << ": treeant " << u << " does " << damage
                  << " damage to " << otherParty[target]->getName() << std::endl;

        copy.treeants[u]--;
    }
}

void Druid::operator>>=(Party &otherParty)
{
    if (otherParty.getNumMembers() == 0)
        return;

    for (int i = 0; i < speed; i++)
    {
        int dicenum = dice->nextInt();
        int a = dicenum / 8 + 1;

        std::cout << name << " rolled a " << dicenum << " and summons " << a
                  << " treeants with a lifetime of " << mana << std::endl;

        int *newtreeants = new int[numTreeants + a];
        if (treeants != NULL)
        {
            for (int k = 0; k < numTreeants; k++)
            {
                newtreeants[k] = treeants[k];
            }
        }
        for (int p = 0; p < a; p++)
        {
            newtreeants[numTreeants + p] = mana;
        }

        if (treeants != NULL)
            delete[] treeants;

        treeants = newtreeants;
        numTreeants += a;
    }
    for (int u = 0; u < numTreeants; u++)
    {
        int target = u % otherParty.getNumMembers();
        int damage = power * treeants[u];
        otherParty[target]->changeHealth(-damage);

        std::cout << name << ": treeant " << u << " does " << damage
                  << " damage to " << otherParty[target]->getName() << std::endl;

        treeants[u]--;
    }

    int kickingants = 0;
    for (int j = 0; j < numTreeants; ++j)
    {
        if (treeants[j] > 0)
            kickingants++;
    }

    int *filt = new int[kickingants];
    int in = 0;
    for (int pp = 0; pp < numTreeants; pp++)
    {
        if (treeants[pp] > 0)
        {
            filt[in] = treeants[pp];
            in++;
        }
    }

    delete[] treeants;
    treeants = filt;
    numTreeants = kickingants;

    for (int i = 0; i < otherParty.getNumMembers(); i++)
    {
        if (otherParty[i] != NULL)
        {
            if (otherParty[i]->getHealth() <= 0)
            {
                otherParty.operator-=(i);
                i--;
            }
        }
    }
}

void Druid::operator<<(const Party &otherParty) const
{
    if (otherParty.getNumMembers() == 0)
        return;

    Druid copy = Druid(*this);

    for (int i = 0; i < copy.speed; i++)
    {
        int dicenum = dice->nextInt();
        int a = dicenum / 8 + 1;

        std::cout << copy.name << " rolled a " << dicenum << " and summons " << a
                  << " treeants with a lifetime of " << copy.mana << std::endl;

        int *newtreeants = new int[copy.numTreeants + a];
        if (copy.treeants != NULL)
        {
            for (int k = 0; k < copy.numTreeants; k++)
            {
                newtreeants[k] = copy.treeants[k];
            }
        }
        for (int p = 0; p < a; p++)
        {
            newtreeants[copy.numTreeants + p] = copy.mana;
        }

        if (copy.treeants != NULL)
            delete[] copy.treeants;

        copy.treeants = newtreeants;
        copy.numTreeants += a;
    }
    for (int u = 0; u < copy.numTreeants; u++)
    {
        int target = u % otherParty.getNumMembers();
        int heals = copy.power * copy.treeants[u];

        std::cout << copy.name << ": treeant " << u << " heals " << otherParty[target]->getName() << " by " << heals << std::endl;
    }
}

void Druid::operator<<=(Party &otherParty)
{
    if (otherParty.getNumMembers() == 0)
        return;

    Druid copy = Druid(*this);

    for (int i = 0; i < speed; i++)
    {
        int dicenum = dice->nextInt();
        int a = dicenum / 8 + 1;

        std::cout << name << " rolled a " << dicenum << " and summons " << a
                  << " treeants with a lifetime of " << mana << std::endl;

        int *newtreeants = new int[numTreeants + a];
        if (treeants != NULL)
        {
            for (int k = 0; k < numTreeants; k++)
            {
                newtreeants[k] = treeants[k];
            }
        }
        for (int p = 0; p < a; p++)
        {
            newtreeants[numTreeants + p] = mana;
        }

        if (treeants != NULL)
            delete[] treeants;

        treeants = newtreeants;
        numTreeants += a;
    }
    for (int u = 0; u < numTreeants; u++)
    {
        int target = u % otherParty.getNumMembers();
        int heals = power * treeants[u];
        otherParty[target]->changeHealth(heals);

        std::cout << name << ": treeant " << u << " heals " << otherParty[target]->getName() << " by " << heals << std::endl;

        treeants[u]--;
    }

    int kickingants = 0;
    for (int j = 0; j < numTreeants; ++j)
    {
        if (treeants[j] > 0)
            kickingants++;
    }

    int *filt = new int[kickingants];
    int in = 0;
    for (int pp = 0; pp < numTreeants; pp++)
    {
        if (treeants[pp] > 0)
        {
            filt[in] = treeants[pp];
            in++;
        }
    }

    delete[] treeants;
    treeants = filt;
    numTreeants = kickingants;
}