#include "Function.h"

double Function::evaluate(const Vector& inputs) const
{
    double x = inputs.get(0);
    double y = inputs.get(1);
    return 0.1*pow(x,2) + 3*pow(y,2);//may change 
}