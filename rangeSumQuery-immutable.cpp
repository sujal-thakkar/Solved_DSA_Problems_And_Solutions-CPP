// Range Sum Query - Immutable (https://leetcode.com/problems/range-sum-query-immutable/description/):

// Given an integer array nums, handle multiple queries of the following type:

// >> Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
// Implement the NumArray class:

// >> NumArray(int[] nums) Initializes the object with the integer array nums.
// int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right
// inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

#include <bits/stdc++.h>
using namespace std;
class NumArray
{
public:
    vector<int> prefixSum;
    NumArray(vector<int> &nums)
    {
        prefixSum.resize(nums.size());
        prefixSum[0] = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            prefixSum[i] = nums[i] + prefixSum[i - 1];
        }
    }

    int sumRange(int left, int right)
    {
        if (left == 0)
            return prefixSum[right];
        else
            return prefixSum[right] - prefixSum[left - 1];
    }
};

/*
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

int main()
{
    vector<int> nums = {3, 9, 2, 6, 5, 4, 1, 0};
    NumArray obj(nums);
    cout << "the sum of the elements of nums between indices left and right inclusive is: " << obj.sumRange(3, 7) << endl;
    cout << "the sum of the elements of nums between indices left and right inclusive is: " << obj.sumRange(0, 7) << endl;
    cout << "the sum of the elements of nums between indices left and right inclusive is: " << obj.sumRange(2, 5) << endl;
    cout << "the sum of the elements of nums between indices left and right inclusive is: " << obj.sumRange(6, 7) << endl;
    return 0;
}