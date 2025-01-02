/* 268. Missing Number(https://leetcode.com/problems/missing-number/description/):

Given an array nums containing n distinct numbers in the range [0, n],
return the only number in the range that is missing from the array. */

// The most Optimal approach /w time complesity as: O(n), Space complexity: O(1) (using XOR^)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        // we'll solve the problem using xor(^).
        // some rules - 1) while xoring 2 numbers if both the numbers are equal i.e. 2 ^ 2
        // then the result will be 0. similarly 2 ^ 2 ^ 5 ^ 5 will also result to 0.
        // 2) if one number is 0 and other is not then, the result will be the non zero number.
        // i.e. 5 ^ 5 ^ 5 ^ 5 ^ 8 will result to 8, okay enough talking, let's build!
        int n = nums.size();

        int xor1 = 0;
        int xor2 = 0;

        /* for (int i = 0; i <= n; i++) {
            xor1 = xor1 ^ i;
        }  */
        // the result will be internaly calculated mathematically.
        // but using 2 for loops will surely increase our t.c. and will make it O(2n), so we will remove one.

        for (int i = 0; i < n; i++) {
            xor2 = xor2 ^ nums[i]; // similarly there'll be a result calculated internally.
            xor1 = xor1 ^ i;       // calculate xor1 till n-1 along with xor2
        }
        xor1 = xor1 ^ n; // and then calculate n

        return xor1 ^ xor2; // xoring these two will lead us left with the missing number that'll also be the resultant.
        // Since one number is missing in the array,
        // the XOR of xor1 and xor2 will cancel out all the numbers that are present in both the nums array and the range 0 to n.
        // The result will be the missing number.
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