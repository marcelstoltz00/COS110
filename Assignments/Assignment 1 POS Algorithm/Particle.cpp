#include "Particle.h"
std::string stringCopy(const std::string &source, int start, int end)
{
    return source.substr(start, end - start + 1);
}
Particle::Particle(std::string line)
{
    /*
        [pC1,...,pCN]|[vC1,...,vCN]|w|c1|c2|
        ∗ pC stands for positionComponent
        ∗ vC stands for velocityComponent
        ∗ w is the inertia weight
        ∗ c1 is the cognitive acceleration coefficient ∗ c2 is the social acceleration coefficient*/

    std::string first, second, third, fourth, fifth;
    std::stringstream oss;
    // line="|[1.0,-26.0]|[0.555699,0.658027]|0.47231|0.352957|0.344642|";

    int start = 0, end = 0;

    start = line.find('|') + 1;
    end = line.find('|', start);

    first = stringCopy(line, start, end - 1);

    position = new Vector(first);
    // std::cout<<"pos:  "<<first;

    start = end + 1;
    end = line.find('|', start);

    second = stringCopy(line, start, end - 1);
    // std::cout<<"pos:  "<<second;

    velocity = new Vector(second);

    start = end + 1;
    end = line.find('|', start);
    ///|[69.754,-26.9342]|[0.555699,0.658027]|0.47231|0.352957|0.344642|

    third = stringCopy(line, start, end - 1);
    // std::cout<<"pos:  "<<third;

    std::stringstream othird(third);
    othird >> w;

    start = end + 1;
    end = line.find('|', start);

    fourth = stringCopy(line, start, end - 1);
    // std::cout<<"pos:  "<<fourth;

    std::stringstream ofour(fourth);
    ofour >> c1;

    start = end + 1;
    end = line.find('|', start);

    fifth = stringCopy(line, start, end - 1);
    // std::cout<<"pos:  "<<fifth;

    std::stringstream os(fifth);
    os >> c2;

    vMax = 1;
    pBest = NULL;
};
Particle::Particle(const Particle &other)
{

    c1 = other.c1;
    c2 = other.c2;
    w = other.w;
    vMax = other.vMax;

    position = new Vector(*other.position);
    velocity = new Vector(*other.velocity);
    if (other.pBest)
    {
        pBest = new Vector(*other.pBest);
    }
    else
    {
        pBest = NULL;
    }
};
Particle::~Particle()
{
    if (position != NULL)
        delete position;

    if (velocity != NULL)
        delete velocity;
        
    if (pBest != NULL)
        delete pBest;

    position = NULL;
    velocity = NULL;
    pBest = NULL;
};
/*
void Particle::updateParticle(const Particle &gBest)
{
 for (int i = 0; i < position->getSize(); ++i)
 {

     if (pBest == NULL)
     {
         velocity->getArray()[i] = w * velocity->getArray()[i] + c2 * (gBest.position->getArray()[i] - position->getArray()[i]);
     }
     else
     {
         velocity->getArray()[i] = w * (velocity->getArray()[i] + c1 * (pBest->getArray()[i] - position->getArray()[i]) + c2 * (gBest.position->getArray()[i] - position->getArray()[i]));
     }

     if (velocity->getArray()[i] > vMax)
     {
         velocity->getArray()[i] = vMax;
     }
     else if (velocity->getArray()[i] < -vMax)
     {
         velocity->getArray()[i] = -vMax;
     }

     position->getArray()[i] += velocity->getArray()[i];
 }
};*/
void Particle::updateParticle(const Particle &gBest)
{
    /*    for (int i = 0; i < position->getSize(); ++i)
      {
          double cc = 0.0;
          if (pBest != NULL)
          {
              cc = c1 * (pBest->getArray()[i] - position->getArray()[i]);
          }

          double sc = c2 * (gBest.position->getArray()[i] - position->getArray()[i]);

          velocity->getArray()[i] = w * velocity->getArray()[i] + cc + sc;

          if (velocity->getArray()[i] > vMax)
          {
              velocity->getArray()[i] = vMax;
          }
          else if (velocity->getArray()[i] < -vMax)
          {
              velocity->getArray()[i] = -vMax;
          }

          position->getArray()[i] += velocity->getArray()[i];
      }

  */

    int vmaxNeg = vMax * -1;

    for (int i = 0; i < position->getSize(); ++i)
    {
        double newVelocity = 0.0;
        //  float oldPosition = position->getArray()[i];

        if (pBest != NULL)
        {
            velocity->getArray()[i] = w * (velocity->getArray()[i]) + c2 * (gBest.getPosition().getArray()[i] - position->getArray()[i]) + c1 * (pBest->get(i) - position->getArray()[i]);
        }
        else
        {
            velocity->getArray()[i] = c2 * (gBest.getPosition().getArray()[i] - position->getArray()[i]) + w * (velocity->getArray()[i]);
        }

        if (velocity->getArray()[i] < vMax)
        {
            if (velocity->getArray()[i] < vmaxNeg)
            {
                velocity->getArray()[i] = vmaxNeg;
            }
        }
        else
        {
            velocity->getArray()[i] = vMax;
        }
        position->getArray()[i] = velocity->getArray()[i] + position->getArray()[i];

        /* std::cout << "Update for dimension " << i << ": "
                   << "Old Vel: " << oldVelocity << ", "
                   << "New Vel: " << velocity->getArray()[i] << ", "
                   << "Old Pos: " << oldPosition << ", "
                   << "New Pos: " << position->getArray()[i] << std::endl;*/
    }
}
const Vector &Particle::getPosition() const { return *position; };
const Vector &Particle::getVelocity() const { return *velocity; };
const Vector *Particle::getPBest() const { return pBest; };
void Particle::setVMax(double vMax)
{

    this->vMax = std::abs(vMax);
};
double Particle::evaluate(const Function &function)
{
    double cv = function.evaluate(*position);

    if (pBest == NULL)
    {

        pBest = new Vector(*position);
    }
    else
    {

        double pBestV = function.evaluate(*pBest);

        if (cv < pBestV)
        {
            delete pBest;
            pBest =new Vector(*position);
           
        }
    }
    return cv;
};
bool Particle::equal(const Particle &other) const
{

    if (position->getSize() != other.getPosition().getSize())
        return false;

    bool equalpart = true;

    for (int i = 0; i < position->getSize(); i++)
    {
        if (velocity->getArray()[i] != other.getVelocity().getArray()[i] && position->getArray()[i] != other.getPosition().getArray()[i])
            return false;
    }
    return true;
}
double Particle::getW() const { return w; };
double Particle::getC1() const { return c1; };
double Particle::getC2() const { return c2; };
double Particle::getVMax() const { return vMax; };