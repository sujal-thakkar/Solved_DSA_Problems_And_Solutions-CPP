/* Key Pair (https://www.geeksforgeeks.org/problems/key-pair5616/1):

Given an array arr of positive integers and another number x.
Determine whether two elements exist in arr whose sum is exactly x or not. */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to check if array has 2 elements
    // whose sum is equal to the given value
    bool hasArrayTwoCandidates(vector<int> &arr, int x)
    {
        int n = arr.size();
        /* 
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] + arr[i] == x)
                    return true;
            }
        }
        */

        // Even u=if this code gives us the answer but will not work on online judge!
        // because the time complexity of it, is simply O(n^2) and the constraints
        // we were given was upto 10^5(100000) and it will surpass it and will give -
        // TLE Error! we've to find more optimized sol, of O(N) complexity -->

        vector<int> memo(100001, 0);

        for (int i = 0; i < n; i++)
        {
            int curNum = arr[i];
            int reqNum = x - curNum;

            if (reqNum > 0 and reqNum <= 100000 and memo[reqNum] == 1)
            {
                return true;
            }
            memo[curNum] = 1;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    int x = 200000;
    vector<int> v = {12, 3, 100000, 1, 100000, 50000};
    bool ans = sol.hasArrayTwoCandidates(v, x);
    cout << ans;

    return 0;
}
