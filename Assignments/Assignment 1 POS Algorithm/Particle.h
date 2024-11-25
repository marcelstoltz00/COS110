#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream>
#include <string>

#include "Function.h"
#include "Vector.h"
#include "SwarmGenerator.h"

class Particle
{
private:
    Vector *position;//represents the pos 
    Vector *velocity;// represents the velocity of the velocity and position has same amount of components
    Vector *pBest;//best position of the particle thus far
    double w;//inertia
    double c1;//cognitive acceleration 
    double c2;//social acce
    double vMax;//absolute max velocity of a particle





public:
    //|[attr1,...,attrN]|[v1,...,vN]|w|c1|c2|
    Particle(std::string line);
    Particle(const Particle &other);
    ~Particle();
    void updateParticle(const Particle &gBest);
    const Vector& getPosition() const;
    const Vector& getVelocity() const;
    const Vector *getPBest() const;
    void setVMax(double vMax);
    double evaluate(const Function& function);
    bool equal(const Particle& other) const;
    const std::string toString() const
    {
        std::string result = "P: " + (position != NULL ? position->toString() : "NULL") + "\tV: " + (velocity != NULL ? velocity->toString() : "NULL");
        return result;
    }
    double getW() const;
    double getC1() const;
    double getC2() const;
    double getVMax() const;
};

#endif /*PARTICLE_H*/