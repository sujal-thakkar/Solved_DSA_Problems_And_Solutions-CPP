/* 268. Missing Number(https://leetcode.com/problems/missing-number/description/):

Given an array nums containing n distinct numbers in the range [0, n],
return the only number in the range that is missing from the array. */

// Optimal approach /w time complesity as: O(n), Space complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int n = nums.size();
        int sum = n * (n + 1) / 2;
        int sum2 = 0;
        for (int i = 0; i < n; i++)
            sum2 += nums[i];

        return (sum - sum2);
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution sol;
    int ans = sol.missingNumber(nums);
    cout << "The missing number is: " << ans;

    return 0;
}