/* 1. Two Sum(https://leetcode.com/problems/two-sum/description/):

Given an array of integers nums and an integer target,
return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution,
and you may not use the same element twice.

You can return the answer in any order. */

// Optimal approach using Hash-Map.
// if we use map, then it will take O(n) to iterate through nums[] and O(log n) to iterate through map to find y.
// so the t.c. boils down to = O(n * log n), s.c.= O(n)

// if we use unordered map, then to find y in map will take O(1) for n elements in best and average case,
// in that case our overall t.c. will be O(n)
// but in the worst case it might go to O(n^2) and s.c.= O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        int n = nums.size();

        unordered_map<int, int> mpp;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int y = target - x;
            if (mpp.find(y) != mpp.end()) {
                return {mpp[y], i};
            }
            mpp[x] = i;
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
    for (auto it : arr)
        cout << it << " ";

    return 0;
}