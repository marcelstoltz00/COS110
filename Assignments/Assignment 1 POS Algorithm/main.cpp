#include <iostream>
#include <string>
#include <fstream>
#include "Function.h"
#include "Vector.h"
#include "Particle.h"
#include "PSO.h"
#include "SwarmGenerator.h"

using namespace std;

void studentExample()
{

    //   int line=1;
    //   std::cout<<line++;
    //  SwarmGenerationProperties sgp;
    //   std::cout<<line++;
    // defaultSettings(sgp);
    // std::cout<<line++;
    // toFile("studentExample.txt", generateSwarm(sgp, 110));
    // std::cout<<line++;
    PSO *pso1 = new PSO("studentExample.txt"); // definitely me giving the error
    // std::cout<<line++;
    pso1->setMaxV(10);
    // std::cout<<line++;
    cout << "Population" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "Particle " << i << ": " << pso1->getParticle(i)->toString() << endl;
    }
    cout << "Manual Loop" << endl;
    for (int i = 0; i < 20; i++)
    {
        cout << "Generation " << i << endl;
        Particle best = pso1->run(Function());
        for (int j = 0; j < 10; j++)
        {
            cout << "\tParticle " << j << ": " << pso1->getParticles()[j]->toString() << endl;
        }
        cout << "Best particle: " << best.toString() << endl;
        cout << endl;
    }
    delete pso1;
    pso1 = new PSO("studentExample.txt");
    pso1->setMaxV(10);
    Particle **results = pso1->run(20, Function());
    for (int i = 0; i < 20; i++)
    {
        cout << "Generation " << i << " best particle: " << results[i]->toString() << endl;
        delete results[i];
    }
    delete[] results;
    delete pso1;
}
void modstudentExample()
{
    //  SwarmGenerationProperties sgp;
    //   defaultSettings(sgp);
    // toFile("studentExample.txt", generateSwarm(sgp, 110));
    PSO *pso1 = new PSO("studentExample.txt");
    pso1->setMaxV(10);
    cout << "Population" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "Particle " << i << ": " << pso1->getParticle(i)->toString() << endl;
    }
    cout << "Manual Loop" << endl;
    for (int i = 0; i < 20; i++)
    {
        cout << "Generation " << i << endl;
        cout << "Initial: " << endl;
        for (int j = 0; j < 10; j++)
        {
            Particle *p = pso1->getParticles()[j];
            cout << "\tParticle " << j << ": " << (pso1->getParticles()[j]->toString()) << " W: " << p->getW() << " C1: " << p->getC1() << " C2: " << p->getC2();
            cout << "pBest: " << (p->getPBest() != NULL ? p->getPBest()->toString() : "NULL") << endl;
        }
        Particle best = pso1->run(Function());
        for (int j = 0; j < 10; j++)
        {
            cout << "\tParticle " << j << ": " << (pso1->getParticles()[j]->toString()) << endl;
        }
        cout << "Best particle: " << (best.toString()) << endl;
        cout << endl;
    }
    delete pso1;
    pso1 = new PSO("studentExample.txt");
    pso1->setMaxV(10);
    Particle **results = pso1->run(20, Function());
    for (int i = 0; i < 20; i++)
    {
        cout << "Generation " << i << " best particle: " << (results[i]->toString()) << endl;
        delete results[i];
    }
    delete[] results;
    delete pso1;
}
void myexample()
{

    std::string particle_str = "|[-18.0057, 5.59675]|[-5.72035, -9.41285]|0.413716|0.251389|0.381295|";
    Particle particle(particle_str);

    std::cout << "Initial State:" << std::endl;
    std::cout << "Position: " << particle.getPosition().toString() << std::endl;
    std::cout << "Velocity: " << particle.getVelocity().toString() << std::endl;
    std::cout << "W: " << particle.getW() << std::endl;
    std::cout << "C1: " << particle.getC1() << std::endl;
    std::cout << "C2: " << particle.getC2() << std::endl;
    std::cout << "pBest: " << (particle.getPBest() ? particle.getPBest()->toString() : "NULL") << std::endl;

    std::string gbest_str = "|[-10.0, 0.0]|[0.0, 0.0]|0.413716|0.251389|0.381295|";
    Particle gBest(gbest_str);

    particle.updateParticle(gBest);

    std::cout << "\nAfter Update:" << std::endl;
    std::cout << "Position: " << particle.getPosition().toString() << std::endl;
    std::cout << "Velocity: " << particle.getVelocity().toString() << std::endl;

    Vector v1("[1.1, 2.2, 3.3]");
    std::cout << "Vector v1: " << v1.toString() << std::endl;

    Vector v2(v1);
    std::cout << "Copied Vector v2: " << v2.toString() << std::endl;

    double arr[] = {4.4, 5.5, 6.6};
    Vector v3(arr, 3);
    std::cout << "Array Constructor Vector v3: " << v3.toString() << std::endl;

    std::cout << (v1.equal(v2) ? "True" : "False") << std::endl;
    std::cout << (v1.equal(v3) ? "True" : "False") << std::endl;

    std::cout << Vector::fromDoubleToString(5.0) << std::endl;
    std::cout << Vector::fromDoubleToString(5.25) << std::endl;

    Particle p1("|[0.1, 1.1]|[0.2, 1.2]|0.5|1.0|1.5|");
    std::cout << p1.toString() << std::endl;

    Particle p2(p1);
    std::cout << p2.toString() << std::endl;

    p1.updateParticle(p2);
    std::cout << p1.toString() << std::endl;

    PSO *pso = new PSO("studentExample.txt");
    pso->setMaxV(5);
    std::cout << "Number of Particles: " << pso->getNumberOfParticles() << std::endl;

    Particle *bestParticle = pso->getBestParticle(Function());
    std::cout << "Best Particle: " << bestParticle->toString() << std::endl;

    Particle **results = pso->run(10, Function());
    for (int i = 0; i < 10; i++)
    {
        std::cout << "Best Particle in Generation " << i << ": " << results[i]->toString() << std::endl;
        delete results[i];
    }
    delete[] results;

    Particle newParticle("|[2.1, 3.1]|[2.2, 3.2]|0.6|1.2|1.8|");
    int newIndex = pso->addParticle(newParticle);
    std::cout << "Added Particle at index: " << newIndex << std::endl;
    std::cout << "Particle at new index: " << pso->getParticle(newIndex)->toString() << std::endl;

    bool removedByPosition = pso->removeParticle(v1);
    std::cout << "Removed Particle by position: " << (removedByPosition ? "Success" : "Failure") << std::endl;
    bool removedByInstance = pso->removeParticle(p1);
    std::cout << "Removed Particle by instance: " << (removedByInstance ? "Success" : "Failure") << std::endl;
    bool removedByIndex = pso->removeParticle(newIndex);
    std::cout << "Removed Particle by index: " << (removedByIndex ? "Success" : "Failure") << std::endl;

    Particle *specificParticle = pso->getParticle(0);
    if (specificParticle != NULL)
    {
        std::cout << "Specific Particle at index 0: " << specificParticle->toString() << std::endl;
    }
    else
    {
        std::cout << "No particle at index 0." << std::endl;
    }

    delete pso;
}
void removeparticle()
{

    std::string particle_str = "|[-18.0057, 5.59675]|[-5.72035, -9.41285]|0.413716|0.251389|0.381295|";
    Particle particle(particle_str);

    std::cout << "Initial State:" << std::endl;
    std::cout << "Position: " << particle.getPosition().toString() << std::endl;
    std::cout << "Velocity: " << particle.getVelocity().toString() << std::endl;
    std::cout << "W: " << particle.getW() << std::endl;
    std::cout << "C1: " << particle.getC1() << std::endl;
    std::cout << "C2: " << particle.getC2() << std::endl;
    std::cout << "pBest: " << (particle.getPBest() ? particle.getPBest()->toString() : "NULL") << std::endl;

    std::string gbest_str = "|[-10.0, 0.0]|[0.0, 0.0]|0.413716|0.251389|0.381295|";
    Particle gBest(gbest_str);
    particle.updateParticle(gBest);

    std::cout << "\nAfter Update:" << std::endl;
    std::cout << "Position: " << particle.getPosition().toString() << std::endl;
    std::cout << "Velocity: " << particle.getVelocity().toString() << std::endl;

    Vector v1("[1.1, 2.2, 3.3]");
    std::cout << "Vector v1: " << v1.toString() << std::endl;

    Vector v2(v1);
    std::cout << "Copied Vector v2: " << v2.toString() << std::endl;

    double arr[] = {4.4, 5.5, 6.6};
    Vector v3(arr, 3);
    std::cout << "Array Constructor Vector v3: " << v3.toString() << std::endl;

    std::cout << (v1.equal(v2) ? "True" : "False") << std::endl;

    std::cout << Vector::fromDoubleToString(5.0) << std::endl;
    std::cout << Vector::fromDoubleToString(5.25) << std::endl;

    Particle p1("|[0.1, 1.1]|[0.2, 1.2]|0.5|1.0|1.5|");
    std::cout << p1.toString() << std::endl;

    Particle p2(p1);
    std::cout << p2.toString() << std::endl;

    p1.updateParticle(p2);
    std::cout << p1.toString() << std::endl;

    PSO *pso = new PSO("studentExample.txt");
    pso->setMaxV(5);
    std::cout << "Number of Particles: " << pso->getNumberOfParticles() << std::endl;

    Particle *bestParticle = pso->getBestParticle(Function());
    std::cout << "Best Particle: " << bestParticle->toString() << std::endl;

    Particle **results = pso->run(10, Function());
    for (int i = 0; i < 10; i++)
    {
        std::cout << "Best Particle in Generation " << i << ": " << results[i]->toString() << std::endl;
        delete results[i];
    }
    delete[] results;

    Particle newParticle("|[2.1, 3.1]|[2.2, 3.2]|0.6|1.2|1.8|");
    int newIndex = pso->addParticle(newParticle);
    std::cout << "Added Particle at index: " << newIndex << std::endl;
    std::cout << "Particle at new index: " << pso->getParticle(newIndex)->toString() << std::endl;

    bool removedByPosition = pso->removeParticle(v1);
    std::cout << "Removed Particle by position: " << (removedByPosition ? "Success" : "Failure") << std::endl;

    bool removedByInstance = pso->removeParticle(p1);
    std::cout << "Removed Particle by instance: " << (removedByInstance ? "Success" : "Failure") << std::endl;

    bool removedByIndex = pso->removeParticle(newIndex);
    std::cout << "Removed Particle by index: " << (removedByIndex ? "Success" : "Failure") << std::endl;

    Particle *specificParticle = pso->getParticle(0);
    if (specificParticle != NULL)
    {
        std::cout << "Specific Particle at index 0: " << specificParticle->toString() << std::endl;
    }
    else
    {
        std::cout << "No particle at index 0." << std::endl;
    }

    delete pso;
}
int main()
{
    myexample();
    removeparticle();

    studentExample();
    modstudentExample();

    return 0;
}