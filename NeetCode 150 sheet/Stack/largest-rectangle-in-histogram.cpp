/* 84. Largest Rectangle in Histogram (https://leetcode.com/problems/largest-rectangle-in-histogram/description/):

Given an array of integers heights representing the histogram's bar height 
where the width of each bar is 1, 
return the area of the largest rectangle in the histogram. */

//t.c.= O(n), s.c.= O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> nse(vector<int>&v) {
        int n=v.size();
        vector<int>nse(n);
        stack<int>st;
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() and v[st.top()] >= v[i]) st.pop();
            if(st.empty()) nse[i] = n;
            else nse[i] = st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> pse(vector<int>&v) {
        int n=v.size();
        vector<int>pse(n);
        stack<int>st;
        for(int i=0; i<n; i++) {
            while(!st.empty() and v[st.top()] >= v[i]) st.pop();
            if(st.empty()) pse[i] = -1;
            else pse[i] = st.top();
            st.push(i);
        }
        return pse;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>nseArr = nse(heights);
        vector<int>pseArr = pse(heights);
        int largestArea = 0;
        for(int i=0; i<heights.size(); i++) largestArea = max(largestArea, heights[i] * (nseArr[i] - pseArr[i] - 1));
        return largestArea;
    }
};
int main() {
    int n;
    cin>>n;
    vector<int> heights(n);
    for(int i=0; i<n; i++) cin>>heights[i];
    Solution sol;
    int ans = sol.largestRectangleArea(heights);
    cout << "The largest rectangle area that can be formed with the histograms is: " << ans;
 
    return 0;
}