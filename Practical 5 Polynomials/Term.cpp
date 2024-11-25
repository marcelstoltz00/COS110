#include "Term.h"
Term::Term()
{
    coefficient = 1;
    numVariables = 0;
    variables = new char[0];
    powers = new int[0];
};
Term::Term(const Term &other)
{
    this->coefficient = other.coefficient;

    if (other.coefficient == 0)
    {
        this->numVariables = 0;
        this->variables = new char[0];
        this->powers = new int[0];
        return;
    }

    this->numVariables = other.numVariables;

    this->variables = new char[this->numVariables];
    this->powers = new int[this->numVariables];

    for (int i = 0; i < this->numVariables; i++)
    {
        this->variables[i] = other.variables[i];
        this->powers[i] = other.powers[i];
    }
    // not fixed
};
Term::Term(int coefficient, int numVariables, char *variables, int *powers)
{

    this->coefficient = coefficient;
    if (coefficient == 0)
    {
        this->numVariables = 0;
        this->variables = new char[0];
        this->powers = new int[0];
        return;
    }
    this->numVariables = 0;
    this->variables = new char[this->numVariables];
    this->powers = new int[this->numVariables];

    for (int i = 0; i < numVariables; i++)
    {

        if (powers[i] != 0)
        {
            this->addVariable(variables[i], powers[i]);
        }
    }
};
Term::~Term()
{
    if (variables != NULL)
        delete[] variables;
    if (powers != NULL)
        delete[] powers;
};
Term &Term::operator=(const Term &other)
{
    if (this == &other)
        return *this;
    delete[] this->powers;
    delete[] this->variables;

    this->coefficient = other.coefficient;

    if (other.coefficient == 0)
    {
        this->numVariables = 0;
        this->variables = new char[0];
        this->powers = new int[0];
        return *this;
    }
    this->numVariables = other.numVariables;
    this->variables = new char[this->numVariables];
    this->powers = new int[this->numVariables];

    for (int i = 0; i < this->numVariables; i++)
    {
        this->variables[i] = other.variables[i];
        this->powers[i] = other.powers[i];
    }

    return *this;
};
ostream &operator<<(ostream &os, const Term &term)
{
    if (term.coefficient == 0)
    {
        os << "0";
        return os;
    }

    if (term.coefficient > 0)
        os << "+";

    os << term.coefficient;

    for (int i = 0; i < term.numVariables; i++)
    {

        os << "*" << term.variables[i] << "^" << term.powers[i];
    }

    return os;
};
Term Term::operator*(const Term &other) const
{
    Term newTerm;
    newTerm.coefficient = this->coefficient * other.coefficient;

    if (newTerm.coefficient == 0)
        return newTerm;

    for (int i = 0; i < this->numVariables; i++)
    {
        newTerm.addVariable(this->variables[i], this->powers[i]);
    }

    for (int j = 0; j < other.numVariables; j++)
    {
        newTerm.addVariable(other.variables[j], other.powers[j]);
    }

    for (int k = 0; k < newTerm.numVariables; k++)
    {
        if (newTerm.powers[k] == 0)
        {
            newTerm.removeVariable(newTerm.variables[k]);
            k--;
        }
    }

    return newTerm;
};
Term &Term::operator*=(const Term &other)
{
    Term result = *this * other;
    *this = result;
    return *this;
};
bool Term::operator==(const Term &other) const
{

    if (this->numVariables != other.numVariables)
        return false;
    for (int i = 0; i < numVariables; i++)
    {
        if (variables[i] != other.variables[i] || powers[i] != other.powers[i])
            return false;
    }
    return true;
};
bool Term::operator<(const Term &other) const
{

    if (*this == other)
        return false;
    if (this->numVariables == 0)
        return false;

    if (other.numVariables == 0)
        return true;

    int smallest = (numVariables < other.numVariables) ? numVariables : other.numVariables;
    for (int i = 0; i < smallest; i++)
    {
        if (variables[i] == other.variables[i])
        {
            if (powers[i] != other.powers[i])
            {
                return powers[i] > other.powers[i];
            }
        }
        else
        {
            return variables[i] < other.variables[i];
        }
    }

    if (numVariables < other.numVariables)
        return true;
    else
        return false;
};
bool Term::operator>(const Term &other) const
{
    return !(*this < other) && !(*this == other);
};
int &Term::operator[](int index)
{

    if (index >= 0 && index < numVariables)
        return powers[index];
    else
        return coefficient;
};
Term Term::operator!() const
{
    Term newest = *this;
    newest.coefficient = -coefficient;
    return newest;
};
int Term::getVarIndex(char var) const
{

    for (int i = 0; i < numVariables; i++)
    {
        if (variables[i] == var)
        {
            return i;
        }
    }

    return -1;
};
void Term::addVariable(char var, int pow)
{
    if (coefficient == 0 || pow == 0)
        return;

    int index = getVarIndex(var);
    if (index != -1)
    {
        powers[index] += pow;

        if (powers[index] == 0)
        {
            removeVariable(var);
        }
        return;
    }

    char *newVar = new char[numVariables + 1];
    int *newPowers = new int[numVariables + 1];

    int i = 0, j = 0;
    bool inserted = false;

    while (i < numVariables)
    {
        if (!inserted && var < variables[i])
        {
            newVar[j] = var;
            newPowers[j] = pow;
            inserted = true;
            j++;
        }

        newVar[j] = variables[i];
        newPowers[j] = powers[i];
        i++;
        j++;
    }

    if (!inserted)
    {
        newVar[j] = var;
        newPowers[j] = pow;
    }

    delete[] variables;
    delete[] powers;
    variables = newVar;
    powers = newPowers;
    numVariables++;
};
void Term::removeVariable(char var){

    bool found = false;

    if (coefficient == 0)
        return;
    int retrn = getVarIndex(var);
    if (retrn == -1)
    {

        return;
    }
    {
        char *newVar = new char[numVariables - 1];
        int *newPowers = new int[numVariables - 1];

        int newval = 0;
        bool inserted = false;

        for (int i = 0; i < numVariables; i++)
        {

            if (variables[i] != var)
            {
                newVar[newval] = variables[i];
                newPowers[newval] = powers[i];
                newval++;
            }
        }

        delete[] variables;
        delete[] powers;
        powers = newPowers;
        variables = newVar;
        numVariables--;
    }
};