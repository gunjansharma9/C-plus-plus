#include "bits/stdc++.h"
using namespace std;

// 37. Sudoku Solver
// time complexity -> O(9^m*n)
// space complexity -> O(m*n)
class Solution {
public:
    bool isSafe(char value,vector<vector<char>>& board,int curr_row,int curr_col){
        // row check
        for(int col = 0;col<9;col++){
            if(board[curr_row][col] == value){
                return false;
            }
        }

        // col check
        for(int row = 0;row < 9;row++){
            if(board[row][curr_col] == value){
                return false;
            }
        }

        // 3*3 box check
        for(int i=0;i<9;i++){
            if(board[3*(curr_row/3) + (i/3)][3*(curr_col/3) + (i%3)] == value){
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board,int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // check for empty cell
                if(board[i][j] == '.'){
                    for(char value = '1';value<='9';value++){
                        if(isSafe(value,board,i,j)){
                            board[i][j] = value;
                            bool aageKaSolution = solve(board,n);
                            if(aageKaSolution == true){
                                return true;
                            }
                            // backtrack only when you can't get an aagekasolution 
                            board[i][j] = '.';
                        }
                    }
                    // if 1-9 tk kisi b value se solution nhi nikla,that means piche kahin pr galti hai ,go back by returning false
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,9);
    }
};