#include <bits/stdc++.h>
using namespace std;

int add(int a, int b) {
    return a + b;
}

void greet(string name) {
    cout << "Hello, " << name;
}

int main() {
    int (*ptr)(int, int);

    // ptr = &add;
    // int c = (*ptr)(5, 4);
    // OR,
    ptr = add;
    int c = ptr(5, 4); // both are fairly right!
    cout << c << '\n';

    void (*p)(string);
    p = greet;
    p("jew");

    return 0;
}