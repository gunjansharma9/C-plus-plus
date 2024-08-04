// It is just a specific form of Recursion nothing else
#include "bits/stdc++.h"
using namespace std;

// // complexity is n!
// void printPermutation(string&str,int i){
//     if(i >= str.length()){
//         cout<<str<<" ";
//         return;
//     }

//     for(int j=i;j<str.length();j++){
//         // swap
//         swap(str[i],str[j]);
//         // recursive call
//         printPermutation(str,i+1);
//         // backtracking
//         swap(str[i],str[j]);
//     }
// }
// int main(){
//     string str = "abc";
//     int i = 0;
//     printPermutation(str,i);

//     return 0;
// }


// // Rat in a maze
// time complexity -> O(4^m*n)
// space complexity -> O(m*n)

// bool isSafe(int i,int j,int row,int col,int arr[][3],vector<vector<bool>>&visited){
//     if((i>=0 && j<row) && (j>=0 && j<col) && (arr[i][j] == 1) && (!visited[i][j])){
//         return true;
//     }else{
//         return false;
//     }
// }

// void solveMaze(int arr[3][3],int row,int col,int i,int j,vector<vector<bool>>&visited,vector<string>&path,string output){
//     if(i == row-1 && j == col-1){
//         path.push_back(output);
//         return;
//     }

//     // Down
//     if(isSafe(i+1,j,row,col,arr,visited)){
//         visited[i+1][j] = true;
//         solveMaze(arr,row,col,i+1,j,visited,path,output+'D');
//         visited[i+1][j] = false;
//     }
//     // Left
//     if(isSafe(i,j-1,row,col,arr,visited)){
//         visited[i][j-1] = true;
//         solveMaze(arr,row,col,i,j-1,visited,path,output+'L');
//         visited[i][j-1] = false;
//     }
//     // Right
//     if(isSafe(i,j+1,row,col,arr,visited)){
//         visited[i][j+1] = true;
//         solveMaze(arr,row,col,i,j+1,visited,path,output+'R');
//         visited[i][j+1] = false;
//     }
//     // Up
//     if(isSafe(i-1,j,row,col,arr,visited)){
//         visited[i-1][j] = true;
//         solveMaze(arr,row,col,i-1,j,visited,path,output+'U');
//         visited[i-1][j] = false;
//     }
// }

// int  main(){
//     int maze[3][3] = {{1,0,0},
//     {1,1,0},
//     {1,1,1}};

//     if(maze[0][0] == 0){
//         cout<<"No path exists"<<endl;
//         return 0;
//     }

//     int row = 3;
//     int col = 3;

//     vector<vector<bool>>visited(row,vector<bool>(col,false));
//     visited[0][0] = true;

//     vector<string>path;
//     string output = "";

//     solveMaze(maze,row,col,0,0,visited,path,output);

//     for(auto p:path){
//         cout<<p<<" ";
//     }cout<<endl;

//     return 0;
// }


// N Queen problem
// time complexity -> O(n!) or O(n^n)
// void printSolution(vector<vector<char>>&board,int&n){
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cout<<board[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     cout<<endl;
// }

// bool isSafe(int row,int col,vector<vector<char>>&board,int n){
//     // hmhe sirf left part check krna h or previous diagonal part check krna hai upper part isliye check ni krna qki ek col m ek hi queen place ki hai hmne or aage ka isliye check ni krre qki aage queen place hi ni ki
//     int i = row;
//     int j = col;
//     // row wise
//     while(j>=0){
//         if(board[i][j] == 'Q'){
//             return false;
//         }
//         j--;
//     }
//     // upper diagonal
//     i = row;
//     j = col;
//     while(i>=0 && j>=0){
//        if(board[i][j] == 'Q'){
//         return false;
//        }
//        i--;
//        j--;
//     }
//     // below diagonal
//     i = row;
//     j = col;
//     while(i<n && j>=0){
//         if(board[i][j] == 'Q'){
//             return false;
//         }
//         i++;
//         j--;
//     }
//     return true;
// }

// void solve(vector<vector<char>>&board,int col,int n){
//     if(col >= n){
//         printSolution(board,n);
//         return; 
//     }

//     // solve 1 case
//     for(int row = 0;row<n;row++){
//         if(isSafe(row,col,board,n)){
//             // is safe then place the queen 
//             board[row][col] = 'Q';
//             // recursive sol
//             solve(board,col+1,n);
//             // backtrack
//             board[row][col] = '-';
//         }
//     }
// }

// int main(){
//     int n = 4;
//     vector<vector<char>>board(n,vector<char>(n,'-'));
//     int col = 0;
//     solve(board,col,n);
//     return 0;
// }


// // 22. Generate Parentheses
class Solution {
public: 
    void solve(vector<string>&ans,int n,int open,int close,string output){
        if(open == 0 && close == 0){
            ans.push_back(output);
            return;
        }

        // include open bracket
        if(open > 0){
            output.push_back('(');
            solve(ans,n,open-1,close,output);
            // backtrack
            output.pop_back();
        }

        // include close bracket
        // this if condition is important
        if(close>open){
            output.push_back(')');
            solve(ans,n,open,close-1,output);
            // backtrack
            output.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int open = n;
        int close = n;
        string output = "";
        solve(ans,n,open,close,output);
        return ans;
    }
};


// // 17. Letter Combinations of a Phone Number
// // time complexity -> O(4^n)
// // space complexity -> O(4^N)
// class Solution {
// public:
//     void solve(vector<string>&ans,int index,string output,string digits,vector<string>&mapping){
//         if(index >= digits.length()){
//             ans.push_back(output);
//             return;
//         }

//         int digit = digits[index]-'0';
//         string value = mapping[digit];
//         for(int i=0;i<value.length();i++){
//             char ch = value[i];
//             output.push_back(ch);
//             solve(ans,index+1,output,digits,mapping);
//             // backtrack
//             output.pop_back();
//         }
//     }
//     vector<string> letterCombinations(string digits) {
//         vector<string>ans;
//         if(digits.length() == 0){
//             return ans;
//         }
//         int index = 0;
//         string output = "";
//         vector<string>mapping(10);
//         mapping[2]="abc";
//         mapping[3]="def";
//         mapping[4]="ghi";
//         mapping[5]="jkl";
//         mapping[6]="mno";
//         mapping[7]="pqrs";
//         mapping[8]="tuv";
//         mapping[9]="wxyz";

//         solve(ans,index,output,digits,mapping);
//         return ans;
//     }
// };