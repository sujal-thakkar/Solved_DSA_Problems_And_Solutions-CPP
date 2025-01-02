/* 136. Single Number(https://leetcode.com/problems/single-number/description/):

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space */

// How TF did you not clicked it ?! You've done this type before bruhh!
// t.c straight O(n) and s.c. -> O(1) as well.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int xorAns = 0;

        for (int i = 0; i < nums.size(); i++) {
            xorAns ^= nums[i];
        }

        return xorAns;
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Solution sol;
    int ans = sol.singleNumber(nums);
    cout << ans;

    return 0;
}