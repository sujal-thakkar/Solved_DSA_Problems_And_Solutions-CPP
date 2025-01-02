/* 268. Missing Number(https://leetcode.com/problems/missing-number/description/):

Given an array nums containing n distinct numbers in the range [0, n],
return the only number in the range that is missing from the array. */

// Brute force approach /w time complesity as: O(n logn + n^2)[hypotethically], Space complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        int ans = 0;
        for (int i = 0; i <= n; i++) {
            int flag = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] == i) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                ans = i;
                break;
            }
        }
        return ans;
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
    int ans = sol.missingNumber(nums);
    cout << "The missing number is: " << ans;

    return 0;
}