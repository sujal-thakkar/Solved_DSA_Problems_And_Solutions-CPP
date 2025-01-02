/* 169. Majority Element(https://leetcode.com/problems/majority-element/description/):

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times.
You may assume that the majority element always exists in the array. */

// again better approach, by sorting the array and counting freq. 
// t.c.= O(n logn) + O(n), s.c.= O(1) (might or might not say better, but yeah, consider as a sol)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) { // nums= [0 2 2 0 2 1 2 2 2 1] -> [0 0 1 1 2 2 2 2 2 2]
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int freq = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                freq++;
            } else if (freq > n / 2) {
                return nums[i - 1];
            } else {
                freq = 1;
            }
        }
        if (freq > n / 2)
            return nums[n - 1];

        return -1;
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
    int ans = sol.majorityElement(nums);
    cout << ans;

    return 0;
}