/* 189. Rotate Array(https://leetcode.com/problems/rotate-array/description/):

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative. */

// brute force - O(n) T.C. & an extra space of O(n) S.C.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // if interviewer asks not to use in-built reverse function,
    // in that case, you can make one!
    // we'll make one for ourselves here.
    void reverse(vector<int> &nums, int start, int end) {
        while (start <= end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }

    void rotatedArray(vector<int> &nums, int n, int k) {
        if (n == 1)
            return;

        k %= n; //[1 2 3 4 5 6] -> [4 5 6 1 2 3]

        reverse(nums, 0, n - k - 1);
        reverse(nums, n - k, n - 1);
        reverse(nums, 0, n - 1);
    }
};

int main() {
    Solution s;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        int k;
        cin >> k;
        s.rotatedArray(nums, n, k);
        for (int i = 0; i < n; i++)
            cout << nums[i] << " ";
    }
    return 0;
}