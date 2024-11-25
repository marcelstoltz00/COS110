#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <sstream>
#include <string>

#include "Term.h"

using namespace std;

class Polynomial
{
private:
  int numTerms;
  Term **terms;
  int termIndex(Term term) const;
  void addOrRemoveTerm(Term term);

public:
  Polynomial();
  Polynomial(Term **terms, int numTerms);
  Polynomial(const Polynomial &other);
  Polynomial(Term term);
  ~Polynomial();
  Polynomial &operator=(const Polynomial &other);
  friend ostream &operator<<(ostream &os, const Polynomial &polynomial);
  Term *operator[](int index) const;
  Polynomial operator+(const Polynomial &other)const;
  Polynomial operator-(const Polynomial &other)const;
  Polynomial operator*(const Polynomial &other)const;

  Polynomial &operator+=(const Polynomial &other);
  Polynomial &operator-=(const Polynomial &other);
  Polynomial &operator*=(const Polynomial &other);
};
#endif