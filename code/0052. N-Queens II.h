/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
https://assets.leetcode.com/uploads/2018/10/12/8-queens.png
Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Input: 4
Output: 2
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
    void update(int r, int c,vector<int> &row,vector<int> &col,vector<int> &diag,vector<int> &anti_diag, int reset){
        int n=row.size();
        row[r]=col[c]=diag[r-c+n-1]=anti_diag[r+c]=reset;
        return;
    }
    void backtrack(int &res,int r, vector<int> &row,vector<int> &col,vector<int> &diag,vector<int> &anti_diag) {
        int n=row.size();
        if(r==n){
            res++;
            return;
        }
        for(int i=0;i<n;i++){
            if(check(r,i,row,col,diag,anti_diag)){
                update(r,i,row,col,diag,anti_diag,1);
                backtrack(res,r+1,row,col,diag,anti_diag);
                update(r,i,row,col,diag,anti_diag,0);
            }
        }
        return;
    }
public:
    int totalNQueens(int n) {
        vector<int> row(n,0),col(n,0),diag(2*n-1,0),anti_diag(2*n-1,0);
        int res=0;
        backtrack(res,0,row,col,diag,anti_diag) ;
        return res;
    }
};
