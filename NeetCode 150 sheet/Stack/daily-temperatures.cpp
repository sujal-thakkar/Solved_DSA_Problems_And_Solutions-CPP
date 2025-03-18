/* 739. Daily Temperatures (https://leetcode.com/problems/daily-temperatures/description/):

    Given an array of integers temperatures represents the daily temperatures, 
    return an array answer such that answer[i] is the number of days you have to wait 
    after the ith day to get a warmer temperature. 
    If there is no future day for which this is possible, keep answer[i] == 0 instead. */

    //t.c.= O(n), s.c.= O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            int n=temperatures.size();
            vector<int> ans(n);
            stack<int> st;
            for(int i=n-1; i>=0; i--) {
                while(!st.empty() and temperatures[st.top()] <= temperatures[i])
                    st.pop();
                if(st.empty()) ans[i] = 0;
                else ans[i] = st.top() - i;
                st.push(i);
            }
            return ans;
        }
    };
int main() {
    int n; cin>>n;
    vector<int> temps(n);
    for(int i=0; i<n; i++) cin>>temps[i];
    Solution sol;
    vector<int> ans = sol.dailyTemperatures(temps);
    cout<<"[ ";
    for(int i : ans) cout << i << " ";
    cout<<"]";
    
    return 0;
}