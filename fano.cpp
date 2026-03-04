#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

string toBaseD(double value, int length, int D) {
    string code = "";
    const double EPS = 1e-12;

    for (int i = 0; i < length; i++) {
        value *= D;
        int digit = (int)(value + EPS);
        code += to_string(digit);
        value -= digit;
    }
    return code;
}

int main() {
    int D, n;

    cout << "Enter  D: ";
    cin >> D;

    cout << "Enter number of symbols: ";
    cin >> n;

    vector<double> prob(n);

    cout << "Enter probabilities:\n";
    for (int i = 0; i < n; i++)
        cin >> prob[i];

    sort(prob.begin(), prob.end(), greater<double>());

    vector<double> cumulative(n);
    double sum = 0.0;

    for (int i = 0; i < n; i++) {
        cumulative[i] = sum;
        sum += prob[i];
    }

    double avgLength = 0.0;

    // cout << "\nProbability  Code  Length\n";

    for (int i = 0; i < n; i++) {
        int length = ceil(-log(prob[i]) / log((double)D));
        string code = toBaseD(cumulative[i], length, D);

        avgLength += prob[i] * length;

        cout << prob[i] << " " 
             << code << "\n";
             
    }

    cout << "\nAverage Length = " << avgLength << endl;

    return 0;
}