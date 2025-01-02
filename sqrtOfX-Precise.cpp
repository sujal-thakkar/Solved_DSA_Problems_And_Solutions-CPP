/* Now, we’re not only interested in the integral part.

 Given a value of N & P, we need to
 find sqrt(N) accurate up to p decimal places. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double mySqrtPrecise(int n, int p) {
        if (n <= 1)
            return n;
        double l = 0, r = n / 2;
        double precision = pow(10, -p);
        double ans = 0;

        while (r - l >= precision) {
            double mid = l + (r - l) / 2.0;
            if (mid * mid <= n) {
                ans = mid;
                l = mid;
            } else {
                r = mid;
            }
        }
        return ans; 
    }
};
int main() {
    int x;
    int p;
    cin >> x >> p;
    Solution sol;
    double ans = sol.mySqrtPrecise(x, p);
    cout << "the precise Sqrt of " << x << " is: " << ans;

    return 0;
}