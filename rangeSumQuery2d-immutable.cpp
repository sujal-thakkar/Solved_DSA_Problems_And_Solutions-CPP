/* Range Sum Query 2D - Immutable (https://leetcode.com/problems/range-sum-query-2d-immutable/description/):

Given a 2D matrix matrix, handle multiple queries of the following type:

Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
Implement the NumMatrix class:

NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle
defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
You must design an algorithm where sumRegion works on O(1) time complexity. */

#include <bits/stdc++.h>
using namespace std;

class NumMatrix
{
public:
    int prefixArr[200][200];
    NumMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 and j == 0)
                {
                    prefixArr[i][j] = matrix[i][j];
                }
                else if (i == 0)
                {
                    prefixArr[i][j] = prefixArr[i][j - 1] + matrix[i][j];
                }
                else if (j == 0)
                {
                    prefixArr[i][j] = prefixArr[i - 1][j] + matrix[i][j];
                }
                else
                {
                    prefixArr[i][j] = prefixArr[i][j - 1] + prefixArr[i - 1][j] - prefixArr[i - 1][j - 1] + matrix[i][j];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int ans = prefixArr[row2][col2];
        if (row1 > 0)
        {
            ans -= prefixArr[row1 - 1][col2];
        }
        if (col1 > 0)
        {
            ans -= prefixArr[row2][col1 - 1];
        }
        if (row1 > 0 and col1 > 0)
        {
            ans += prefixArr[row1 - 1][col1 - 1];
        }
        return ans;
    }
};

/*
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main()
{
    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}};

    NumMatrix *obj = new NumMatrix(matrix);

    // Test cases
    cout << "Sum of region (2, 1, 4, 3): " << obj->sumRegion(2, 1, 4, 3) << endl; // Expected output: 8
    cout << "Sum of region (1, 1, 2, 2): " << obj->sumRegion(1, 1, 2, 2) << endl; // Expected output: 11
    cout << "Sum of region (1, 2, 2, 4): " << obj->sumRegion(1, 2, 2, 4) << endl; // Expected output: 12

    delete obj;
    return 0;
}