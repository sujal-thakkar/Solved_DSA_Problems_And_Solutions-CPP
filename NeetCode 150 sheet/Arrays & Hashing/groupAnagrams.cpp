/* 49. Group Anagrams(https://leetcode.com/problems/group-anagrams/description/):

Given an array of strings strs, group the
anagrams together. You can return the answer in any order. */

//t.c.- O(n+m) s.c.- O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        map<vector<int>, vector<string>> m;
        for (int i = 0; i < strs.size(); i++) {
            vector<int> v(26);
            for (char c : strs[i]) {
                v[c - 97]++;
            }
            m[v].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for (auto &i : m) {
            ans.push_back(i.second);
        }
        return ans;
    }
};
int main() {

    return 0;
}