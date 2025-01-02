/* 169. Majority Element(https://leetcode.com/problems/majority-element/description/):

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times.
You may assume that the majority element always exists in the array. */

// Optimal approach using ❎Moore's Voting Algorithm❗ t.c.= O(n), s.c.= O(1)
// If, in the question, it's clarified that there is surely an element with majority occurance,
// then we can return the element directly bcz we've had found our answer by then.

// but if there can be elements which are not majority. We'll have to explicitly check that,
// by traversing through the array and checking if our candidate's freq is >n/2 or not.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int n = nums.size();
        int candidate = nums[0];
        int ctr = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == candidate) {
                ctr++;
            } else {
                ctr--;
            }
            if (ctr == 0) {
                candidate = nums[i];
                ctr = 1;
            }
        }
        // if there is surely an element with majority count, then we can return candidate here.
        // return candidate;
        // but if it's not clarified, then we need to check that explicitly.
        int candidateFreq = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == candidate)
                candidateFreq++;
        }
        if (candidateFreq > n / 2)
            return candidate;
        return -1;
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
    int ans = sol.majorityElement(nums);
    cout << ans;

    return 0;
}