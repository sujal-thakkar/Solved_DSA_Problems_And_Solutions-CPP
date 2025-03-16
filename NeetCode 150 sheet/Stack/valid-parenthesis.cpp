/* 20. Valid Parentheses (https://leetcode.com/problems/valid-parentheses/description/):

    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
    determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s[0]==')' or s[0]=='}' or s[0]==']') return false;
        stack<char> st;
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='(' or s[i]=='{' or s[i]=='[') st.push(s[i]);
            else {
                if(s[i]==')') {
                    if(st.empty() or st.top() != '(') return false;
                    else st.pop();
                }
                else if(s[i]=='}') {
                    if(st.empty() or st.top() != '{') return false;
                    else st.pop();
                }
                else if(s[i]==']') {
                    if(st.empty() or st.top() != '[') return false;
                    else st.pop();
                }
            }
        }
        return true;
    }
};

int main() {
    string s;
    cin >> s;
    Solution sol;
    bool ans = sol.isValid(s);
    ans==1? cout << "input string is valid" : cout << "input string is not valid";
 
    return 0;
}