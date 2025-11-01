/* 39. Combination Sum (https://leetcode.com/problems/combination-sum/description/):

Given an array of distinct integers candidates and a target integer target, 
    return a list of all unique combinations of candidates where the chosen numbers sum to target. 
    You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. 
    Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations 
that sum up to target is less than 150 combinations for the given input. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& nums, int target, vector<vector<int>>& ans, vector<int>& combi, int i) {
        if(i == nums.size() or target < 0) return;
        if(target == 0) {
            ans.push_back(combi);
            return;
        }
        // Include
        combi.push_back(nums[i]);
        backtrack(nums, target-nums[i], ans, combi, i);
        // Exclude
        combi.pop_back();
        backtrack(nums, target, ans, combi, i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combi;
        backtrack(candidates, target, ans, combi, 0);
        return ans;
    }
};

int main() {
    
 
    return 0;
}