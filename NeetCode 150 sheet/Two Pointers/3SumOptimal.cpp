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
        for(int i=0; i<nums.size(); i++) {
            if(i > 0 and nums[i] == nums[i-1]) continue;
            int target = 0 - nums[i];
            int l=i+1, r=nums.size()-1;
            while(l < r) {
                if(l > i+1 and nums[l] == nums[l-1]) {
                    l++;
                    continue;
                }
                if(nums[l] + nums[r] < target) l++;
                else if(nums[l] + nums[r] > target) r--;
                else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++; r--;
                }
            }
        }
        return ans;
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) 
        cin >> v[i];
    Solution sol;
    vector<vector<int>> ans = sol.threeSum(v);
    
    for(int i=0; i<ans.size(); i++) {
        cout << "[";
        for(int j=0; j<ans[i].size(); j++) {
            if(j == ans[i].size()-1) cout << ans[i][j];
            else cout << ans[i][j] << ", ";
        }
        cout << "]" << endl;
    }
 
    return 0;
}