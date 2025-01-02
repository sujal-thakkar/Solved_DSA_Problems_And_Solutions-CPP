/* 73. Set Matrix Zeroes(https://leetcode.com/problems/set-matrix-zeroes/description/):

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

Example:

Input: matrix = 
[1,1,1],
[1,0,1],
[1,1,1]
Output: [[1,0,1],[0,0,0],[1,0,1]] 

Input: matrix = 
[0,1,2,0],
[3,4,5,2],
[1,3,1,5]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]*/

// Brute force approach. t.c.= O(2 * (m * n) + (m + n)) ~ O(n^3), s.c.= O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void markRow(vector<vector<int>> &matrix, int n, int i) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0)
                matrix[i][j] = -1;
        }
    }
    void markColumn(vector<vector<int>> &matrix, int m, int j) {
        for (int i = 0; i < m; i++) {
            if (matrix[i][j] != 0)
                matrix[i][j] = -1;
        }
    }
    
    void setZeroes(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    markRow(matrix, m, i);
                    markColumn(matrix, n, j);
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1)
                    matrix[i][j] = 0;
            }
        }
    }
};
int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    Solution sol;
    sol.setZeroes(matrix);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
    }

    return 0;
}