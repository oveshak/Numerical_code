#include <iostream>
#include <cmath>

using namespace std;

// Function for which we want to find the root
double function(double x)
{
    return x * x - 4; // Example function: x^2 - 4
}

// Derivative of the function
double derivative(double x)
{
    return 2 * x; // Example derivative: 2x
}

// Newton-Raphson Method
double newtonRaphson(double initialGuess, double tolerance)
{
    double x = initialGuess;
    double xNext = x;

    while (true)
    {
        double f = function(x);
        double fPrime = derivative(x);

        if (fabs(fPrime) < tolerance)
        {
            cout << "Newton-Raphson method failed: Division by zero." << endl;
            return NAN; // Return NaN (Not a Number) to indicate failure
        }

        xNext = x - f / fPrime;

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

    double root = newtonRaphson(initialGuess, tolerance);

    if (!isnan(root))
        cout << "Approximate root: " << root << endl;

    return 0;
}
