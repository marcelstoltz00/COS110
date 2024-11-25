#include "Vector.h"
Vector::Vector(std::string array) // error here not fixed
{
    array = array.substr(1, array.length() - 2); // removes the brackets

    int numComp = 1; // number of components in array
    for (int i = 0; i < array.length(); i++)
    {

        if (array[i] == ',')
            numComp++;
    }

    size = numComp;
    this->array = new double[size]; // allocate enough space

    // now to fill the vector
    // string to double

    int indexofstring = 1;
    int indexofcomparray = 0;
    double value;
    std::string newC;
    for (int i = 0; i < size; i++)
    {
        /// dissect string
        // [0.1, 33.4, 4.132]

        newC = array.substr(0, array.find_first_of(',', 1));
        // array = array.substr(array.find_first_of(',', 1) + 2, array.length() - array.find_first_of(',', 1));
        array = array.substr(array.find_first_of(',', 1) + 1);

        std::stringstream oss(newC);
        oss >> newC;
        value = fromStringToDouble(newC);
        // std::cout<<"this is the value"<<value<<std::endl;
        this->array[i] = value;
    }
};
Vector::Vector(const Vector &other) // error here not fixed
{

    // create a deep copy of the vector

    size = other.size;
    array = new double[size];
    for (int i = 0; i < size; i++)
    {

        array[i] = other.array[i];
    }
};
Vector::Vector(const double *array, int size)
{
    if (size <= 0 || array == NULL)
    {
        this->array = NULL;
        this->size = 0;
    }
    else
    {
        this->size = size;
        this->array = new double[size];

        for (int i = 0; i < size; i++)
        {
            this->array[i] = array[i];
        }
    }
};
Vector::~Vector()
{
    if (array == NULL)
    {
    }
    else
    {
        delete[] array;
        array = NULL;
    }
};
double *Vector::getArray() const { return array; };
int Vector::getSize() const { return size; };
double Vector::fromStringToDouble(std::string v)
{

    std::stringstream oss(v);
    double returnval = 0.0;
    oss >> returnval;

    return returnval;
};
std::string Vector::fromDoubleToString(double v)
{

    std::stringstream oss;
    oss << v;

    std::string returnval = oss.str();

    if (returnval.find('.') == std::string::npos)
    {

        returnval += ".0";
    }

    return returnval;
};
const std::string Vector::toString() const
{

    std::stringstream newstr;
    newstr << '[';
    for (int i = 0; i < size; i++)
    {
        newstr << fromDoubleToString(array[i]);
        if (i < size - 1)
            newstr << ", ";
    }
    newstr << ']';
    return newstr.str();
};
double Vector::get(int index) const
{
    if (index < 0 || index >= size)
        return 0;
    return array[index];
};
bool Vector::equal(const Vector &other) const
{
    if (this->size != size)
        return false;

    bool equalvec = true;

    for (int i = 0; i < size; i++)
    {

        if (this->array[i] != other.array[i])
        {
            return false;
        }
    }

    return equalvec;
};