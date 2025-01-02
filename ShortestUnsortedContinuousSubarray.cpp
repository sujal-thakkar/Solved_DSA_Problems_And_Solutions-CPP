/* Shortest Unsorted Continuous Subarray (https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/):

Given an integer array nums, you need to find one continuous subarray
such that if you only sort this subarray in non-decreasing order,
then the whole array will be sorted in non-decreasing order.

Return the shortest such subarray and output its length. */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        /* vector<int> sortedArr = nums;
        sort(sortedArr.begin(), sortedArr.end());

        int s = -1, e = -2;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != sortedArr[i])
            {
                if (s == -1)
                    s = i;
                else
                    e = i;
            }
        }
        return e - s + 1; */ // THE SORT() TAKES O(NlogN) TIME SO IT'S NOT OPTIMAL SOL!

        vector<int> preSort;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
    int ans = sol.findUnsortedSubarray(nums);
    cout << "the length of such shortest subarray is: " << ans;

    return 0;
}