/* 69. Sqrt(x)(https://leetcode.com/problems/sqrtx/description/):

Given a non-negative integer x, return the square root of x rounded down to the nearest integer.
The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1)
            return x;
        // Linear search:
        /* int ans = 0;
        long i = 0;
        while(i * i <= x) {
            i++;
        }
        return (int)i-1;  */

        // Binary Search:
        int l = 0, r = x / 2;
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (mid * mid <= x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return ans;
    }
};
int main() {
    int x;
    cin >> x;
    Solution sol;
    int ans = sol.mySqrt(x);
    cout << "Sqrt of " << x << " is: " << ans;

    return 0;
}