// Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
// Return the running sum of nums.

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        vector<int> ans(nums.size());

        for (int i = 0; i < nums.size(); i++)
            ans[i] = i > 0 ? ans[i - 1] + nums[i] : nums[i];

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> v = {0, 1, 1, 2, 0, 0, -1, -2, 0, -1};

    vector<int> result = sol.runningSum(v);

    for (int num : result)
        cout << num << " ";

    cout << endl;
    return 0;
}