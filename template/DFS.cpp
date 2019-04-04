int dfs(vector<vector<int>>& grid,int i,int j,int n,int m){
    if(grid[i][j]!=1) return 0;
    int res=1;
    grid[i][j]=2;
    vector<int> pos={0,1,0,-1,0};
    for(int k=0;k<4;k++){
        int x=i+pos[k], y=j+pos[k+1];
        if(x>=0 && x<n && y>=0 && y<m)
            res+=dfs(grid,x,y,n,m);
    }
    return res;
}
