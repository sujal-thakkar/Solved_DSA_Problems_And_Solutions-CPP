/* Okay, let’s move to the next problem now.It’s an interesting one.
[Was also asked in a nice company’s interview]

Given a function f(x) = x + x / 10 + x / 100 + x / 1000 ….
Note : the division is integer division.

Now, given a value K,
it should be pretty simply to find f(K), right? */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKOfFunc(int k) {
        int ans = 0;
        while(k > 0) {
            ans += k;
            k /= 10;
        }
        return ans;
    }
};
int main() {
    Solution sol;
    int k;
    cin >> k;
    int ans = sol.findKOfFunc(k);
    cout << ans;

    return 0;
}