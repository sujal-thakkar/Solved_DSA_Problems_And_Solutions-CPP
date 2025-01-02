/* 49. Group Anagrams(https://leetcode.com/problems/group-anagrams/description/):

Given an array of strings strs, group the anagrams together.
You can return the answer in any order. 

t.c. = O(m * n), s.c.= O(2N) */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> ans;
        if (strs.size() <= 1) {
            ans.push_back(strs);
            return ans;
        }
        unordered_map<string, vector<string>> mpp;

        for (string str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            mpp[sortedStr].push_back(str);
        }

        for (auto &pair : mpp) {
            ans.push_back(pair.second);
        }

        return ans;
    }
};

int main() {

    return 0;
}