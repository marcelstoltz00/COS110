#include "colour.h"

Colour::Colour(int red, int green, int blue)
{
    this->red = red;
    this->blue = blue;
    this->green = green;
};
Colour::~Colour() {};
int Colour::getRed() { return red; };
int Colour::getGreen() { return green; };
int Colour::getBlue() { return blue; };
Colour Colour::operator+(const Colour &other)
{
    Colour newcol;
    newcol.red = (this->red + other.red) / 2;
    newcol.blue = (this->blue + other.blue) / 2;
    newcol.green = (this->green + other.green) / 2;
       if (newcol.red > 255)
    {
        newcol.red = 255;
    };
    if (newcol.blue > 255)
    {
        newcol.blue = 255;
    };
    if (newcol.green > 255)
    {
        newcol.green = 255;
    };


    return newcol;
};
Colour Colour::operator-(const Colour &other)
{

    Colour newcol;
    newcol.red = std::abs((this->red - other.red)) / 2;
    newcol.blue = std::abs(this->blue - other.blue) / 2;
    newcol.green = std::abs(this->green - other.green) / 2;

    return newcol;
};
Colour &Colour::operator+=(const Colour &other)
{

       this->red = this->red + (this->red + other.red) / 2;
    this->blue = this->blue + (this->blue + other.blue) / 2;
    this->green = this->green + (this->green + other.green) / 2;

    if (this->red > 255)
    {
        this->red = 255;
    };
    if (this->blue > 255)
    {
        this->blue = 255;
    };
    if (this->green > 255)
    {
        this->green = 255;
    };

    return *this;
};
Colour &Colour::operator-=(const Colour &other)
{

  this->red = this->red - (this->red - other.red) / 2;
    this->blue = this->blue - (this->blue - other.blue) / 2;
    this->green = this->green - (this->green - other.green) / 2;

        if (this->red <0)
    {
        this->red = 0;
    };
    if (this->blue < 0)
    {
        this->blue = 0;
    };
    if (this->green < 0)
    {
        this->green = 0;
    };

    return *this;
};
Colour Colour::operator*(double ratio)
{

    Colour newcol;
    newcol.red = (this->red * ratio);
    newcol.blue = (this->blue * ratio);
    newcol.green = (this->green * ratio);

    if (newcol.red > 255)
    {
        newcol.red = 255;
    };
    if (newcol.blue > 255)
    {
        newcol.blue = 255;
    };
    if (newcol.green > 255)
    {
        newcol.green = 255;
    };
    return newcol;
};
bool Colour::operator==(const Colour &rhs)
{

    if (this->green == rhs.green && this->blue == rhs.blue && this->red == rhs.red)
        return true;
    else
        return false;
};