76. Minimum Window Substring (https://leetcode.com/problems/minimum-window-substring/description/):

    Given two strings s and t of lengths m and n respectively, 
    return the minimum window substring of s such that every character in t (including duplicates) is included in the window.
    If there is no such substring, return the empty string "".

    The testcases will be generated such that the answer is unique.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string minWindow(string s, string t) {
            if(t.size() > s.size()) return "";

            unordered_map<char, int> tm, sm;

            for(char c : t) tm[c]++;

            int have = 0;
            int need = tm.size();
            pair<int, int> ansIdx;
            int ansSize = INT_MAX;
            int l=0, r=0;

            while(r < s.size()) {
                if(tm.find(s[r]) != tm.end()) {
                    sm[s[r]]++;
                    if(sm[s[r]] == tm[s[r]]) have++;
                }
                while (have == need) {
                    if(r-l+1 < ansSize) {
                        ansSize = r-l+1;
                        ansIdx = {l, r};
                    }
                    if(tm.find(s[l]) != tm.end()) {
                        sm[s[l]]--;
                        if(sm[s[l]] < tm[s[l]]) {
                            have--;
                        }
                    }
                    l++;
                }
                r++;
            }
            if(ansSize != INT_MAX) return s.substr(ansIdx.first, ansSize);
            else return "";
        }
    };
int main() {
    string s, t;
    cin >> s >> t;
    Solution sol;
    string ans = sol.minWindow(s, t);
    cout << "Ans: " << ans;
 
    return 0;
}