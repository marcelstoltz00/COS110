#ifndef PSO_H
#define PSO_H

#include <string>
#include <fstream>

#include "Particle.h"

class PSO{
    private:
        Particle** particles;//This is a dynamic 1D array of dynamic Particle objects.
        int numParticles;//This member variable stores the total number of particles present in the array.

    public:
        PSO(std::string fileName);
        ~PSO();
        const Particle& run(const Function& func);
        Particle** run(int numIterations, const Function& func);
        Particle* getBestParticle(const Function& func) const;
        Particle** getParticles() const;
        int getNumberOfParticles() const;
        Particle* getParticle(int pos) const;
        Particle* getParticle(const Vector& position) const;
        int addParticle(const Particle& nParticle);
        bool removeParticle(const Particle& particle);
        bool removeParticle(const Vector& position);
        bool removeParticle(int pos);
        void setMaxV(double v);
};

#endif /*PSO_H*/