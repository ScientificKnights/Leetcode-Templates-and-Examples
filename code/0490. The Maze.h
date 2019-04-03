/*
There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, 
but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.
Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.
The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. 
You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.

Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (4, 4)
Output: true
Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.
*/

bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
    int n=maze.size();
    int m=maze[0].size();
    queue<pair<int,int>> q;
    vector<int> dirs={1,0,-1,0,1};
    q.push(make_pair(start[0],start[1]));
    maze[destination[0]][destination[1]]=2;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        maze[x][y]=-1;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=dirs[i]+x, ny=dirs[i+1]+y;
            while(nx>=0 && nx<n && ny>=0 && ny<m && maze[nx][ny]!=1){
                nx+=dirs[i];
                ny+=dirs[i+1];
            }
            nx-=dirs[i];ny-=dirs[i+1];
            if(maze[nx][ny]!=-1){
                if(maze[nx][ny]==2) return true;
                q.push(make_pair(nx,ny));
            }
        }
    }
    return false;
}
