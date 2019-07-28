/*
Given a 2D grid of 0s and 1s, return the number of elements in the largest square subgrid that has all 1s on its border, 
or 0 if such a subgrid doesn't exist in the grid.

Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
Output: 9
Example 2:

Input: grid = [[1,1,0,0]]
Output: 1

Constraints:

1 <= grid.length <= 100
1 <= grid[0].length <= 100
grid[i][j] is 0 or 1
*/

int largest1BorderedSquare(vector<vector<int>>& grid) {
    int n=grid.size(),m=grid[0].size();
    vector<vector<int>> row(n+1,vector<int>(m+1,0));
    vector<vector<int>> col=row;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(grid[i][j]){
                row[i+1][j+1]=row[i+1][j]+1;
                col[i+1][j+1]=col[i][j+1]+1;
            }
    for(int i=min(n,m); i>=1;i--)
        for(int j=i;j<n+1;j++)
            for(int k=i;k<m+1;k++){
                if(row[j][k]>=i && col[j][k]>=i && row[j-i+1][k]>=i && col[j][k-i+1]>=i)
                    return i*i;
            }
    return 0;
}
