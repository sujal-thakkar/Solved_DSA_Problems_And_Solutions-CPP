/* 1. Two Sum (https://leetcode.com/problems/two-sum/description/):

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order. */

//t.c.- O(n), s.c.- O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++) {
            auto it = m.find(target - nums[i]);
            if(it != m.end()) {
                return {(*it).second, i};
            }
            m[nums[i]] = i;
        }
        return {0,0};
    }
};
int main() {
    
 
    return 0;
}