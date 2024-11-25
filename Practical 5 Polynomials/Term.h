#ifndef TERM_H
#define TERM_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Term
{
private:
    int coefficient;
    int numVariables;
    char *variables;
    int *powers;
    void addVariable(char var, int pow);
    void removeVariable(char var);
     int getVarIndex(char var)const;

public:
    Term();
    Term(const Term &other);
    Term(int coefficient, int numVariables, char *variables, int *powers);
    ~Term();
    Term &operator=(const Term &other);
    friend ostream &operator<<(ostream &os, const Term &term);
    Term operator*(const Term &other) const;
    Term &operator*=(const Term &other);
    bool operator==(const Term &other) const;
    bool operator<(const Term &other) const;
    bool operator>(const Term &other) const;
    int &operator[](int index) ;
    Term operator!()const;
};

#endif