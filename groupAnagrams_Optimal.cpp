/* 49. Group Anagrams(https://leetcode.com/problems/group-anagrams/description/):

Given an array of strings strs, group the anagrams together.
You can return the answer in any order.

t.c. = O(n * m) + O(26) + O(p) ;
s.c.= O(N) + O(p);

where 'n' is the length of the given array,
'm' is the length of every element of the given array,
and 'p' is the size of the map taken to find the answer. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> mpp;

        for (auto &str : strs) {
            vector<int> count(26, 0);
            for (char c : str) {
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for (int i = 1; i < 26; i++) {
                key += ',' + to_string(count[i]);
            }
            mpp[key].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto &pair : mpp) {
            ans.push_back(pair.second);
        }

        return ans;
    }
};

int main() {

    return 0;
}