/* The problem is that given a number N,
we need to find fInverse(N).
In other words, we need to find a valid value K, such that f(K) = N

In yet another words, we’re basically given the output (N) of the
function, and we need to find what to give as an input (K) so that
we get the given output (N).
Ex.- f(?) = 1370 ans. f(1234) = 1370
A couple of things:
 1. We have to print -1 if there is no valid answer.
 2. It is guaranteed that if there is a valid answer, then that answer will
    be unique.

*Implement both linear search and binary search */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int funcInverseHelper(int n) {
        int ans = 0;
        while (n > 0) {
            ans += n;
            n /= 10;
        }
        return ans;
    }
    int funcInverse(int n) {
        int ans = -1;
        // Linear search:
        /* for (int i = 0; i < 1000000; i++) {
            if (funcInverseHelper(i) == n) {
                ans = i;
                break;
            }
        }
        return ans; */

        // Binary Search:
        int l = 0, r = n;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (funcInverseHelper(mid) == n) {
                ans = mid;
                break;
            } else if (funcInverseHelper(mid) > n) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
int main() {
    Solution sol;
    int n;
    cin >> n;
    int ans = sol.funcInverse(n);
    cout << ans;

    return 0;
}