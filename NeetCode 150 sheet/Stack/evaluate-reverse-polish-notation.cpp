/* 150. Evaluate Reverse Polish Notation (https://leetcode.com/problems/evaluate-reverse-polish-notation/description/):

    You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer. */

//t.c.= O(n), s.c.= O(1);
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int evalRPN(vector<string>& tokens) {
            stack<int> st;
            for(int i=0; i<tokens.size(); i++) {
                if(tokens[i] == "+" or 
                   tokens[i] == "-" or 
                   tokens[i] == "*" or 
                   tokens[i] == "/") 
                {
                    int oprnd1 = st.top();
                    st.pop();
                    int oprnd2 = st.top();
                    st.pop();

                    if(tokens[i] == "+") st.push(oprnd2 + oprnd1);
                    else if(tokens[i] == "-") st.push(oprnd2 - oprnd1);
                    else if(tokens[i] == "*") st.push(oprnd2 * oprnd1);
                    else st.push(oprnd2 / oprnd1);
                }
                else st.push(stoi(tokens[i]));
            }
            return st.top();
        }
    };
int main() {
    int n;
    cin >> n;
    vector<string> tokens(n);
    for(int i=0; i<n; i++) cin >> tokens[i];
    Solution sol;
    int ans = sol.evalRPN(tokens);
    cout << "Evaluation: " << ans;
 
    return 0;
}