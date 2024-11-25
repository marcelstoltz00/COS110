#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>
#include <cmath>

#include "Vector.h"

class Function{
    public:
        double evaluate(const Vector& inputs) const;
};

#endif /*FUNCTION_H*/