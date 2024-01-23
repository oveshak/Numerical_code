#include <iostream>
#include <cmath>

using namespace std;

// Function for which we want to find the root
double function(double x)
{
    return x * x - 4; // Example function: x^2 - 4
}

// Secant Method
double secant(double x0, double x1, double tolerance)
{
    double x2 = 0.0;

    while (fabs(x1 - x0) >= tolerance)
    {
        x2 = x1 - (function(x1) * (x1 - x0)) / (function(x1) - function(x0));

        x0 = x1;
        x1 = x2;
    }

    return x2;
}

int main()
{
    double x0 = 1.0;           // Initial value x0
    double x1 = 2.0;           // Initial value x1
    double tolerance = 0.0001; // Tolerance or desired accuracy

    double root = secant(x0, x1, tolerance);

    cout << "Approximate root: " << root << endl;

    return 0;
}
