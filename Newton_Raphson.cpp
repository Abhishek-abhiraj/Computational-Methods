#include <iostream>
#include <cmath>
using namespace std;

// Function f(x) for which we want the root
double f(double x) {
    return x*x*x - x - 2; // Example: f(x) = x^3 - x - 2
}

// Derivative f'(x)
double df(double x) {
    return 3*x*x - 1; // derivative: 3x^2 - 1
}

int main() {
    double x0, x1;
    double tolerance = 0.0001;
    int maxIter = 100, iter = 0;

    // Input initial guess
    cout << "Enter initial guess: ";
    cin >> x0;

    cout << "Iteration\t x\t\t f(x)\n";

    do {
        x1 = x0 - f(x0) / df(x0); // Newton-Raphson formula
        cout << ++iter << "\t\t " << x1 << "\t " << f(x1) << endl;

        if (fabs(x1 - x0) < tolerance) {
            break; // Stop if within tolerance
        }

        x0 = x1;

    } while (iter < maxIter);

    cout << "\nApproximate root is: " << x1 << endl;
    return 0;
}
