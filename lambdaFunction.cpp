#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 2, b = 5;
    //lambda expression:
    [&]() -> void {
        cout << a << " " << b;
        a = 4;
    }();
    
    cout << endl << a;
    return 0;
}