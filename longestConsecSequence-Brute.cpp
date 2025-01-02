/* 128. Longest Consecutive Sequence(https://leetcode.com/problems/longest-consecutive-sequence/description/):

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time. */

// Brute force approach, w/ t.c.= O(n^2), s.c.= O(1)
// will not work with the given constraints where, 
// 0 <= nums.length <= 10^5
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) { // [100,4,200,1,3,2] // [0,3,7,2,5,8,4,6,0,1]
        int n = nums.size();
        int maxSeq = 0;
        for (int i = 0; i < n; i++) {
            int curSeq = 1;
            int x = nums[i];
            for (int j = 0; j < n; j++) {
                if (nums[j] == x + 1) {
                    curSeq += 1;
                    x += 1;
                    j = -1;
                }
            }
            maxSeq = max(maxSeq, curSeq);
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