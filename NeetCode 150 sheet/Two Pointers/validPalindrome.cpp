/* 125. Valid Palindrome(https://leetcode.com/problems/valid-palindrome/):

A phrase is a palindrome if, after converting all uppercase 
letters into lowercase letters and removing all non-alphanumeric characters, 
it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise. */

//t.c.- O(n), s.c.- O(1), where n is the size of the input string.
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int l=0, r=s.size()-1;
        while(l < r) {
            while(!isAlphaNum(s[l]) and l < r) l++;
            while(!isAlphaNum(s[r]) and l < r) r--;
            if(s[l] >= 'A' and s[l] <= 'Z') s[l] += 32;
            if(s[r] >= 'A' and s[r] <= 'Z') s[r] += 32;
            if(s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }
    bool isAlphaNum(char c) {
        return(c >= '0' and c <= '9' or c >= 'A' and c <= 'Z' or c >= 'a' and c <= 'z');
    }
};
int main() {
    
 
    return 0;
}