/* 75. Sort Colors(https://leetcode.com/problems/sort-colors/description/):

Given an array nums with n objects colored red, white, or blue,
sort them in-place so that objects of the same color are adjacent,
with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function. */

// Most Optimal Solution using 3 pointer, that'll blow your mind!💥
// t.c.= O(n), s.c.= O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int> &nums) {
        int n = nums.size();

        int low = 0;
        int mid = 0;
        int high = n - 1;

        /* 3 conditions:
      1) if mid = 0: swap with low and increase mid and low.
      2) if mid = 1: do nothing, but increase mid.
      3) if mid = 2: swap with high and decrease high to one place. */
        for (int i = 0; i < n; i++) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                mid++;
                low++;
            } else if (nums[mid] == 1) {
                mid++;
            } else if (nums[mid] == 2) {
                swap(nums[high], nums[mid]);
                high--;
            }
        }
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
    sol.sortColors(nums);
    for (int i : nums)
        cout << i << " ";

    return 0;
}