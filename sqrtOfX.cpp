#include <bits/stdc++.h>
using namespace std;

double sqrt_precise(double n, double epsilon = 1e-15) {
    if (n < 0) {
        return numeric_limits<double>quiet_NaN(); // Return NaN for negative inputs
    }
    
    if (n == 0 || n == 1) {
        return n;
    }
    
    double x = n / 2.0; // Initial guess
    
    while (abs(x * x - n) > epsilon) {
        x = (x + n / x) / 2.0;
    }
    
    return x;
}

int main() {
    double n;
    cin>>n;
    double epilson;
    cin >> epilson;

    cout << sqrt_precise(n, 2);
 
    return 0;
}