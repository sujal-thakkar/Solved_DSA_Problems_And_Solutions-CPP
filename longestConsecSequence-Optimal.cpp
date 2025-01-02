/* 128. Longest Consecutive Sequence(https://leetcode.com/problems/longest-consecutive-sequence/description/):

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time. */

// Optimal approach. With t.c.= O(maxSeq + 2n), s.c= O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) { // [100,4,200,1,3,2]  [0,3,7,2,5,8,4,6,0,1]
        int n = nums.size();
        if (n == 0 or n == 1)
            return n;
        unordered_set<int> st;
        int maxSeq = 0;
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }
        for (auto it : st) {
            int curSeq = 1;
            int x = it;
            if (st.find(it - 1) == st.end()) {
                while (st.find(x + 1) != st.end()) {
                    curSeq++;
                    x++;
                }
                maxSeq = max(maxSeq, curSeq);
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