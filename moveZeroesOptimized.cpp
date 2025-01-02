/* 283. Move Zeroes(https://leetcode.com/problems/move-zeroes/description/):

Given an integer array nums, move all 0's to the end of it
while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

Follow up: Could you minimize the total number of operations done? */

// Optimized solution where T.C. is O(N) for worst case &
// S.C. is O(1) for the worst case
#include <bits/stdc++.h>
using namespace std;

void moveZeroesToEnd(vector<int> &nums, int n) {
    // [0 1 0 5 2 3 0 0 1]
    int j = -1;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            j = i;
            break;
        }
    }

    for (int i = j + 1; i < n; i++) {
        if (nums[i] != 0) {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    moveZeroesToEnd(nums, n);
    for (int i : nums)
        cout << i << ' ';
    return 0;
}