/* 78. Subsets (https://leetcode.com/problems/subsets/description/):

Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& nums, vector<int>& v, vector<vector<int>>& ans, int i) {
        if(i == nums.size()) {
            ans.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        backtrack(nums, v, ans, i+1);
        v.pop_back();
        backtrack(nums, v, ans, i+1);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> ans;
        backtrack(nums, v, ans, 0);
        return ans;
    }
};

int main() {
    
 
    return 0;
}