#ifndef RANDOMNUMBERGENERATOR_H
#define RANDOMNUMBERGENERATOR_H

#include <cmath>

class RandomNumberGenerator {
   protected:
    int a;
    int c;
    int m;
    int value;

   public:
    RandomNumberGenerator(int seed) {
        a = 1103515245;
        c = 12345;
        m = 2147483648;
        value = seed;
    }

    RandomNumberGenerator(const RandomNumberGenerator& other) {
        a = other.a;
        c = other.c;
        m = other.m;
        value = other.value;
    }

    int nextInt(int minVal = 1, int maxVal = 20) {
        if (a == 0) {
            return c;
        }
        value = abs((a * value + c) % m);
        return value % (maxVal - minVal + 1) + minVal;
    }
    void lockDiceRoll(int nextValue) {
        a = 0;
        c = nextValue;
    }
    void unlockDiceRoll() {
        a = 1103515245;
        c = 12345;
    }
};

#endif