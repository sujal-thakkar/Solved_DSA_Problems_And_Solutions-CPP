/* 46. Permutations (https://leetcode.com/problems/permutations/description/):

Given an array nums of distinct integers, 
return all the possible permutations. You can return the answer in any order. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, int idx) {
        if(idx == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for(int i=idx; i<nums.size(); i++) {
            swap(nums[i], nums[idx]);
            backtrack(nums, ans, idx+1);
            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(nums, ans, 0);
        return ans;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}