#include "PSO.h"

PSO::PSO(std::string fileName)
{

    std::ifstream TXT(fileName.c_str());

    numParticles = 0;
    std::string line;

    while (getline(TXT, line))
    {
        numParticles++;
    }
    particles = new Particle *[numParticles];
    TXT.clear();

    std::ifstream txt(fileName.c_str());

    for (int i = 0; i < numParticles; i++)
    {
        getline(txt, line);
        particles[i] = new Particle(line);
    }
};
PSO::~PSO()
{
    if (particles == NULL)
    {
    }
    else
    {

        for (int i = 0; i < numParticles; i++)
        {
            if (particles[i] == NULL)
            {
            }
            else
            {
                delete particles[i];
                particles[i] = NULL;
            }
        }
        delete[] particles;
        particles = NULL;
    }
};
const Particle &PSO::run(const Function &func)
{
    Particle *newbest = getBestParticle(func);

    for (int i = 0; i < numParticles; i++)
    {
        particles[i]->updateParticle(*newbest);
    }
    return *newbest;

    /*

    Particle *newbest = NULL;

    for (int k = 0; k < numParticles; k++)
    {
        if (newbest == NULL || func.evaluate((particles[k])->getPosition()) < func.evaluate((newbest)->getPosition()))
        {
            newbest = particles[k];
        }
    }
    for (int i = 0; i < numParticles; i++)
    {
        particles[i]->updateParticle(*newbest);
    }
    return *newbest;*/
};
Particle **PSO::run(int numIterations, const Function &func)
{

    Particle **newbest = new Particle *[numIterations];

    for (int i = 0; i < numIterations; i++)
    {

        const Particle &bestParticle = this->run(func);

        newbest[i] = new Particle(bestParticle);
    }

    return newbest;

    /* Particle **newbest = new Particle *[numIterations];

     for (int i = 0; i < numIterations; i++)
     {

         const Particle &bestParticle = this->run(func);

         newbest[i] = new Particle(bestParticle);
     }

     return newbest;*/
};
Particle *PSO::getBestParticle(const Function &func) const
{

    Particle *newbest = NULL;

    for (int i = 0; i < numParticles; ++i)
    {

        //  if (newbest == NULL || func.evaluate(particles[i]->getPosition()) < func.evaluate(newbest->getPosition()))
        if (newbest == NULL || particles[i]->evaluate(func) < newbest->evaluate(func))
        {
            newbest = particles[i];
        }
    }

    return newbest;
    /*double best = INFINITY;
       Particle *newbest = particles[0];


       for (int i = 1; i < numParticles; ++i)
       {
           if (newbest == NULL || particles[i]->evaluate(func) < best)
           {
               newbest = particles[i];
               best =newbest->evaluate(func);
           }
       }

   Particle *newbest = particles[0];

   for (int i = 1; i < numParticles; ++i)
   {
       if ( particles[i]->evaluate(func) < newbest->evaluate(func))
       {
           newbest = particles[i];
       }
   }

   return newbest;*/
};
Particle **PSO::getParticles() const
{
    return particles;
};
int PSO::getNumberOfParticles() const
{
    return numParticles;
};
Particle *PSO::getParticle(int pos) const
{
    if (pos < 0 || pos >= numParticles)
        return NULL;
    else
        return particles[pos];
};
Particle *PSO::getParticle(const Vector &position) const
{

    for (int i = 0; i < numParticles; i++)
    {
        bool found = true;

        for (int j = 0; j < position.getSize(); j++)
        {
            if (position.getArray()[j] != particles[i]->getPosition().getArray()[j])
            {
                found = false;
                break;
            }
        }

        if (found)
        {
            return particles[i];
        }
    }

    return NULL;
};
int PSO::addParticle(const Particle &nParticle)
{

    Particle **np = new Particle *[numParticles + 1];

    for (int i = 0; i < numParticles; i++)
    {

        np[i] = particles[i];
    }
    np[numParticles] = new Particle(nParticle);
    delete[] particles;
    particles = np;
    numParticles++;

    return numParticles - 1;
};
bool PSO::removeParticle(const Particle &particle)
{

    bool remov = false;
    int newnumP = numParticles;

    for (int i = 0; i < numParticles; i++)
    {
        if (particles[i]->equal(particle) == true)
        {
            delete particles[i];
            remov = true;
            for (int j = i; j < numParticles - 1; j++)
            {
                particles[j] = particles[j + 1];
            }
            numParticles--;
            break;
        }
    }

    // now to resize

    if (remov == true)
    {

        Particle **np = new Particle *[newnumP];
        for (int i = 0; i < newnumP; i++)
        {
            np[i] = particles[i];
        }
        delete[] particles;
        particles = np;
    }

    return remov;
};
bool PSO::removeParticle(const Vector &position)
{

    bool remov = false;
    bool found = false;
    int newnumP = numParticles;

    for (int i = 0; i < numParticles; i++)
    {
        found = true;
        for (int j = 0; j < position.getSize(); j++)
        {
            if (position.getArray()[j] != particles[i]->getPosition().getArray()[j])
            {
                found = false;
                break;
            }
        }

        if (found)
        {
            delete particles[i];
            remov = true;
            for (int j = i; j < numParticles - 1; j++)
            {
                particles[j] = particles[j + 1];
            }
            newnumP--;
            break;
        }
    }

    // now to resize

    if (remov == true)
    {

        Particle **np = new Particle *[newnumP];
        for (int i = 0; i < newnumP; i++)
        {
            np[i] = particles[i];
        }
        delete[] particles;
        particles = np;
        numParticles = newnumP;
    }

    return remov;
};
bool PSO::removeParticle(int pos)
{
    int newnumP = numParticles;
    if (pos < 0 || pos >= numParticles)
        return false;

    delete particles[pos];

    for (int i = pos; i < newnumP - 1; i++)
    {
        particles[i] = particles[i + 1];
    }
    newnumP--;

    // now to resize

    Particle **np = new Particle *[newnumP];
    for (int i = 0; i < newnumP; i++)
    {
        np[i] = particles[i];
    }
    delete[] particles;
    particles = np;
    numParticles = newnumP;

    return true;
};
void PSO::setMaxV(double v)
{
    for (int i = 0; i < numParticles; i++)
    {
        particles[i]->setVMax(v);
    }
};
