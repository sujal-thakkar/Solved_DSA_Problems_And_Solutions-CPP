/* 15. 3Sum(https://leetcode.com/problems/3sum/description/):

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets. */

//better approach, t.c.- O(n^2), s.c.- O(n), where n is the size of the input array.
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        set<vector<int>> st;
        for(int i=0; i<nums.size()-2; i++) {
            if(i > 0 and nums[i] == nums[i-1]) continue;
            vector<int> v;
            v.push_back(nums[i]);
            int target = 0 - (nums[i]);
            unordered_set<int> s;
            for(int j=i+1; j<nums.size(); j++) {
                auto it = s.find(target - (nums[j]));
                if(it != s.end()) {
                    v.push_back(nums[j]);
                    v.push_back(*it);
                    st.insert(v);
                    v.clear();
                    v.push_back(nums[i]);
                }
                s.insert(nums[j]);
            }
        }
        for(auto& i : st) ans.push_back(i);
        return ans;
    }
};
int main() {
    
 
    return 0;
}