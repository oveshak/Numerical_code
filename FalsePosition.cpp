#include <iostream>
#include <cmath>

using namespace std;

// Function for which we want to find the root
double function(double x)
{
    return x * x - 4; // Example function: x^2 - 4
}

// False Position Method
double falsePosition(double a, double b, double tolerance)
{
    if (function(a) * function(b) >= 0)
    {
        cout << "False Position method cannot guarantee convergence with the given interval." << endl;
        return NAN; // Return NaN (Not a Number) to indicate failure
    }

    double c = a;
    while (fabs(b - a) >= tolerance)
    {
        c = (a * function(b) - b * function(a)) / (function(b) - function(a));

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

    double root = falsePosition(a, b, tolerance);

    if (!isnan(root))
        cout << "Approximate root: " << root << endl;

    return 0;
}
