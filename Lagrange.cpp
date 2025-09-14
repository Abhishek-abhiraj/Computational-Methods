#include <iostream>
using namespace std;

// Function to perform Lagrange Interpolation
double lagrangeInterpolation(double x[], double y[], int n, double X) {
    double result = 0.0;

    for (int i = 0; i < n; i++) {
        double term = y[i];

        for (int j = 0; j < n; j++) {
            if (j != i)
                term *= (X - x[j]) / (x[i] - x[j]);
        }

        result += term;
    }

    return result;
}

int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    double x[n], y[n];

    cout << "Enter data points (x and y):\n";
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "]: ";
        cin >> x[i];
        cout << "y[" << i << "]: ";
        cin >> y[i];
    }

    double X;
    cout << "Enter value of X to interpolate: ";
    cin >> X;

    double interpolatedValue = lagrangeInterpolation(x, y, n, X);
    cout << "\nInterpolated value at X = " << X << " is: " << interpolatedValue << endl;

    return 0;
}
