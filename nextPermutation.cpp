/* 31. Next Permutation(https://leetcode.com/problems/next-permutation/description/):

A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr:
[1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically
greater permutation of its integer.
More formally, if all the permutations of the array are sorted in one container
according to their lexicographical order, then the next permutation of that array is
the permutation that follows it in the sorted container. If such arrangement is not possible,
the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory. */

// optimal approach, 
// the brute would take O(!n * n) which is impossible to compute.
// the better approach is, to use the built-in STL function next_permutation(nums.begin(), nums.end())
// Optimal approach: which is the implementation of the the built-in STL function.
// t.c.= O(3n), s.c.= O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &nums) { // [2 1 5 4 3 0 0]
        int n = nums.size();
        int ind = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }
        if (ind == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = n - 1; i > ind; i--) {
            if (nums[i] > nums[ind]) {
                swap(nums[ind], nums[i]);
                break;
            }
        }
        reverse(nums.begin() + (ind + 1), nums.end());
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
    sol.nextPermutation(nums);
    cout << "The next permutation is: ";
    for (int i : nums)
        cout << i << " ";

    return 0;
}