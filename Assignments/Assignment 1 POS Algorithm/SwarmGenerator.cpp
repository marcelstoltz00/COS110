#include "SwarmGenerator.h"

using namespace std;

string generateSwarm(const SwarmGenerationProperties &props, long seed)
{
    //|[attr1,...,attrN]|[v1,...,vN]|w|c1|c2|
    srand(seed);
    string result = "";
    for (int i = 0; i < props.numParticles; i++)
    {
        result += "|[";
        string position = "";
        string velocity = "";
        for (int j = 0; j < props.numAttributes; j++)
        {
            double pJ = getRandomNumber(props.minPositionValue, props.maxPositionValue);
            double vJ = getRandomNumber(props.minVelocity, props.maxVelocity);
            
            if (j + 1 >= props.numAttributes)
            {
                position += fromDoubleToString(pJ);
                velocity += fromDoubleToString(vJ);
            }
            else
            {
                position += fromDoubleToString(pJ) + ",";
                velocity += fromDoubleToString(vJ) + ",";
            }
        }
        result += position + "]|[" + velocity + "]|" + 
            fromDoubleToString(getRandomNumber(props.minW, props.maxW)) + "|" + 
            fromDoubleToString(getRandomNumber(props.minC1, props.maxC1)) + "|" +
            fromDoubleToString(getRandomNumber(props.minC2, props.maxC2)) + "|\n";
    }
    return result;
}

double getRandomNumber(double min, double max)
{
    long max_rand = 1000000L;
    if (min > max)
    {
        double temp;
        temp = max;
        max = min;
        min = temp;
    }
    int randVal = rand();
    return min + (max - min) * (randVal % (int)floor(max_rand)) / max_rand;
}

string fromDoubleToString(double v)
{
    stringstream ss;
    ss << v;
    return ss.str();
}

void defaultSettings(SwarmGenerationProperties &props)
{
    props.maxC1 = 0.5;
    props.maxC2 = 0.5;
    props.maxPositionValue = 100;
    props.maxVelocity = 1;
    props.maxW = 0.5;
    props.minC1 = 0.1;
    props.minC2 = 0.1;
    props.minPositionValue = -100;
    props.minVelocity = 0.1;
    props.minW = 0.1;
    props.numAttributes = 2;
    props.numParticles = 10;
}

void toFile(string fileName, string content)
{
    ofstream file(fileName.c_str());

    file << content;

    file.close();
}
