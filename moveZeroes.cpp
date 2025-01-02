/* 283. Move Zeroes(https://leetcode.com/problems/move-zeroes/description/):

Given an integer array nums, move all 0's to the end of it 
while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

Follow up: Could you minimize the total number of operations done? */

// brute force solution where T.C. is O(N) for worst case &
// S.C. is O(N) for the worst case
#include <bits/stdc++.h>
using namespace std;

void moveZeroesToEnd(vector<int> &nums, int n) {
    if(n == 1) //[1 0 2 3 2 0 0 4 5 1]
        return;
    
    vector<int> temp;
    for(int i=0; i<n; i++) {
        if(nums[i] != 0)
            temp.push_back(nums[i]);
    }

    for(int i=0; i<temp.size(); i++) {
        nums[i] = temp[i];
    }

    for(int i=temp.size(); i<n; i++) {
        nums[i] = 0;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
        cin >> nums[i];
    moveZeroesToEnd(nums, n);
    for(int i : nums)
        cout << i << ' ';
    return 0;
}