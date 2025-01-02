// Maximum Difference Between Increasing Elements (https://leetcode.com/problems/maximum-difference-between-increasing-elements/description/):
// Given a 0-indexed integer array nums of size n,
// find the maximum difference between nums[i] and nums[j]
// (i.e., nums[j] - nums[i]), such that 0 <= i < j < n and nums[i] < nums[j].

// Return the maximum difference. If no such i and j exists, return -1.

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int ans = -1, min_till_now = INT_MAX;

        for (int j = 0; j < nums.size(); j++)
        {

            if (nums[j] > min_till_now)
                ans = max(ans, nums[j] - min_till_now);

            min_till_now = min(min_till_now, nums[j]);
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> v = {9, 4, 3, 2};

    int ans = sol.maximumDifference(v);

    if (ans == -1)
        cout << "No such i and j exists with maximum difference, code exits with " << ans;
    else
        cout << "the maximum difference between nums[i] and nums[j] is: " << ans;

    return 0;
}