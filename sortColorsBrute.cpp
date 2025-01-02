/* 75. Sort Colors(https://leetcode.com/problems/sort-colors/description/):

Given an array nums with n objects colored red, white, or blue,
sort them in-place so that objects of the same color are adjacent,
with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function. */

// brute force approach with using in-built library's sorting algorithm, merge sort. t.c.= O(n log n), s.c.= O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> merge(vector<int> &left, vector<int> &right) {
        vector<int> ans;
        int i = 0;
        int j = 0;

        while (i < left.size() and j < right.size()) {
            if (left[i] <= right[j])
                ans.push_back(left[i++]);
            else {
                ans.push_back(right[j++]);
            }
        }
        while (i < left.size()) {
            ans.push_back(left[i++]);
        }
        while (j < right.size()) {
            ans.push_back(right[j++]);
        }
        return ans;
    }
    vector<int> sortColors(vector<int> &nums) {
        int n = nums.size();
        if (n == 1)
            return nums;
        vector<int> left(nums.begin(), nums.begin() + n / 2);
        vector<int> right(nums.begin() + n / 2, nums.end());

        left = sortColors(left);
        right = sortColors(right);

        return merge(left, right);
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
    vector<int> ans = sol.sortColors(nums);
    for (int i : ans)
        cout << i << " ";

    return 0;
}