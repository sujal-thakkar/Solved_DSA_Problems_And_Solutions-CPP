/* 238. Product of Array Except Self(https://leetcode.com/problems/product-of-array-except-self/description/):

Given an integer array nums, return an array answer such that answer[i]
is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation. */

//t.c.- O(n), s.c.- O(1), where n is the size of the given array, and the array used for returning the ans,
//is not considered as exra space, thus s.c. turns out to be O(1).
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> ans(nums.size());
        ans[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            int it = ans[i - 1] * nums[i - 1];
            ans[i] = it;
        }
        int it = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            ans[i] = it * ans[i];
            it *= nums[i];
        }
        return ans;
    }
};
int main() {

    return 0;
}