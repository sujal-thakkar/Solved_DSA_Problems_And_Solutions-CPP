/* 347. Top K Frequent Elements(https://leetcode.com/problems/top-k-frequent-elements/description/):

Given an integer array nums and an integer k, return the k most frequent elements.
You may return the answer in any order. */

//t.c.- O(n+m), s.c.- O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> m;
        for (int i : nums) {
            m[i]++;
        }
        vector<vector<int>> v(nums.size() + 1);
        for (auto it : m) {
            v[it.second].push_back(it.first);
        }
        vector<int> ans;
        for (int i = v.size() - 1; i >= 0; i--) {
            for (int i : v[i]) {
                ans.push_back(i);
                k--;
                if (!k)
                    return ans;
            }
        }
        return {0};
    }
};
int main() {

    return 0;
}