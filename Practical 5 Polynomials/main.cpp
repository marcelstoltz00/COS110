#include "Polynomial.h"

void testTerm()
{
    Term term1;
    std::cout << "Default Constructor: " << term1 << std::endl;

    char variables1[] = {'z', 'x'};
    int powers1[] = {2, 0};
    Term term2(5, 2, variables1, powers1);
    std::cout << "Parameterized Constructor: " << term2 << std::endl;

    char variables4[] = {'z', 'x'};
    int powers4[] = {0, 2};
    Term term9(5, 2, variables1, powers1);
    std::cout << "Parameterized Constructor: " << term2 << std::endl;

    Term term3(term2);
    std::cout << "Copy Constructor: " << term3 << std::endl;

    Term term4;
    term4 = term2;
    std::cout << "Assignment Operator: " << term4 << std::endl;

    char variables2[] = {'x', 'z'};
    int powers2[] = {1, 2};
    Term term5(3, 2, variables2, powers2);
    Term term6 = term2 * term5;
    std::cout << "Multiplication Operator: " << term6 << std::endl;

    term2 *= term5;
    std::cout << "Multiplication Assignment Operator: " << term2 << std::endl;

    std::cout << "Equality Operator: " << (term3 == term4) << std::endl;

    std::cout << "Less Than Operator: " << (term4 < term5) << std::endl;

    std::cout << "Greater Than Operator: " << (term5 > term2) << std::endl;

    std::cout << "Negation Operator: " << !term2 << std::endl;

    std::cout << "Subscript Operator: Power of first variable (x) in term2: " << term2[0] << std::endl;

    std::cout << "Output Operator: " << term2 << std::endl;
};
void testPolynomials()
{
    Polynomial poly1;
    std::cout << "Empty Polynomial: " << poly1 << std::endl;

    char vars1[] = {'x', 'y'};
    int pows1[] = {1, 2};
    Term term1(4, 2, vars1, pows1);

    char vars2[] = {'x', 'y'};
    int pows2[] = {1, 2};
    Term term2(3, 2, vars2, pows2);

    Term term3(5, 1, vars1, pows1);

    Polynomial poly2(term1);
    Polynomial poly3(term2);
    Polynomial poly19(poly2);

    std::cout << "Polynomial 2: " << poly2 << std::endl;
    std::cout << "Polynomial 3: " << poly3 << std::endl;

    Polynomial sumPoly = poly2 + poly3;
    Polynomial diffPoly = poly2 - poly3;
    Polynomial prodPoly = poly2 * poly3;

    std::cout << "Sum Polynomial: " << sumPoly << std::endl;
    std::cout << "Difference Polynomial: " << diffPoly << std::endl;
    std::cout << "Product Polynomial: " << prodPoly << std::endl;

    poly2 += poly3;
    std::cout << "Poly2 after += Poly3: " << poly2 << std::endl;

    poly2 -= poly3;
    std::cout << "Poly2 after -= Poly3: " << poly2 << std::endl;

    poly2 *= poly3;
    std::cout << "Poly2 after *= Poly3: " << poly2 << std::endl;
};
void newtests()
{

    Polynomial poly1;
    std::cout << "Empty Polynomial: " << poly1 << std::endl;

    char vars1[] = {'x', 'y'};
    int pows1[] = {1, 2};
    Term term1(4, 2, vars1, pows1);

    char vars2[] = {'x', 'y'};
    int pows2[] = {1, 2};
    Term term2(3, 2, vars2, pows2);

    Polynomial poly2(term1);
    Polynomial poly3(term2);

    std::cout << "Polynomial 2: " << poly2 << std::endl;
    std::cout << "Polynomial 3: " << poly3 << std::endl;

    Polynomial sumPoly = poly2 + poly3;
    Polynomial diffPoly = poly2 - poly3;
    Polynomial prodPoly = poly2 * poly3;

    std::cout << "Sum Polynomial: " << sumPoly << std::endl;
    std::cout << "Difference Polynomial: " << diffPoly << std::endl;
    std::cout << "Product Polynomial: " << prodPoly << std::endl;

    poly2 += poly3;
    std::cout << "Poly2 after += Poly3: " << poly2 << std::endl;

    poly2 -= poly3;
    std::cout << "Poly2 after -= Poly3: " << poly2 << std::endl;

    poly2 *= poly3;
    std::cout << "Poly2 after *= Poly3: " << poly2 << std::endl;

    char vars3[] = {'x'};
    int pows3[] = {1};
    Term zeroTerm(0, 1, vars3, pows3);

    Polynomial poly4(zeroTerm);
    std::cout << "Polynomial with zero coefficient: " << poly4 << std::endl;

    Polynomial poly5 = poly4 + poly2;
    std::cout << "Adding zero coefficient polynomial: " << poly5 << std::endl;

    Polynomial poly6 = poly4 - poly2;
    std::cout << "Subtracting zero coefficient polynomial: " << poly6 << std::endl;

    Polynomial poly7 = poly4 * poly2;
    std::cout << "Multiplying with zero coefficient polynomial: " << poly7 << std::endl;

    Term negTerm(-3, 1, vars3, pows3);
    Polynomial poly8(negTerm);
    std::cout << "Polynomial with negative coefficient: " << poly8 << std::endl;

    Polynomial poly9 = poly8 + poly2;
    std::cout << "Adding negative coefficient polynomial: " << poly9 << std::endl;

    Polynomial poly10 = poly8 - poly2;
    std::cout << "Subtracting negative coefficient polynomial: " << poly10 << std::endl;

    Polynomial poly11 = poly8 * poly2;
    std::cout << "Multiplying with negative coefficient polynomial: " << poly11 << std::endl;

    int pows4[] = {10};
    Term highPowerTerm(2, 1, vars3, pows4);
    Polynomial poly12(highPowerTerm);
    std::cout << "Polynomial with high power term: " << poly12 << std::endl;

    Polynomial poly13 = poly12 + poly2;
    std::cout << "Adding high power polynomial: " << poly13 << std::endl;

    Polynomial poly14 = poly12 - poly2;
    std::cout << "Subtracting high power polynomial: " << poly14 << std::endl;

    Polynomial poly15 = poly12 * poly2;
    std::cout << "Multiplying with high power polynomial: " << poly15 << std::endl;

    // Polynomial poly16;
    // for (int i = 1; i <= 100; i++)
    // {
    //     char var = 'x';
    //     int pows[] = {i};
    //     Term term(i, 1, &var, pows);
    //     poly16 += (term);
    // }

    // std::cout << "Polynomial with 100 terms: " << poly16 << std::endl;

    // Polynomial poly17 = poly16 + poly2;
    // std::cout << "Adding to large polynomial: " << poly17 << std::endl;

    // Polynomial poly18 = poly16 - poly2;
    // std::cout << "Subtracting from large polynomial: " << poly18 << std::endl;

    // Polynomial poly19 = poly16 * poly2;
    // std::cout << "Multiplying large polynomial: " << poly19 << std::endl;

    char vars5[] = {'y', 'x'};
    int pows5[] = {2, 1};
    Term term4(4, 2, vars5, pows5);
    Polynomial poly20(term4);
    std::cout << "" << poly20 << std::endl;
    Term termnew(4, 2, vars1, pows1);
    Polynomial polyuse(termnew);
    std::cout << "use this:" << polyuse << std::endl;

    std::cout << "Polynomial with terms in different order: " << poly20 << std::endl;

    Polynomial poly21 = polyuse + poly20;
    std::cout << "Adding polynomials with same terms but different order: " << poly21 << std::endl;

    Polynomial poly22 = polyuse - poly20;
    std::cout << "Subtracting polynomials with same terms but different order: " << poly22 << std::endl;

    Polynomial poly23 = polyuse * poly20;
    std::cout << "Multiplying polynomials with same terms but different order: " << poly23 << std::endl;

    // Testing polynomials with mixed positive, negative, and zero coefficients
    char vars6[] = {'z'};
    int pows6[] = {5};
    Term mixedTerm1(10, 1, vars6, pows6);
    Term mixedTerm2(-10, 1, vars6, pows6);
    Term mixedTerm3(0, 1, vars6, pows6);

    Polynomial poly24;
    poly24 += mixedTerm1;
    poly24 += mixedTerm2;
    poly24 += mixedTerm3;

    std::cout << "Complex polynomial: " << poly24 << std::endl;

    Polynomial poly25 = poly24 + poly2;
}

bool testOutput(const std::string &testName, const Polynomial &poly, const std::string &expected)
{
    std::ostringstream os;
    os << poly;
    std::string result = os.str();

    if (result == expected)
    {
        std::cout << testName << ": PASS" << std::endl;
        return true;
    }
    else
    {
        std::cout << testName << ": FAIL" << std::endl;
        std::cout << "Expected: " << expected << std::endl;
        std::cout << "Got: " << result << std::endl;
        return false;
    }
}

// int main() {
//     bool allTestsPassed = true;

//     // Test Case 1: Basic Polynomial Operations
//     Polynomial poly1;
//     allTestsPassed &= testOutput("Empty Polynomial", poly1, "+0");

//     char vars1[] = {'x', 'y'};
//     int pows1[] = {1, 2};
//     Term term1(4, 2, vars1, pows1);

//     char vars2[] = {'x', 'y'};
//     int pows2[] = {1, 2};
//     Term term2(3, 2, vars2, pows2);

//     Polynomial poly2(term1);
//     Polynomial poly3(term2);

//     allTestsPassed &= testOutput("Polynomial 2", poly2, "+4*x^1*y^2");
//     allTestsPassed &= testOutput("Polynomial 3", poly3, "+3*x^1*y^2");

//     Polynomial sumPoly = poly2 + poly3;
//     allTestsPassed &= testOutput("Sum Polynomial", sumPoly, "+7*x^1*y^2");

//     Polynomial diffPoly = poly2 - poly3;
//     allTestsPassed &= testOutput("Difference Polynomial", diffPoly, "+0");

//     Polynomial prodPoly = poly2 * poly3;
//     allTestsPassed &= testOutput("Product Polynomial", prodPoly, "+12*x^2*y^4");

//     poly2 += poly3;
//     allTestsPassed &= testOutput("Poly2 after += Poly3", poly2, "+7*x^1*y^2");

//     poly2 -= poly3;
//     allTestsPassed &= testOutput("Poly2 after -= Poly3", poly2, "+4*x^1*y^2");

//     poly2 *= poly3;
//     allTestsPassed &= testOutput("Poly2 after *= Poly3", poly2, "+12*x^2*y^4");

//     char vars3[] = {'x'};
//     int pows3[] = {1};
//     Term zeroTerm(0, 1, vars3, pows3);

//     Polynomial poly4(zeroTerm);
//     allTestsPassed &= testOutput("Polynomial with zero coefficient", poly4, "+0");

//     Polynomial poly5 = poly4 + poly2;
//     allTestsPassed &= testOutput("Adding zero coefficient polynomial", poly5, "+12*x^2*y^4");

//     Polynomial poly6 = poly4 - poly2;
//     allTestsPassed &= testOutput("Subtracting zero coefficient polynomial", poly6, "-12*x^2*y^4");

//     Polynomial poly7 = poly4 * poly2;
//     allTestsPassed &= testOutput("Multiplying with zero coefficient polynomial", poly7, "+0");

//     Term negTerm(-3, 1, vars3, pows3);
//     Polynomial poly8(negTerm);
//     allTestsPassed &= testOutput("Polynomial with negative coefficient", poly8, "-3*x^1");

//     Polynomial poly9 = poly8 + poly2;
//     allTestsPassed &= testOutput("Adding negative coefficient polynomial", poly9, "+9*x^2*y^4-3*x^1");

//     Polynomial poly10 = poly8 - poly2;
//     allTestsPassed &= testOutput("Subtracting negative coefficient polynomial", poly10, "-15*x^2*y^4+3*x^1");

//     Polynomial poly11 = poly8 * poly2;
//     allTestsPassed &= testOutput("Multiplying with negative coefficient polynomial", poly11, "-36*x^3*y^6");

//     int pows4[] = {10};
//     Term highPowerTerm(2, 1, vars3, pows4);
//     Polynomial poly12(highPowerTerm);
//     allTestsPassed &= testOutput("Polynomial with high power term", poly12, "+2*x^10");

//     Polynomial poly13 = poly12 + poly2;
//     allTestsPassed &= testOutput("Adding high power polynomial", poly13, "+2*x^10+12*x^2*y^4");

//     Polynomial poly14 = poly12 - poly2;
//     allTestsPassed &= testOutput("Subtracting high power polynomial", poly14, "+2*x^10-12*x^2*y^4");

//     Polynomial poly15 = poly12 * poly2;
//     allTestsPassed &= testOutput("Multiplying with high power polynomial", poly15, "24*x^12*y^4");

//     Polynomial poly16;
//     for (int i = 1; i <= 100; i++) {
//         char var = 'x';
//         int pows[] = {i};
//         Term term(i, 1, &var, pows);
//         poly16+=term;
//     }

//     char vars5[] = {'y', 'x'};
//     int pows5[] = {2, 1};
//     Term term4(4, 2, vars5, pows5);
//     Polynomial poly20(term4);

//     allTestsPassed &= testOutput("Polynomial with terms in different order", poly20, "+4*y^2*x^1");

//     Polynomial poly21 = poly2 + poly20;
//     allTestsPassed &= testOutput("Adding polynomials with same terms but different order", poly21, "+8*x^1*y^2");

//     Polynomial poly22 = poly2 - poly20;
//     allTestsPassed &= testOutput("Subtracting polynomials with same terms but different order", poly22, "+0");

//     Polynomial poly23 = poly2 * poly20;
//     allTestsPassed &= testOutput("Multiplying polynomials with same terms but different order", poly23, "+16*x^2*y^4");

//     char vars6[] = {'z'};
//     int pows6[] = {5};
//     Term mixedTerm1(10, 1, vars6, pows6);
//     Term mixedTerm2(-10, 1, vars6, pows6);
//     Term mixedTerm3(0, 1, vars6, pows6);

//     Polynomial poly24;
//     poly24+=mixedTerm1;
//     poly24+=mixedTerm2;
//     poly24+=mixedTerm3;

//     allTestsPassed &= testOutput("Complex polynomial", poly24, "+0");

//     Polynomial poly25 = poly24 + poly2;
//     allTestsPassed &= testOutput("Adding complex polynomial", poly25, "+4*x^1*y^2");

//     if (allTestsPassed) {
//         std::cout << "All tests passed!" << std::endl;
//     } else {
//         std::cout << "Some tests failed. Please review the output above." << std::endl;
//     }

//     return 0;
// }
void errors()
{

    char vars5[] = {'x', 'y'};
    int pows5[] = {2, 1};
    Term term4(3, 2, vars5, pows5);
    Polynomial poly20(term4);

    char vars2[] = {'x', 'y'};
    int pows2[] = {2, 1};
    Term term2(3, 2, vars2, pows2);
    Polynomial poly21(term2);

    Polynomial plont = poly20 - poly21;
    std::cout << plont << std::endl;
}
int main()
{
     errors();
    testPolynomials();
    testTerm();
    return 0;
    
}