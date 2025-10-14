/* 215. Kth Largest Element in an Array(https://leetcode.com/problems/kth-largest-element-in-an-array/description/):

    Given an integer array nums and an integer k, return the kth largest element in the array.

    Note that it is the kth largest element in the sorted order, not the kth distinct element.

    Can you solve it without sorting? */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int num : nums) {
            if(pq.size() < k) pq.push(num);
            else if(num > pq.top()) {
                pq.pop();
                pq.push(num);
            }
        }
        return pq.top();
    }
};

int main() {
    
 
    return 0;
}