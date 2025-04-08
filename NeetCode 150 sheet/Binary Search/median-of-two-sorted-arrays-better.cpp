/* 4. Median of Two Sorted Arrays (https://leetcode.com/problems/median-of-two-sorted-arrays/description/):

Given two sorted arrays nums1 and nums2 of size m and n respectively, 
return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)). */

//t.c.= O(m+n), s.c.= O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size(); //n1 = [1,5,9] n2 = [5,9,10] = 1 5 5 9 9 10
        int idx2 = n/2;
        int idx1 = n/2 - 1;
        int ele1 = 0, ele2 = 0;
        int i=0, j=0;
        int cnt = 0;
        while(i < nums1.size() and j < nums2.size()) {
            if(nums1[i] <= nums2[j]) {
                if(cnt == idx1) ele1 = nums1[i];
                if(cnt == idx2) ele2 = nums1[i];
                if(ele1 and ele2) break;
                cnt++;
                i++;
            }
            else {
                if(cnt == idx1) ele1 = nums2[j];
                if(cnt == idx2) ele2 = nums2[j];
                if(ele1 and ele2) break;
                cnt++;
                j++;
            }
        }
        if(!ele1 or !ele2) {
            while(i < nums1.size()) {
                if(cnt == idx1) ele1 = nums1[i];
                if(cnt == idx2) ele2 = nums1[i];
                if(ele1 and ele2) break;
                cnt++;
                i++;
            }
            while(j < nums2.size()) {
                if(cnt == idx1) ele1 = nums2[j];
                if(cnt == idx2) ele2 = nums2[j];
                if(ele1 and ele2) break;
                cnt++;
                j++;
            }
        }
        if(n%2) return ele2;
        else return (double)(ele1 + ele2) / 2.0;
    }
};
int main() {
    vector<int> a = {1,2}, b = {3,4};
    Solution sol;
    double ans = sol.findMedianSortedArrays(a, b);
    cout << "the median of the two sorted arrays is: " << ans;
 
    return 0;
}