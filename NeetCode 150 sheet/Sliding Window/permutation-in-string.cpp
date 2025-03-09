/* 567. Permutation in String (https://leetcode.com/problems/permutation-in-string/description/):

    Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

    In other words, return true if one of s1's permutations is the substring of s2. */


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> v1(26);

        for(char c : s1) v1[c - 'a']++;

        int l=0, r=s1.size()-1;

        while(r < s2.size()) {
            vector<int> v2(26);
            for(int i=l; i<=r; i++) v2[s2[i] - 'a']++;
            if(v2 == v1) return true;
            l++; r++;
        }
        return false;
    }
};

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    Solution sol;
    bool ans = sol.checkInclusion(s1, s2)
    cout << ans;

    return 0;
}