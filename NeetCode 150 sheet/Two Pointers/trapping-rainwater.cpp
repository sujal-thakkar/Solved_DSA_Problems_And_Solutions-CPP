/* 42. Trapping Rain Water (https://leetcode.com/problems/trapping-rain-water/description/):

    Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
    https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 2) return 0;

        int l = 0, r = height.size()-1;
        int maxLeft = height[0], maxRight = height[r];
        int total = 0;

        while(l < r) {
            if(maxLeft < maxRight) {
                l++;
                maxLeft = max(maxLeft, height[l]);
                total += maxLeft - height[l];
            }
            else {
                r--;
                maxRight = max(maxRight, height[r]);
                total += maxRight - height[r];
            }
        }
        return total;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> height(n);
    for(int i=0; i<height.size(); i++) cin >> height[i];
    Solution sol;
    int ans = sol.trap(height);
    cout << ans;
 
    return 0;
}