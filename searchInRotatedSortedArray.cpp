/* 33. Search in Rotated Sorted
Array(https://leetcode.com/problems/search-in-rotated-sorted-array/description/):

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown
pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k],
nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For
example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become
[4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target,
return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int search(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    int lastEle = nums[r];
    while (l <= r) {
      int mid = (l + r) / 2;
      // we will divide the given rotated array in 2 regions
      // first region will be first half till the elements are sorted
      // and the second region will be the second half that is sorted

      // if target is in first region but the mid is in second region then--
      if (target > lastEle and nums[mid] <= lastEle) r = mid - 1;
      // if target is in second region but our mid comes out to be in first
      // region then --
      else if (target <= lastEle and nums[mid] > lastEle)
        l = mid + 1;
      // if the mid comes out to be in one of the two sorted regions
      // then we can simply search it by using simple 'binary search'
      else {
        if (nums[mid] == target)
          return mid;
        else if (nums[mid] > target)
          r = mid - 1;
        else
          l = mid + 1;
      }
    }
    return -1;
  }
};
int main() {
  Solution sol;
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) cin >> nums[i];
  int target;
  cin >> target;
  int ans = sol.search(nums, target);
  cout << ans;
  return 0;
}