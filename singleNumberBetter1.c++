/* 136. Single Number(https://leetcode.com/problems/single-number/description/):

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space */

// medium approach using hash. But time complexity is O(3n)[bcz of 3 for loops] and s.c. O(n)
// but the biggest problems is that, the algorithm will not work if nums contains negative elements.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        int maxi = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
        }

        vector<int> hash(n + maxi, 0);

        for (int i = 0; i < n; i++) {
            hash[nums[i]]++;
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (hash[nums[i]] == 1)
                ans = nums[i];
        }

        return ans;
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