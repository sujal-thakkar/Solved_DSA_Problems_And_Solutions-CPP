/* 11. Container With Most Water(https://leetcode.com/problems/container-with-most-water/description/):

You are given an integer array height of length n. 
There are n vertical lines drawn such that 
the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container. */

//t.c.- O(n), where n is the size of the input array. s.c.- O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r=height.size()-1;
        int maxCapacity = 0;
        while(l < r) {
            int containerSize = r - l;
            int curCapacity = 0;
            if(height[l] < height[r]) {
                curCapacity = height[l] * containerSize;
                l++;
            }
            else if(height[r] < height[l]) {
                curCapacity = height[r] * containerSize;
                r--;
            }
            else if(height[l] == height[r]) {
                curCapacity = height[l] * containerSize;
                l++;
            }
            maxCapacity = max(maxCapacity, curCapacity);
        }
        return maxCapacity;
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    Solution sol;
    int ans = sol.maxArea(v);
    cout << "the maximum amount of water a container can store is: " << ans;
 
    return 0;
}