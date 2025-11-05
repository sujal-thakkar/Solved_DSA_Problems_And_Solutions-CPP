/* 40. Combination Sum II (https://leetcode.com/problems/combination-sum-ii/description/):

Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations. */

#include <bits/stdc++.h>
using namespace std

class Solution {
public:
    void backtrack(
        vector<int>& candidates, 
        int target, 
        vector<vector<int>>& ans,
        vector<int>& combo,
        int i)
    {
        if(target == 0) {
            ans.push_back(combo);
            return;
        }    
        if(target < 0 or i == candidates.size()) return;

        combo.push_back(candidates[i]);
        backtrack(candidates, target - candidates[i], ans, combo, i + 1);
        
        combo.pop_back();
        while(i + 1 < candidates.size() and candidates[i] == candidates[i+1]) i++;
        backtrack(candidates, target, ans, combo, i + 1);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> combo;
        backtrack(candidates, target, ans, combo, 0);
        return ans;
    }
};

int main() {
    
    return 0;
}