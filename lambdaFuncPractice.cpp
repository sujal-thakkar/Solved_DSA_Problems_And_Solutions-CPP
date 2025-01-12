#include <bits/stdc++.h>
using namespace std;

// p.s. Print prime numbers from given vector of integers

// method 1: (Using simple function to check and print)
/* bool isPrime(int x) {
    for (int i = 2; i < x; i++)
        if (x % i == 0)
            return false;
    return true;
}
void printPrime(int n) {
    if (isPrime(n))
        cout << n << " ";
}

int main() {
    vector<int> vec = {3, 9, 7, 64, 81, 52, 29, 8};
    for_each(vec.begin(), vec.end(), printPrime);

    return 0;
} */

// method 2: (Using functor/operator overloading to check and print)
/* class Prime {
public:
    bool isPrime(int x) {
        for (int i = 2; i < x; i++)
            if (x % i == 0)
                return false;
        return true;
    }

    void operator ()(int n) {
        if (isPrime(n))
            cout << n << " ";
    }

};

int main() {
    vector<int> vec = {3, 9, 7, 64, 81, 52, 29, 8};
    for_each(vec.begin(), vec.end(), Prime());

    return 0;
} */

// method 3: Using simple, easy, without jhanjhat, lambda function:
int main() {
    vector<int> vec = {3, 9, 7, 64, 81, 52, 29, 8};
    for_each(vec.begin(), vec.end(), [](int x) {
        int i;
        for (i = 2; i < x; i++) {
            if (x % i == 0)
                break;
        }
        if (i == x)
            cout << x << " ";
    });

    return 0;
}