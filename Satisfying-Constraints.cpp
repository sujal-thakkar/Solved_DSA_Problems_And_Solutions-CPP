// Satisfying Constraints : (https://codeforces.com/contest/1920/problem/A)

// Alex is solving a problem. He has n
// constraints on what the integer k
// can be. There are three types of constraints:

// k
//  must be greater than or equal to some integer x;

// k
//  must be less than or equal to some integer x;

// k
//  must be not equal to some integer x;

// find the number of integers k,
// that satisfy all n constraints.
// It is guaranteed that the answer is finite (there exists at least one constraint of type 1
// and at least one constraint of type 2)
// Also, it is guaranteed that no two constraints are the exact same.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> ans;
    int k = 0;
    int t; cin >> t;

    while(t--) {
        int n; cin >> n;
        while(n--) {
            int a, x;
            cin >> a >> x;
            if(a == 1) {

            }
            if(a == 2) {

            }
            if(a == 3) {
                
            }
        }
    }

    return 0;
}