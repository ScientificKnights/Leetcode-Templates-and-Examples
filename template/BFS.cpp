/*
You are given a m x n 2D grid initialized with these three possible values.
-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF 
as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, 
it should be filled with INF.
Given the 2D grid:
INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:
  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
*/

void BFS(vector<vector<int>>& rooms) {
    int n=rooms.size();
    if(n==0) return;
    int m=rooms[0].size(),level=1;
    vector<int> pos={1,0,-1,0,1};
    queue<pair<int,int>> q;
    //把所有的起始点加入queue
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(rooms[i][j]==0)
                q.push({i,j});
        }
    while(!q.empty()){
        int k=q.size();   //记录这层数目
        for(int i=0;i<k;i++){
            int r=q.front().first,c=q.front().second;
            q.pop();
            for(int j=0;j<4;j++){
                int x=r+pos[j],y=c+pos[j+1];
                if(x>=0 && x<n && y>=0 && y<m && rooms[x][y]!=-1 && rooms[x][y]>level){ //没扫描过或者扫描的结果大
                    q.push({x,y});
                    rooms[x][y]=level;
                }
            }
        }
        level++;
    }
    return;
}
