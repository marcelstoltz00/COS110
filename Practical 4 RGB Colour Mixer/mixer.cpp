#include "mixer.h"

Mixer::Mixer(int red, int green, int blue)
{
    Colour oddcol(red, green, blue);
    Colour white(255, 255, 255);

    for (int i = 0; i < 10; i++)
    {

        if (i % 2 != 0)
            palette[i] = oddcol;
        else
            palette[i] = white;
    }
};
Mixer::~Mixer() {};
Colour *Mixer::getPalette() { return palette; };
bool Mixer::addColour(int index, const Colour &colourToAdd)
{
    if (index < 0 || index >= 10)
        return false;

    Colour white(255, 255, 255);

    if (palette[index].getBlue() == 255 && palette[index].getGreen() == 255 && palette[index].getRed() == 255)
        palette[index] = colourToAdd;
    else
        palette[index] += colourToAdd;

    return true;
};
Colour Mixer::getColour(int index)
{
    Colour special(-1, -1, -1);

    if (index < 0 || index >= 10)
        return special;
    else
        return palette[index];
};
std::string Mixer::displayPalette()
{
    std::stringstream str;
    for (int i = 0; i < 10; i++)
    {
        str << "Colour " << i << ": Red: " << palette[i].getRed() << " Green: " << palette[i].getGreen() << " Blue: " << palette[i].getBlue() << "\n";
    }
    return str.str();
};
bool Mixer::mixTwo(int colour1, int colour2)
{
    if (colour1 < 0 || colour1 >= 10 || colour2 < 0 || colour2 >= 10)
        return false;

    palette[colour1] += palette[colour2];

    palette[colour2] -= palette[colour1];
    return true;
};
bool Mixer::mixRatio(int colour, double ratio)
{
    if (colour < 0 || colour >= 10)
        return false;
    else
    {
        palette[colour] = palette[colour] * ratio;
        return true;
    }
};
Mixer &Mixer::operator+=(const Colour coloursToMix[10])
{

    for (int i = 0; i < 10; i++)
    {
        this->palette[i] += coloursToMix[i];
    }
    return *this;
};
Mixer &Mixer::operator+(const Mixer other)
{

    for (int i = 0; i < 10; i++)
    {

        if (i % 2 == 0)
        {
            palette[i] += other.palette[i];
        }
        else
        {
            palette[i] -= other.palette[i];
        }
    }
    return *this;
};
Mixer &Mixer::operator*=(double ratio)
{

    for (int i = 0; i < 10; i++)
    {
        palette[i] = palette[i] * ratio;
    }
    return *this;
};