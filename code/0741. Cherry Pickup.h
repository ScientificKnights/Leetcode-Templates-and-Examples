/*
In a N x N grid representing a field of cherries, each cell is one of three possible integers.

0 means the cell is empty, so you can pass through;
1 means the cell contains a cherry, that you can pick up and pass through;
-1 means the cell contains a thorn that blocks your way.

Your task is to collect maximum number of cherries possible by following the rules below:

Starting at the position (0, 0) and reaching (N-1, N-1) by moving right or down through valid path cells (cells with value 0 or 1);
After reaching (N-1, N-1), returning to (0, 0) by moving left or up through valid path cells;
When passing through a path cell containing a cherry, you pick it up and the cell becomes an empty cell (0);
If there is no valid path between (0, 0) and (N-1, N-1), then no cherries can be collected.

Input: grid =
[[0, 1, -1],
 [1, 0, -1],
 [1, 1,  1]]
Output: 5
grid is an N by N 2D array, with 1 <= N <= 50.
Each grid[i][j] is an integer in the set {-1, 0, 1}.
It is guaranteed that grid[0][0] and grid[N-1][N-1] are not -1.
*/

    int cherryPickup(vector<vector<int>>& grid) {
        /*
        It's easy to think in this way, the 2 persons pickup together, at time t, person a is at [i,j], person b is at[k,l] 
        where i+j == k+l ==t, so there are 4 possible previous position pairs, each position pair can be defined as a tuple(i,j,k).
        */
        int n = grid.size();
        vector<vector<vector<int>>> a(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, INT_MIN)));
        a[0][1][0] = a[1][0][0] = a[0][1][1] = a[1][0][1] = 0;
        for (int i = 0; i < n; i++)
           for (int j = 0; j < n; j++)
               for (int k = max(0, i+j-n+1), l; k <= i+j && k < n; k++) 
                //l = i + j - k < n   =>   k > i + j - n   =>  k >= i + j - n+1
                   if (grid[i][j]>=0 && grid[k][l= i + j - k] >= 0)
                       a[i+1][j+1][k+1]=grid[i][j]+(k==i ? 0 : grid[k][l])+max(max(a[i][j+1][k], a[i][j+1][k+1]), max(a[i+1][j][k], a[i+1][j][k+1]));
        return max(a[n][n][n], 0);
    }
