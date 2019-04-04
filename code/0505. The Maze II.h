/*
There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, 
but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.
Given the ball's start position, the destination and the maze, find the shortest distance for the ball to stop at the destination. 
The distance is defined by the number of empty spaces traveled by the ball from the start position(excluded) to the destination(included). 
If the ball cannot stop at the destination, return -1.

The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space.
You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.
*/

int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
    int n=maze.size(),m=maze[0].size(),res=INT_MAX;
    queue<vector<int>> q;
    q.push(vector<int>{start[0],start[1]});
    maze[start[0]][start[1]]=-1;        //maze save distance
    vector<int> dirs={1,0,-1,0,1};
    while(!q.empty()){
        int x=q.front()[0],y=q.front()[1],dist=(-1)*maze[x][y]-1;
        q.pop();
        for(int i=0;i<4;i++){
            int xx=x,yy=y;
            while(xx>=0 && xx<n && yy>=0 && yy<m && maze[xx][yy]!=1){
                xx+=dirs[i],yy+=dirs[i+1];
            }
            xx-=dirs[i],yy-=dirs[i+1];
            int new_dist=dist+abs(xx-x)+abs(yy-y);
            if(new_dist<res){
                if(xx==destination[0] && yy==destination[1])
                    res=new_dist;
                //revisit is ok if there is smaller distance
                else if(maze[xx][yy]==0 || (maze[xx][yy]<0 && (-1)*maze[xx][yy]-1>new_dist)){
                    q.push(vector<int>{xx,yy});
                    maze[xx][yy]=-1-new_dist; 
                }
            }
        }
    }
    return (res==INT_MAX)?-1:res;
}
