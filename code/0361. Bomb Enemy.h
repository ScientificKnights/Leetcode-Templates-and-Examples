/*
Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), 
return the maximum enemies you can kill using one bomb.
The bomb kills all the enemies in the same row and column from the planted point 
until it hits the wall since the wall is too strong to be destroyed.
Note: You can only put the bomb at an empty cell.

Input: 
0 E 0 0 
E 0 W E 
0 E 0 0
Placing a bomb at (1,1) kills 3 enemies.
*/

class Solution {
private:
    int row_helper(vector<vector<char>>& grid,int row, int col){
        int res=0;
        int m=grid[0].size();
        for(int i=col;i<m&& grid[row][i]!='W';i++)
            if(grid[row][i]=='E')
                res++;
        for(int i=col;i>=0 && grid[row][i]!='W';i--)
            if(grid[row][i]=='E')
                res++;
        return res;
    }
    int col_helper(vector<vector<char>>& grid,int row, int col){
        int res=0;
        int n=grid.size();
        for(int i=row;i<n&& grid[i][col]!='W';i++)
            if(grid[i][col]=='E')
                res++;
        for(int i=row;i>=0 && grid[i][col]!='W';i--)
            if(grid[i][col]=='E')
                res++;
        return res;
    }
    
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=n?grid[0].size():0;
        if(n==0||m==0)return 0;
        
        int rowkill=-1,res=0;           //row存row里enemy数，遇到w变为-1
        vector<int> colkill(m,-1);      //col[n] 存col里enemy数，遇到w变为-1
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='W'){
                    rowkill=-1;colkill[j]=-1;
                }
                else if(grid[i][j]=='0'){
                    if(rowkill==-1)
                        rowkill=row_helper(grid,i,j);
                    if(colkill[j]==-1)
                        colkill[j]=col_helper(grid,i,j);
                    res=max(res,rowkill+colkill[j]);
                }
            }
            rowkill=-1; //row清0
        }
        return res;
    }
};
