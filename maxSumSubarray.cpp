// Maximum Subarray (https://leetcode.com/problems/maximum-subarray/description/):-
// Given an integer array nums,
// find the subarray with the largest sum,
// and return its sum.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int curSum = 0, largest_sum = INT_MIN;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            curSum += nums[i];

            largest_sum = max(largest_sum, curSum);

            if (curSum < 0)
                curSum = 0;
        }
        return largest_sum;
    }
};

int main() {
    Solution sol;

    vector<int> v1 = {-2, -3, -4, -9};

    int ans = sol.maxSubArray(v1);

    cout << "The subarray with the largest sum is: " << ans;

    return 0;
}