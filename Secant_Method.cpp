#include <iostream>
#include <cmath>
using namespace std;

// Function f(x)
double f(double x) {
    return x*x*x - x - 2; // Example: f(x) = x^3 - x - 2
}

int main() {
    double x0, x1, x2;
    double tolerance = 0.0001;
    int maxIter = 100, iter = 0;

    // Input two initial guesses
    cout << "Enter first guess x0: ";
    cin >> x0;
    cout << "Enter second guess x1: ";
    cin >> x1;

    cout << "Iteration\t x\t\t f(x)\n";

    do {
        // Apply secant formula
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        cout << ++iter << "\t\t " << x2 << "\t " << f(x2) << endl;

        if (fabs(x2 - x1) < tolerance) {
            break; // Convergence
        }

        x0 = x1;
        x1 = x2;

    } while (iter < maxIter);

    cout << "\nApproximate root is: " << x2 << endl;
    return 0;
}
