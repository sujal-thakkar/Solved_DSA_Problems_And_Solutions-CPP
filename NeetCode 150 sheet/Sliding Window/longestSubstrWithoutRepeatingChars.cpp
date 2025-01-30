/* 3. Longest Substring Without Repeating Characters
(https://leetcode.com/problems/longest-substring-without-repeating-characters/description/):

Given a string s, find the length of the longest substring
without repeating characters. */

// t.c.- O(n), s.c.- O(m), where n is the size of the input array and m is the number of unique characters in the given string.
#include <bits/stdc++.h>
using namespace std;
class Solution { // "a, b, c, a, b, c, b, b"  "d v d v f"
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int maxLen = 0;
        int i = 0;
        for (int j = 0; j < s.size(); j++) {
            while (st.find(s[j]) != st.end()) {
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);
            maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};

int main() {

    return 0;
}