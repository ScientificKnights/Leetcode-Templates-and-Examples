/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
https://assets.leetcode.com/uploads/2018/10/12/8-queens.png
Given an integer n, return all distinct solutions to the n-queens puzzle.
Each solution contains a distinct board configuration of the n-queens' placement, 
where 'Q' and '.' both indicate a queen and an empty space respectively.

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

class Solution {
private:
    bool check(int r, int c, vector<int> &row,vector<int> &col,vector<int> &diag,vector<int> &anti_diag){
        int n=row.size();
        if(row[r]==0 && col[c]==0 && diag[r-c+n-1]==0 && anti_diag[r+c]==0)
            return true;
        else
            return false;
    }
    void update(int r, int c,vector<string> & path, vector<int> &row,vector<int> &col,vector<int> &diag,vector<int> &anti_diag, char reset){
        int n=row.size();
        int i=(reset=='Q')?1:0;
        row[r]=i,col[c]=i,diag[r-c+n-1]=i,anti_diag[r+c]=i;
        path[r][c]=reset;
        return;
    }
    void backtrack(vector<vector<string>> &res,vector<string> & path,int r, vector<int> &row,vector<int> &col,vector<int> &diag,vector<int> &anti_diag) {
        int n=path.size();
        if(r==n){
            res.push_back(path);
            return;
        }
        for(int i=0;i<n;i++){
            if(check(r,i,row,col,diag,anti_diag)){
                update(r,i,path,row,col,diag,anti_diag,'Q');
                backtrack(res,path,r+1,row,col,diag,anti_diag);
                update(r,i,path,row,col,diag,anti_diag,'.');
            }
        }
        return;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> row(n,0),col(n,0),diag(2*n-1,0),anti_diag(2*n-1,0);
        vector<vector<string>> res;
        vector<string> path(n,string(n,'.')) ;
        backtrack(res,path,0,row,col,diag,anti_diag) ;
        return res;
    }
};
