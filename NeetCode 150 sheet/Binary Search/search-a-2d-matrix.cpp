/* 74. Search a 2D Matrix (https://leetcode.com/problems/search-a-2d-matrix/description/):

You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity. */

// t.c.= O(log(m * n)), s.c.= O(m * n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> v;
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[i].size(); j++) v.push_back(matrix[i][j]);
        }
        int l=0, r=v.size()-1;
        int itCount = 0;
        while(l <= r) {
            int mid = l+(r-l)/2;
            if(target > v[mid]) l=mid+1;
            else if(target < v[mid]) r=mid-1;
            else return true;
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 60;
    Solution sol;
    if(sol.searchMatrix(matrix, target)) cout << "Target is present!";
    else cout << "Target isn't present";
 
    return 0;
}