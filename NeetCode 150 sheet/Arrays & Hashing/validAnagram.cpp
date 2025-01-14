/* 242. Valid Anagram (https://leetcode.com/problems/valid-anagram/description/):

Given two strings s and t, return true if t is an
anagram of s, and false otherwise. */

// t.c.- O(n), s.c.- O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        unordered_map<char, int> m1, m2;
        for (int i = 0; i < s.size(); i++) {
            m1[s[i]]++;
            m2[t[i]]++;
        }
        return (m1 == m2);
    }
};
int main() {

    return 0;
}