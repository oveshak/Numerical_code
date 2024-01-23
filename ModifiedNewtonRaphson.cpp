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

// Second derivative of the function
double secondDerivative(double x)
{
    return 2; // Example second derivative: 2
}

// Modified Newton-Raphson Method
double modifiedNewtonRaphson(double initialGuess, double tolerance)
{
    double x = initialGuess;
    double xNext = x;

    while (true)
    {
        double f = function(x);
        double fPrime = derivative(x);
        double fDoublePrime = secondDerivative(x);

        if (fDoublePrime == 0.0)
        {
            cout << "Modified Newton-Raphson method failed: Division by zero." << endl;
            return NAN; // Return NaN (Not a Number) to indicate failure
        }

        xNext = x - (f * fPrime) / (fPrime * fPrime - f * fDoublePrime);

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

    double root = modifiedNewtonRaphson(initialGuess, tolerance);

    cout << "Approximate root: " << root << endl;

    return 0;
}
