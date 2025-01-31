/* 424. Longest Repeating Character Replacement(https://leetcode.com/problems/longest-repeating-character-replacement/description/):

You are given a string s and an integer k.
You can choose any character of the string and change it to any other uppercase English character.
You can perform this operation at most k times.

Return the length of the longest substring containing the same letter
you can get after performing the above operations. */

// t.c.- O(n)*O(26) => O(n), s.c.- O(26) => O(1).
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> m;
        int l=0, r=0;
        int ans=0;
        while(r < s.size()) {
            m[s[r]]++;
            int curWinLen = r-l +1;
            int mostFreqChar = 0;
            for(auto& i : m) {
                mostFreqChar = max(mostFreqChar, i.second);
            }
            int replacementReq = curWinLen - mostFreqChar;
            if(replacementReq <= k) {
                ans = max(ans, curWinLen);
                r++;
            }
            else {
                m[s[l]]--;
                l++;
                m[s[r]]--;
            }
        }
        return ans;
    }
};
int main() {
    string s;
    cin>>s;
    int k;
    cin >> k;
    Solution sol;
    int ans = sol.characterReplacement(s, k);
    cout << "the length of the longest substring containing the same letter is: " << ans;

    return 0;
}