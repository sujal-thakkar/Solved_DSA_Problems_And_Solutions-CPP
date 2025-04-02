/* 153. Find Minimum in Rotated Sorted Array (https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/):

Suppose an array of length n sorted in ascending order is rotated between 1 and n times. 
For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array 
[a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, 
return the minimum element of this array.

You must write an algorithm that runs in O(log n) time. */

// t.c.= O(log n), s.c.= O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        int ans = INT_MAX;
        while(l <= r) {
            int mid = l + (r-l)/2;
            ans = min(ans, nums[mid]);
            if(nums[r] < nums[mid]) l = mid+1;
            else r = mid-1;
        }
        return ans;
    }
};
int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    Solution sol;
    int ans = sol.findMin(nums);
    cout << "ans: " << ans;
 
    return 0;
}