int dfs(vector<vector<int>>& grid,int i,int j,int n,int m){
    if(grid[i][j]!=1) return 0;
    int res=1;
    grid[i][j]=2;
    vector<vector<int>> pos={{0,1},{0,-1},{-1,0},{1,0}};
    for(auto p:pos){
        int x=i+p[0], y=j+p[1];
        if(x>=0&&x<n&&y>=0&&y<m)
            res+=dfs(grid,x,y,n,m);
    }
    return res;
}
