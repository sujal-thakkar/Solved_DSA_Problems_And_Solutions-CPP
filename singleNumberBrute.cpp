/* 136. Single Number(https://leetcode.com/problems/single-number/description/):

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space */

// Ultra Brute force approach with t.c. O(n^2) and s.c. O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        if (nums.size() == 1)
            return nums[0];
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int freq = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] == nums[i])
                    freq += 1;
            }
            if (freq == 1) {
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Solution sol;
    int ans = sol.singleNumber(nums);
    cout << ans;

    return 0;
}