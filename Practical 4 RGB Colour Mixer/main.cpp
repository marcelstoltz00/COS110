#include <iostream>
#include "mixer.h"

using namespace std;

int main()
{
    Mixer myMixer(50, 100, 150);

    std::cout << myMixer.displayPalette() << std::endl;

    Colour newColour(200, 50, 100);
    myMixer.addColour(3, newColour);
    std::cout << myMixer.displayPalette() << std::endl;

    Colour retrievedColour = myMixer.getColour(3);
    std::cout << retrievedColour.getRed()
              << retrievedColour.getGreen()
              << retrievedColour.getBlue() << std::endl;

    myMixer.mixTwo(2, 3);
    std::cout << myMixer.displayPalette() << std::endl;

    myMixer.mixRatio(4, 0.5);
    std::cout << myMixer.displayPalette() << std::endl;

    Colour newPalette[10] = {Colour(10, 20, 30), Colour(40, 50, 60), Colour(70, 80, 90), Colour(100, 110, 120),
                             Colour(130, 140, 150), Colour(160, 170, 180), Colour(190, 200, 210), Colour(220, 230, 240),
                             Colour(250, 240, 230), Colour(220, 210, 200)};
    myMixer += newPalette;
    std::cout << myMixer.displayPalette() << std::endl;

    Mixer anotherMixer(60, 120, 180);
    myMixer + anotherMixer;
    std::cout << myMixer.displayPalette() << std::endl;

    myMixer *= 0.8;
    std::cout << myMixer.displayPalette() << std::endl;

    return 0;
}