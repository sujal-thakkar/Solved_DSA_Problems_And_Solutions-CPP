/* 189. Rotate Array(https://leetcode.com/problems/rotate-array/description/):

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative. */

// brute force - O(n) T.C. & an extra space of O(n) S.C.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotatedArray(vector<int> &nums, int n, int k) {
        if(n==1)
            return;

        k %= n;

        vector<int> temp(k);

        for(int i=n-k; i<n; i++) {
            temp.push_back(nums[i]);
        }

        for(int i=n-k-1; i>=0; i--) {
            nums[i+k] = nums[i];
        }

        for(int i=0; i<n; i++) {
            nums[i] = temp[i];
        }
    }
};

int main()
{
    Solution s;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0; i<n; i++)
            cin>>nums[i];
        int k;
        cin>>k;
        s.rotatedArray(nums, n, k);
        for(int i=0; i<n; i++)
            cout << nums[i] << " ";
    }
    return 0;
}