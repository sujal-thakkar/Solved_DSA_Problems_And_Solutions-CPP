/* 22. Generate Parentheses (https://leetcode.com/problems/generate-parentheses/description/):

    Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses. */

    //t.c.= O(2^n), s.c.= O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(int openedN, int closedN, int n, string& stack, vector<string>& ans) {
        if(openedN == closedN and openedN == n) {
            ans.push_back(stack);
            return;
        }

        if(openedN < n) {
            stack += '(';
            backtrack(openedN + 1, closedN, n, stack, ans);
            stack.pop_back();
        }

        if(closedN < openedN) {
            stack += ')';
            backtrack(openedN, closedN + 1, n, stack, ans);
            stack.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string stack;
        vector<string> ans;
        backtrack(0, 0, n, stack, ans);
        return ans;
    }
};
int main() {
    int n;
    cin>>n;
    Solution sol;
    vector<string> ans = sol.generateParenthesis(n);
    cout << "There can be " << ans.size() << " combinations with " << n << " pairs of parentheses: \n\n";
    cout << "[ ";
    for(int i=0; i<ans.size(); i++) {
        i==ans.size()-1? cout << ans[i] : cout << ans[i] << ", ";
    }
    cout << " ]";
 
    return 0;
}