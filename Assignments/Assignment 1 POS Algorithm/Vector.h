#ifndef VECTOR_H
#define VECTOR_H

#include <sstream>
#include <string>
#include <iostream>

class Vector{
    private:
        double* array;//This member variable is a dynamic 1D array that contains the components that are contained in the vector.

        int size;//This member variable contains the dimensionality or size of the vector (which will be represented as an array in this assignment

    public:
        Vector(std::string array);
        Vector(const Vector& other);
        Vector(const double* array, int size);
        ~Vector();
        double* getArray() const;
        int getSize() const;
        static double fromStringToDouble(std::string v);
        static std::string fromDoubleToString(double v);
        const std::string toString() const;
        double get(int index) const;
        bool equal(const Vector& other) const;
};

#endif /*VECTOR_H*/