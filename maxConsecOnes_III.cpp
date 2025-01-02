// Max Consecutive Ones III (https://leetcode.com/problems/max-consecutive-ones-iii/description/):
// Given a binary array nums and an integer k,
// return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int zeroCount = 0, ans = 0, l = 0;
        int n = nums.size();

        for (int r = 0; r < n; r++)
        {
            if (nums[r] == 0)
                zeroCount++;

            while (zeroCount > k)
            {
                if (nums[l] == 0)
                {
                    zeroCount--;
                    l++;
                }
            }

            ans = max(ans, r - l + 1);
        }
        
        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> v = {0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0};
    int k = 3;

    int ans = sol.longestOnes(v, k);

    cout << "the maximum number of consecutive 1's in the array is: " << ans;

    return 0;
}