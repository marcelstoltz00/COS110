#ifndef SWARM_GENERATOR_H
#define SWARM_GENERATOR_H

#include <string>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <fstream>

struct SwarmGenerationProperties{
    int numParticles; 
    int numAttributes;
    double maxPositionValue; 
    double minPositionValue;
    double maxVelocity;
    double minVelocity;
    double maxW;
    double minW;
    double maxC1;
    double minC1;
    double maxC2;
    double minC2;
};

//|[attr1,...,attrN]|[v1,...,vN]|w|c1|c2|
std::string generateSwarm(const SwarmGenerationProperties& props, long seed);

double getRandomNumber(double min, double max);

std::string fromDoubleToString(double v);

void defaultSettings(SwarmGenerationProperties& props);

void toFile(std::string fileName, std::string content);


#endif /*SWARM_GENERATOR_H*/