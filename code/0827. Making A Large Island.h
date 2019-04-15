/*
In a 2D grid of 0s and 1s, we change at most one 0 to a 1.
After, what is the size of the largest island? (An island is a 4-directionally connected group of 1s).
01111
10001
01111
*/
class Solution {
private:
    vector<int> pos={1,0,-1,0,1};
    void dfs(vector<vector<int>>& grid, int r, int c, int count, int &area){
        grid[r][c]=count;
        area++;
        for(int k=0;k<4;k++){
            int x=r+pos[k],y=c+pos[k+1];
            if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y]==1 )
                dfs(grid,x,y,count,area);
        }
        return;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        if(!n) return 0;
        int m=grid[0].size();
        int count=2;    //islands label from 2;
        int res=0;
        vector<int> areas(2,0);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==1){
                    int area=0;
                    dfs(grid,i,j,count,area);
                    areas.push_back(area);
                    res=max(res,area);
                    count++;
                }
        //scan 0
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(!grid[i][j]){
                    set<pair<int,int>> s;   // {area, island_label} touch same island, cannot use other data structure
                    for(int k=0;k<4;k++){
                        int x=i+pos[k],y=j+pos[k+1];
                        if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y]>=2)
                            s.insert({areas[grid[x][y]],grid[x][y]});
                    }
                    int temp=1;
                    for(auto i:s)
                        temp+=i.first;
                    res=max(res,temp);
                }
        return res;
    }
};
