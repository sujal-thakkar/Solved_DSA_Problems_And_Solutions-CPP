/* 169. Majority Element(https://leetcode.com/problems/majority-element/description/):

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times.
You may assume that the majority element always exists in the array. */

// better approach using hash-map. t.c.= O(n), s.c.= O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[nums[i]] += 1;
        }
        for (auto &it : mpp) {
            int freq = it.second;
            if (freq > n / 2)
                return it.first;
        }
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