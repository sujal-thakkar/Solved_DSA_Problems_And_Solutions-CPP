/* Appy and Balloons(https://www.codechef.com/problems/HMAPPY?tab=statement):

Appy loves balloons! She wants you to give her balloons on each of N consecutive days (numbered 1 through N);
let's denote the number of balloons Appy wants on day i by A[i].
The problem is that you only have M balloons.
Fortunately, you can give her candies instead of balloons as well.
On each day i, Appy accepts B[i] candies per each balloon you do not give her
- formally, if you give Appy X[i] balloons on day i,
then you have to give her C[i] = max(0, A[i] - X[i]) · B[i] candies as well.

Your task is to minimize the maximum number of candies you give Appy on some day -
find the minimum possible value of max(C1, C2, C3, ... , CN). */

/* Constraints:-
. 1 ≤ N ≤ 10^5
. 0≤ M ≤ 10^18
· 0 ≤ Ai ≤ 10^9 for each valid i
· 0 ≤ Bi ≤ 10^9 for each valid i */

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countBalloons(vector<long long> &a, vector<long long> &b, long long threshold) {
        int n = a.size();
        long long totalBallons = 0;
        for (int i = 0; i < n; i++) {
            if (threshold == 0)
                continue;
            totalBallons += max((long long)0, a[i] - (threshold / b[i]));
        }
        return totalBallons;
    }
    long long minMaxCandiesToGive(vector<long long> &a, vector<long long> &b, int m) {
        int n = a.size();
        long long l = 0;
        long long r = 0;
        for (long long i = 0; i < n; i++) {
            r = max(r, a[i] * b[i]);
        }
        int ans = 0;
        while (l <= r) {
            long long threshold = l + (r - l) / 2;
            long long curBalloons = countBalloons(a, b, threshold);
            if (curBalloons <= m) {
                ans = threshold;
                r = threshold - 1;
            } else {
                l = threshold + 1;
            }
        }
        return ans;
    }
};
int main() {
    int n;
    long long m;
    cin >> n >> m;
    vector<long long> a(n);
    vector<long long> b(n);
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (long long i = 0; i < n; i++) {
        cin >> b[i];
    }
    Solution sol;
    long long ans = sol.minMaxCandiesToGive(a, b, m);
    cout << ans;

    return 0;
}