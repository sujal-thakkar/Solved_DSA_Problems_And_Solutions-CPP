/* 128. Longest Consecutive Sequence(https://leetcode.com/problems/longest-consecutive-sequence/description/):

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time. */

// Better approach, with t.c.= O(n + n logn), s.c.= O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) { // [100,4,200,1,3,2] -> [1 2 3 4 100 200] // [0,3,7,2,5,8,4,6,0,1]
        int n = nums.size();
        if (n == 1 or n == 0)
            return n;
        sort(nums.begin(), nums.end());
        int maxSeq = 1;
        int curSeq = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1])
                continue;
            if (nums[i] == nums[i - 1] + 1) {
                curSeq++;
                maxSeq = max(maxSeq, curSeq);
            } else {
                curSeq = 1;
            }
        }
        return maxSeq;
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Solution sol;
    int ans = sol.longestConsecutive(nums);
    cout << ans;

    return 0;
}