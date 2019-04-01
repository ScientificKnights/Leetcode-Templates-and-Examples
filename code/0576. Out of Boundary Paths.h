There is an m by n grid with a ball. Given the start coordinate (i,j) of the ball, 
you can move the ball to adjacent cell or cross the grid boundary in four directions (up, down, left, right). 
However, you can at most move N times. Find out the number of paths to move the ball out of grid boundary. 
The answer may be very large, return it after mod 109 + 7.

Input: m = 2, n = 2, N = 2, i = 0, j = 0
Output: 6
*/

int findPaths(int m, int n, int N, int i, int j) {
    if(N<=0) return 0;
    vector<int> move={0,-1,0,1,0};
    vector<vector<int>> prev(m,vector<int>(n,0));
    prev[i][j]=1;
    int res=0;
    for(int step=1;step<=N;step++){
        vector<vector<int>> cur(m,vector<int>(n,0));
        for(int row=0;row<m;row++)
            for(int col=0;col<n;col++){
                int x,y;
                for(int l=0;l<4;l++){
                    x=row+move[l],y=col+move[l+1];
                    if(x<0 || x>=m || y<0 || y>=n)
                        res=(res+prev[row][col])%1000000007;
                    else
                        cur[x][y]=(cur[x][y]+prev[row][col])%1000000007;
                }
            }
        prev=cur;
    }
    return res;
}
