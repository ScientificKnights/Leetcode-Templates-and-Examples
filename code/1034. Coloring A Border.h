/*
Given a 2-dimensional grid of integers, each value in the grid represents the color of the grid square at that location.

Two squares belong to the same connected component if and only if they have the same color and are next to each other 
in any of the 4 directions.

The border of a connected component is all the squares in the connected component 
that are either 4-directionally adjacent to a square not in the component, 
or on the boundary of the grid (the first or last row or column).

Given a square at location (r0, c0) in the grid and a color, 
color the border of the connected component of that square with the given color, and return the final grid.

Input: grid = [[1,1],[1,2]], r0 = 0, c0 = 0, color = 3
Output: [[3, 3], [3, 2]]
Example 2:

Input: grid = [[1,2,2],[2,3,2]], r0 = 0, c0 = 1, color = 3
Output: [[1, 3, 3], [2, 3, 3]]
Example 3:

Input: grid = [[1,1,1],[1,1,1],[1,1,1]], r0 = 1, c0 = 1, color = 2
Output: [[2, 2, 2], [2, 1, 2], [2, 2, 2]]
*/

class Solution {
private:
    vector<int> pos={1,0,-1,0,1};
public:
    void dfs1(vector<vector<int>>& grid, int r, int c, int old, int color){
        int n=grid.size(),m=grid[0].size();
        if(r==0 || r==n-1 || c==0 || c==m-1)
            grid[r][c]=INT_MIN;
        else if( (grid[r-1][c]==old||grid[r-1][c]==INT_MAX || grid[r-1][c]==INT_MIN) && (grid[r+1][c]==old||grid[r+1][c]==INT_MAX|| grid[r+1][c]==INT_MIN) && (grid[r][c-1]==old||grid[r][c-1]==INT_MAX|| grid[r][c-1]==INT_MIN) &&(grid[r][c+1]==old||grid[r][c+1]==INT_MAX|| grid[r][c+1]==INT_MIN))
            grid[r][c]=INT_MAX;
        else
            grid[r][c]=INT_MIN;
        
        for(int i=0;i<4;i++){
            int x=r+pos[i],y=c+pos[i+1];
            if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==old)
                dfs1(grid,x,y,old,color);
        }
        return;
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        int old=grid[r0][c0];
        if(old==color) return grid;
        dfs1(grid,r0,c0,old,color);
        for(auto &i:grid)
            for(auto &j:i){
                if(j==INT_MAX)
                    j=old;
                if(j==INT_MIN)
                    j=color;
                }
        return grid;
    }
};
