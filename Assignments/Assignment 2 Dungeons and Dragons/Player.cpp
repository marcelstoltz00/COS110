#include "Player.h"

Player::Player(std::string name, int health, int power, int speed)
{
    this->name = name;
    this->health = health;
    this->power = power;
    this->speed = speed;

    dice = new RandomNumberGenerator(health * power * speed + health + power + speed);
};
Player::Player(const Player &other)
{

    name = other.name;
    health = other.health;
    power = other.power;
    speed = other.speed;
    this->dice = new RandomNumberGenerator(*other.dice);
};
Player &Player::operator=(const Player &other)
{
    if (this == &other)
        return *this;

    name = other.name;
    health = other.health;
    power = other.power;
    speed = other.speed;
    delete dice;
    this->dice = new RandomNumberGenerator(*other.dice);

    return *this;
};
Player::~Player()
{
    delete dice;
};

std::ostream &operator<<(std::ostream &os, const Player &player)
{
        os << std::string(player);

    return os;
};
Player::operator std::string() const
{

    std::stringstream str;
    str << name << ":health=" << health << ",power=" << power << ",speed=" << speed;

    return str.str();
};

void Player::changeHealth(int change)
{
    health = health + change;
};
void Player::changePower(int change)
{
    power = power+ change;
};
void Player::changeSpeed(int change)
{

    speed += change;
};
std::string Player::getName()
{
    return this->name;
};
int Player::getHealth()
{

    return health;
};