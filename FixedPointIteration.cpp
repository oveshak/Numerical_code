#include <iostream>
#include <cmath>

using namespace std;

// Function for which we want to find the root
double function(double x)
{
    return x * x - 4; // Example function: x^2 - 4
}

// Function derived from f(x) for fixed-point iteration
double g(double x)
{
    return sqrt(4.0 / x); // Example function: g(x) = sqrt(4 / x)
}

// Fixed-Point Iteration Method
double fixedPointIteration(double initialGuess, double tolerance)
{
    double x = initialGuess;
    double xNext = 0.0;

    while (true)
    {
        xNext = g(x);

        if (fabs(xNext - x) < tolerance)
            break;

        x = xNext;
    }

    return xNext;
}

int main()
{
    double initialGuess = 2.0; // Initial guess for the root
    double tolerance = 0.0001; // Tolerance or desired accuracy

    double root = fixedPointIteration(initialGuess, tolerance);

    cout << "Approximate root: " << root << endl;

    return 0;
}
