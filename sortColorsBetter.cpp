/* 75. Sort Colors(https://leetcode.com/problems/sort-colors/description/):

Given an array nums with n objects colored red, white, or blue,
sort them in-place so that objects of the same color are adjacent,
with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function. */

// better approach, t.c.= O(2n), s.c.= O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int> &nums) {
        int n = nums.size();

        int red = 0;
        int white = 0;
        int blue = 0;

        for (int i = 0; i < n; i++) { 
            if(nums[i] == 0)
                red++;
            else if (nums[i] == 1)
                white++;
            else if (nums[i] == 2)
                blue++;
        }

        for (int i = 0; i < red; i++) {
            nums[i] = 0;
        }
        for (int j = red; j < red + white; j++) {
            nums[j] = 1;
        }
        for (int k = red + white; k < n; k++) {
            nums[k] = 2;
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