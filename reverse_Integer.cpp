/* Reverse Integer (https://leetcode.com/problems/reverse-integer/description/):

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned). */

#include <bits/stdc++.h>
using namespace std;

int reverse(int x) {
    long long revNum = 0;
    bool isNegative = x < 0;
    long long n = abs(static_cast<long long>(x));

    while (n > 0) {
        int lastDigit = n % 10;
        revNum = (revNum * 10) + lastDigit;
        n /= 10;
    }

    if (revNum < INT_MIN or revNum > INT_MAX)
        return 0;

    return isNegative ? -revNum : revNum;
}

int main() {
    int t;
    cout << "Input no of test-cases: " << endl;
    cin >> t;
    cout << endl;

    while (t--) {
        int x;
        cout << "Input 'X': " << endl;
        cin >> x;
        int ans = reverse(x);
        cout << "Reverse of 'X' is: " << ans;
        cout << endl;
        cout << endl;
    }

    return 0;
}
