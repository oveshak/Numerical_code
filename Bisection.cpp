#include <iostream>
#include <cmath>

using namespace std;

// Function for which we want to find the root
double function(double x)
{
    return x * x - 4; // Example function: x^2 - 4
}

// Bisection Method
double bisection(double a, double b, double tolerance)
{
    if (function(a) * function(b) >= 0)
    {
        cout << "Bisection method cannot guarantee convergence with the given interval." << endl;
        return NAN; // Return NaN (Not a Number) to indicate failure
    }

    double c = a;
    while ((b - a) >= tolerance)
    {
        c = (a + b) / 2;

        if (function(c) == 0.0)
            break;

        if (function(c) * function(a) < 0)
            b = c;
        else
            a = c;
    }

    return c;
}

int main()
{
    double a = 0.0;            // Lower limit of the interval
    double b = 2.0;            // Upper limit of the interval
    double tolerance = 0.0001; // Tolerance or desired accuracy

    double root = bisection(a, b, tolerance);

    if (!isnan(root))
        cout << "Approximate root: " << root << endl;

    return 0;
}
