/*
Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.
Input:
0 0 0
0 1 0
1 1 1
Output:
0 0 0
0 1 0
1 2 1
*/
vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    //BFS, 从1开始会重复，从0 开始
    //整体开始，先所有零，再所有1
    int n=matrix.size(), m=matrix[0].size();
    vector<vector<int>> res(n,vector<int>(m,0));
    vector<int> pos={-1,0,1,0,-1};
    queue<pair<int,int>> q;
    //先加挨着零的
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(matrix[i][j]==0)
                for(int p=0;p<4;p++){
                    int y=i+pos[p], x=j+pos[p+1];
                    if(y>=0 && y<n && x>=0 && x<m && matrix[y][x]==1 && res[y][x]==0){
                        q.push(make_pair(y,x));
                        res[y][x]=1;
                    }
                 }
    int dis=2;
    while(!q.empty()){
        int k=q.size();
        for(int l=0;l<k;l++){
            for(int p=0;p<4;p++){
                int y=q.front().first+pos[p], x=q.front().second+pos[p+1];
                //更新大的，和没有visit的
                if(y>=0 && y<n && x>=0 && x<m && matrix[y][x]==1 && (res[y][x]==0||res[y][x]>dis)){
                    q.push(make_pair(y,x));
                    res[y][x]=dis;
                }
            }
            q.pop();
        }
        dis++;
    }
    return res;
}
