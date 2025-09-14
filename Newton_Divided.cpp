#include <iostream>
#include <vector>
using namespace std;

// Function to calculate divided difference table
void dividedDifferenceTable(const vector<double>& x, const vector<double>& y, vector<vector<double>>& table, int n) {
    for (int i = 0; i < n; i++)
        table[i][0] = y[i];

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            table[i][j] = (table[i + 1][j - 1] - table[i][j - 1]) / (x[i + j] - x[i]);
        }
    }
}

// Function to evaluate Newton's Interpolation Polynomial at given value
double newtonInterpolation(const vector<double>& x, vector<vector<double>>& table, int n, double value) {
    double result = table[0][0];
    double term;

    for (int i = 1; i < n; i++) {
        term = table[0][i];
        for (int j = 0; j < i; j++)
            term *= (value - x[j]);

        result += term;
    }
    return result;
}

int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    vector<double> x(n), y(n);
    cout << "Enter x values:\n";
    for (int i = 0; i < n; i++)
        cin >> x[i];

    cout << "Enter y values:\n";
    for (int i = 0; i < n; i++)
        cin >> y[i];

    vector<vector<double>> table(n, vector<double>(n));
    dividedDifferenceTable(x, y, table, n);

    double value;
    cout << "Enter the value to interpolate: ";
    cin >> value;

    double result = newtonInterpolation(x, table, n, value);

    cout << "Interpolated value at " << value << " is: " << result << endl;

    return 0;
}
