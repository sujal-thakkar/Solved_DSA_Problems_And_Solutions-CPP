/* 36. Valid Sudoku(https://leetcode.com/problems/valid-sudoku/description/):

Determine if a 9 x 9 Sudoku board is valid. 
Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Note:
A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules. */

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> rows, cols;
        unordered_map<pair<int, int>, unordered_set<int>> sqrs;

        for(int r=0; r<9; r++) {
            for(int c=0; c<9; c++) {
                if(board[r][c] == '.') continue;

                if(rows[r].count(board[r][c]) or cols[c].count(board[r][c]) or sqrs[{r/3, c/3}].count(board[r][c])) return false;

                rows[r].insert(board[r][c]);
                cols[c].insert(board[r][c]);
                sqrs[{r/3, c/3}].insert(board[r][c]);
            }
        }      
        return true;
    }
};
int main() {
    
 
    return 0;
}