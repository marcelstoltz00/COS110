#include "Polynomial.h"
Polynomial::Polynomial()
{

    numTerms = 0;
    terms = NULL;
};
Polynomial::Polynomial(Term **terms, int numTerms)
{
    this->terms = NULL;
    this->numTerms = 0;

    if (terms == NULL || numTerms <= 0)
        return;

    for (int i = 0; i < numTerms; i++)
    {
        (this->addOrRemoveTerm(*terms[i]));
    }
};
Polynomial::Polynomial(const Polynomial &other)
{
    numTerms = 0;
    terms = NULL;
    for (int i = 0; i < other.numTerms; i++)
    {
        this->addOrRemoveTerm(*other.terms[i]);
    }
};
Polynomial::Polynomial(Term term)
{
    numTerms = 0;
    terms = NULL;
    addOrRemoveTerm(term);
};
Polynomial::~Polynomial()
{
    for (int i = 0; i < numTerms; i++)
    {
        if (terms[i] != NULL)
            delete terms[i];
    }
    if (terms != NULL)
        delete[] terms;
};
Polynomial &Polynomial::operator=(const Polynomial &other)
{
    if (this == &other)
    {
        return *this;
    }

    for (int i = 0; i < numTerms; i++)
    {
        delete terms[i];
    }
    delete[] terms;

    numTerms = 0;
    terms = NULL;
    for (int i = 0; i < other.numTerms; i++)
    {
        this->addOrRemoveTerm(*other.terms[i]);
    }

    return *this;
};
ostream &operator<<(ostream &os, const Polynomial &polynomial)
{

    if (polynomial.numTerms == 0)
        return os << "+0";

    for (int i = 0; i < polynomial.numTerms; i++)
    { 
        if (polynomial.terms[i]==0){}
        else
        os << *polynomial.terms[i];
    }
    return os;
};
Term *Polynomial::operator[](int index) const
{
    if (index >= 0 && index < numTerms)
        return terms[index];
    else
        return NULL;
};
Polynomial Polynomial::operator+(const Polynomial &other) const
{
    Polynomial copynew(*this);

    for (int i = 0; i < other.numTerms; i++)
    {
        copynew.addOrRemoveTerm(*other.terms[i]);
    }
    return copynew;
};
Polynomial Polynomial::operator-(const Polynomial &other) const
{
    Polynomial copynew(*this);
    for (int i = 0; i < other.numTerms; i++)
    {

        Term negation = (*other.terms[i]);

        copynew.addOrRemoveTerm(!negation);
    }
    return copynew;
};
Polynomial Polynomial::operator*(const Polynomial &other) const
{
    Polynomial copynew;

    for (int i = 0; i < numTerms; i++)
    {
        for (int j = 0; j < other.numTerms; j++)
        {
            Term pt = (*terms[i]) * (*other.terms[j]);
            copynew.addOrRemoveTerm(pt);
        }
    }

    return copynew;
};
Polynomial &Polynomial::operator+=(const Polynomial &other)
{

    *this = *this + other;

    return *this;
};
Polynomial &Polynomial::operator-=(const Polynomial &other)
{

    *this = *this - other;

    return *this;
};
Polynomial &Polynomial::operator*=(const Polynomial &other)
{

    *this = *this * other;

    return *this;
};
int Polynomial::termIndex(Term term) const
{

    for (int i = 0; i < numTerms; i++)
    {
        if (*terms[i] == term)
        {
            return i;
        }
    }
    return -1;
};
void Polynomial::addOrRemoveTerm(Term term)
{

    if (term[-1] == 0)
        return;
    int ix = termIndex(term);
    if (ix != -1)
    {
       (*terms[ix])[-1] = (*terms[ix])[-1] + term[-1];


        if ((*terms[ix])[-1] == 0)
        {
            Term **newterms = new Term *[numTerms - 1];
            for (int i = 0, j = 0; i < numTerms; i++)
            {
                if (i == ix)
                {
                    delete terms[i];
                }
                else
                {
                    newterms[j++] = terms[i];
                }
            }
            delete[] terms;
            terms = newterms;
            numTerms--;
        }
    }
    else
    {
        Term **newterms = new Term *[numTerms + 1];
        for (int i = 0; i < numTerms; i++)
        {
            newterms[i] = terms[i];
        }
        newterms[numTerms] = new Term(term);
        delete[] terms;
    
        terms = newterms;
        numTerms++;

        for (int i = 0; i < numTerms - 1; i++)
        {
            for (int j = i + 1; j < numTerms; j++)
            {
                if (*terms[i] > *terms[j])
                {
                    Term *t = terms[i];
                    terms[i] = terms[j];
                    terms[j] = t;
                }
            }
        }
    }
};