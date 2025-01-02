/* 1. Two Sum(https://leetcode.com/problems/two-sum/description/):

Given an array of integers nums and an integer target,
return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution,
and you may not use the same element twice.

You can return the answer in any order. */

// brute force approach with T.C.= O(n^2) and s.c.= O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target)
                    return {i, j};
            }
        }
        return {-1, -1};
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int target;
    cin >> target;
    Solution sol;
    vector<int> arr = sol.twoSum(nums, target);
    for (auto it : arr) {
        cout << it << " ";
    }

    return 0;
}