/* 15. 3Sum(https://leetcode.com/problems/3sum/description/):

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets. */

//brute force approach, t.c.- O(n^3) * nlogn * nlogn, s.c.- O(1), array to return ans, is not considered as extra space.
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1; j<nums.size(); j++) {
                for(int k=j+1; k<nums.size(); k++) {
                    if(nums[i] + nums[j] + nums[k] == 0) {
                        vector<int>v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[k]);
                        sort(v.begin(), v.end());
                        auto it = find(ans.begin(), ans.end(), v);
                        if(it == ans.end()) ans.push_back(v);
                    }
                }
            }
        }
        return ans;
    }
};
int main() {
    
 
    return 0;
}