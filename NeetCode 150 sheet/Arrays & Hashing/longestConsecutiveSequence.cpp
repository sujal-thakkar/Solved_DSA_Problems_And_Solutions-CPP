/* 128. Longest Consecutive Sequence(https://leetcode.com/problems/longest-consecutive-sequence/description/):

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time. */

//t.c.- O(n), s.c.- O(n), where n is the length of the input array.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) { // [100,4,200,1,3,2] // [0,3,7,2,5,8,4,6,0,1]
        unordered_set<int> s;
        for(int& i : nums) s.insert(i);
        int maxSeq = 0;
        for(auto& i : s) {
            if(s.find(i - 1) != s.end()) continue;
            int curSeq = 1;
            int num = i;
            while(s.find(num + 1) != s.end()) {
                curSeq++;
                num++;
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