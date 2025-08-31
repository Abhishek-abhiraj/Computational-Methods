#include <iostream>
#include <cmath>
using namespace std;

// Define the function for which root is to be found
double f(double x) {
    return x*x*x - x - 2; // Example: f(x) = x^3 - x - 2
}

int main() {
    double a, b, c;
    int iterations = 0;
    double tolerance = 0.0001;

    // Input interval [a, b]
    cout << "Enter interval [a, b]: ";
    cin >> a >> b;

    // Check validity
    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval! f(a) and f(b) must have opposite signs." << endl;
        return 1;
    }

    cout << "Iteration\t a\t\t b\t\t c\t\t f(c)\n";

    // Iterative process
    do {
        c = (a + b) / 2.0; // Midpoint
        cout << ++iterations << "\t\t " << a << "\t " << b << "\t " << c << "\t " << f(c) << endl;

        // Check root
        if (f(c) == 0.0)
            break;

        // Decide new interval
        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;

    } while ((b - a) >= tolerance);

    cout << "\nApproximate root is: " << c << endl;
    return 0;
}
