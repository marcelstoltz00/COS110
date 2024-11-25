#include <cstdio>
#include <iostream>

#include "RandomNumberGenerator.h"
//
#include "Party.h"
//
#include "Player.h"
//
#include "MeleeWarrior.h"
#include "Ranger.h"
#include "Support.h"
//
#include "Barbarian.h"
#include "Cleric.h"
#include "Druid.h"
#include "Rogue.h"
#include "SiegeWeapon.h"
#include "Wizard.h"

void clericTest()
{
    Cleric c2("c2", 20, 20, 20, 5, 2);
    Party p1(c2);
    Cleric c3(c2);
    Cleric c4("c2", 2, 3, 4, 5, 6);
    Party p2(c4);

    p1 >> p2;
    p2 << p1;

    p1 >>= p2;
    p2 <<= p1;

    c4 = c2;
    std::cout << c4 << std::endl;
}

void testClasses()
{
    SiegeWeapon s1("SiegeWeapon1", 100, 2, 2, 5);
    Wizard w1("Wizard 1", 50, 20, 10, 2, 5);
    Support sup1("Support 1", 100, 12, 15, 10);
    Rogue rog1("Rogue 1", 100, 20, 10, 10, 100);
    Ranger ran1("Ranger 1", 100, 20, 20, 5);
    MeleeWarrior mel1("Melee Warrior 1", 100, 20, 15, 10);
    Druid drui1("Druid 1", 100, 10, 15, 10);
    Cleric cler1("Cler 1", 200, 30, 10, 10, 10);
    Barbarian barb1("Barbarian 1", 100, 20, 30, 30);

    std::cout << s1 << w1 << sup1 << rog1 << ran1 << mel1 << drui1 << cler1 << barb1 << std::endl;

    SiegeWeapon s2(s1);
    Wizard w2(w1);
    Support s3(sup1);
    Rogue rog2(rog1);
    Ranger ran(ran1);
    MeleeWarrior mel2(mel1);
    Druid drui2(drui1);
    Cleric cler2(cler1);
    Barbarian barb2(barb1);
}
void testdefense()
{

    SiegeWeapon s1("SiegeWeapon1", 100, 2, 2, 5);
    SiegeWeapon s2("SiegeWeapon1", 100, 2, 2, 5);
    Party p1(s1);
    s1 = s2;

    MeleeWarrior m1("m1", 10, 20, 10, 1);

    Ranger r1("Ranger1", 80, 20, 10, 5);
    Party p2(r1);

    Wizard w1("Wizard1", 120, 25, 15, 3, 100);
    Party p3(w1);

    Support sup1("Support1", 90, 15, 20, 50);
    Party p4(sup1);

    Rogue rogue1("Rogue1", 70, 18, 12, 10, 5);
    Party p5(rogue1);

    Druid d1("Druid1", 50, 5, 2, 20);
    Party p6(d1);

    Cleric cleric1("Cleric1", 60, 10, 18, 40, 80);
    Party p7(cleric1);

    Barbarian barbarian1("Barbarian1", 150, 30, 25, 10);
    Party p8(barbarian1);

    MeleeWarrior m2("m1", 10, 20, 10, 1);
    m1 = m2;

    Ranger r2("Ranger1", 80, 20, 10, 5);
    r1 = r2;

    Wizard w2("Wizard1", 120, 25, 15, 3, 100);

    w1 = w2;
    Support sup2("Support1", 90, 15, 20, 50);
    sup2 = sup1;

    Rogue rogue2("Rogue1", 70, 18, 12, 10, 5);
    rogue1 = rogue2;

    Druid d2("Druid1", 50, 5, 2, 20);

    d2 = d1;
    Cleric cleric2("Cleric1", 60, 10, 18, 40, 80);
    cleric1 = cleric2;

    Barbarian barbarian2("Barbarian1", 150, 30, 25, 10);
    barbarian1 = barbarian2;

    barbarian1.getHealth();
    barbarian1.getName();
    barbarian1.changeHealth(1);
    barbarian1.changePower(1);
    barbarian1.changeSpeed(1);

    r1.getHealth();
    r1.getName();
    r1.changeHealth(1);
    r1.changePower(1);
    r1.changeSpeed(1);

    cleric1.getHealth();
    cleric1.getName();
    cleric1.changeHealth(1);
    cleric1.changePower(1);
    cleric1.changeSpeed(1);

    m1.getHealth();
    m1.getName();
    m1.changeHealth(1);
    m1.changePower(1);
    m1.changeSpeed(1);

    w1.getHealth();
    w1.getName();
    w1.changeHealth(1);
    w1.changePower(1);
    w1.changeSpeed(1);
    s1.getHealth();
    s1.getName();
    s1.changeHealth(1);
    s1.changePower(1);
    s1.changeSpeed(1);
    d1.getHealth();
    d1.getName();
    d1.changeHealth(1);
    d1.changePower(1);
    d1.changeSpeed(1);

    sup1.getHealth();
    sup1.getName();
    sup1.changeHealth(1);
    sup1.changePower(1);
    sup1.changeSpeed(1);

    rogue1.getHealth();
    rogue1.getName();
    rogue1.changeHealth(1);
    rogue1.changePower(1);
    rogue1.changeSpeed(1);

    p8[0];
    p8.operator+=(cleric1);
    p8.operator-=(0);
    p8 + cleric1;
    p8 - 0;
    rogue1.changeHealth(12);

    p1 << p2;
    p3 << p4;
    p5 << p6;
    p7 << p8;

    p2 << p1;
    p4 << p3;
    p6 << p5;
    p8 << p7;

    p1 <<= p2;
    p3 <<= p4;
    p5 <<= p6;
    p7 <<= p8;

    p2 <<= p1;
    p4 <<= p3;
    p4 <<= p5;
    p6 <<= p5;
    p8 <<= p7;
}
void testattack()
{

    SiegeWeapon s1("SiegeWeapon1", 100, 2, 2, 5);
    Party p1(s1);

    Ranger r1("Ranger1", 80, 20, 10, 5);
    Party p2(r1);

    Wizard w1("Wizard1", 120, 25, 15, 3, 100);
    Party p3(w1);

    Support sup1("Support1", 90, 15, 20, 50);
    Party p4(sup1);

    Rogue rogue1("Rogue1", 70, 18, 12, 10, 5);
    Party p5(rogue1);

    Druid d1("Druid1", 50, 5, 2, 20);
    Party p6(d1);

    Cleric cleric1("Cleric1", 60, 10, 18, 40, 80);
    Party p7(cleric1);

    Barbarian barbarian1("Barbarian1", 150, 30, 25, 10);
    Party p8(barbarian1);

    p1 >> p2;
    p2 >> p1;

    p3 >> p4;

    p4 >> p5;

    p5 >> p6;
    p6 >> p5;

    p7 >> p8;
    p8 >> p7;
    p7 >>= p8;
    p2 >>= p1;
    p1 >>= p2;
    p4 >>= p5;
    p5 >>= p6;
    p6 >>= p5;
    p8 >>= p7;
    p3 >>= p4;
}

void theirtest()
{

    SiegeWeapon s1("SiegeWeapon1", 100, 2, 2, 5);
    Party p1(s1);

    Druid d1("Druid1", 50, 5, 2, 20);
    Party p2(d1);

    p1 >> p2;
    p2 >> p1;

    p1 >>= p2;
    p2 >>= p1;

    std::cout << "Party 1 : " << p1 << std::endl
              << "Party 2 : " << p2 << std::endl;

    //  return 0;
}

void testparty()
{

    SiegeWeapon s1("SiegeWeapon1", 100, 2, 4, 5);
    Ranger r1("Ranger1", 100, 10, 5, 4);
    Wizard w1("Wizard1", 120, 25, 15, 5, 10);
    Druid d1("Druid1", 50, 5, 2, 20);
    Cleric cleric1("Cleric1", 60, 10, 18, 2, 10);
    Barbarian barbarian1("Barbarian1", 150, 30, 4, 10);
    Rogue rogue1("Rogue1", 70, 18, 12, 2, 5);
    Support sup1("Support1", 90, 15, 2, 5);

    Party p1(s1);
    p1 += r1;
    p1 += w1;
    p1 += d1;
    Party p2(cleric1);
    p2 += barbarian1;
    p2 += rogue1;
    p2 += sup1;

    std::cout << "Initial Parties:" << std::endl;
    std::cout << "Party 1: " << p1 << std::endl
              << std::endl;
    std::cout << "Party 2: " << p2 << std::endl
              << std::endl;

    p1 >> p2;
    p2 >> p1;
    p1 << p2;
    p2 << p1;

    p1 >>= p2;
    std::cout << "Party 1: " << p1 << std::endl;
    std::cout << "Party 2: " << p2 << std::endl;

    p2 >>= p1;
    std::cout << "Party 1: " << p1 << std::endl;
    std::cout << "Party 2: " << p2 << std::endl;

    p1 <<= p2;
    std::cout << "Party 1: " << p1 << std::endl;
    std::cout << "Party 2: " << p2 << std::endl;
    p2 <<= p1;

    std::cout << "Party 1: " << p1 << std::endl;
    std::cout << "Party 2: " << p2 << std::endl;
}
void Druidtest()
{

    Druid d1("d1", 20, 20, 20, 5);
    Party p1(d1);
    Cleric c4("c4", 2, 3, 4, 5, 6);
    Party p2(c4);

    p1 >> p2;
    p1 << p2;
    p1 <<= p2;
    p1 >>= p2;
}
void siegeweapon()
{

    SiegeWeapon s1("s1", 20, 20, 3, 5);
    Party p1(s1);
    SiegeWeapon r1("s2", 2, 3, 4, 5);
    Party p2(r1);

    p1 >> p2;
    p1 << p2;

    std::cout << "part 2" << std::endl;
    p1 <<= p2;
    p1 >>= p2;
}
void Druidtest2()
{
    std::cout << "Druidtest Start" << std::endl;

    // Create a Druid and Party
    Druid d1("d1", 20, 20, 20, 5);
    Party p1(d1); // Party with a Druid
    Cleric c4("c4", 2, 3, 4, 5, 6);
    Party p2(c4); // Party with a Cleric

    // Test Druid attacking another Party
    std::cout << "p1 attacks p2" << std::endl;
    p1 >> p2;

    // Test Druid healing the other Party
    std::cout << "p1 heals p2" << std::endl;
    p1 << p2;

    // Test Druid special attack and healing with combinations of overloaded operators
    std::cout << "p1 special attack on p2" << std::endl;
    p1 <<= p2;

    std::cout << "p1 special healing on p2" << std::endl;
    p1 >>= p2;

    std::cout << "Druidtest End" << std::endl;
}

void siegeweapon2()
{
    std::cout << "SiegeWeapon Test Start" << std::endl;

    // Create SiegeWeapon and Party
    SiegeWeapon s1("s1", 20, 20, 3, 5);
    Party p1(s1); // Party with SiegeWeapon

    SiegeWeapon r1("r1", 2, 3, 4, 5);
    Party p2(r1); // Another Party with SiegeWeapon

    // Test SiegeWeapon attacking another Party
    std::cout << "p1 attacks p2" << std::endl;
    p1 >> p2;

    // Test SiegeWeapon special attack
    std::cout << "p1 special attack on p2" << std::endl;
    p1 <<= p2;

    std::cout << "SiegeWeapon Test End" << std::endl;
}

int main(int argc, char *argv[])
{

    theirtest();
  //  partytests();
    testattack();
    testdefense();
    testClasses();

    testparty();
    theirtest();
   // hopefullythelastTest();

    clericTest();

    Druidtest2();
    siegeweapon2();

    return 0;
}