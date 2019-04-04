/*
There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up (u), down (d), 
left (l) or right (r), but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction. 
There is also a hole in this maze. The ball will drop into the hole if it rolls on to the hole.

Given the ball position, the hole position and the maze, find out how the ball could drop into the hole by moving the shortest distance. 
The distance is defined by the number of empty spaces traveled by the ball from the start position (excluded) to the hole (included). 
Output the moving directions by using 'u', 'd', 'l' and 'r'. Since there could be several different shortest ways, 
you should output the lexicographically smallest way. If the ball cannot reach the hole, output "impossible".

The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. 
You may assume that the borders of the maze are all walls. The ball and the hole coordinates are represented by row and column indexes.

Input 1: a maze represented by a 2D array
0 0 0 0 0
1 1 0 0 1
0 0 0 0 0
0 1 0 0 1
0 1 0 0 0
Input 2: ball coordinate (rowBall, colBall) = (4, 3)
Input 3: hole coordinate (rowHole, colHole) = (0, 1)
Output: "lul"
*/
string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
    int n=maze.size(),m=maze[0].size(),res=INT_MAX;
    string res_path="z";
    queue<vector<int>> q;
    q.push(vector<int>{ball[0],ball[1]});
    unordered_map<int,unordered_map<int, string>> paths;    //save path to each stop
    maze[ball[0]][ball[1]]=-1;        //maze save distance
    paths[ball[0]][ball[1]]="";
    vector<int> dirs={1,0,-1,0,1};
    vector<char> turn={'d','l','u','r'};
    while(!q.empty()){
        int x=q.front()[0],y=q.front()[1],dist=(-1)*maze[x][y]-1;
        string path=paths[x][y];
        q.pop();
        for(int i=0;i<4;i++){
            int xx=x,yy=y;
            while(xx>=0 && xx<n && yy>=0 && yy<m && maze[xx][yy]!=1){
                if(xx==hole[0] && yy==hole[1]) 
                    break;
                xx+=dirs[i],yy+=dirs[i+1];
            }
            if(xx!=hole[0] || yy!=hole[1])
                xx-=dirs[i],yy-=dirs[i+1];
            int new_dist=dist+abs(xx-x)+abs(yy-y);
            string new_path=path+turn[i];
            if(new_dist<=res){
                if(xx==hole[0] && yy==hole[1]){
                    if(new_dist<res || (new_dist==res && new_path<res_path))
                    {res=new_dist; res_path=new_path;}
                }
                //revisit is ok if there is smaller distance
                else if(maze[xx][yy]==0 || (maze[xx][yy]<0 &&( (-1)*maze[xx][yy]-1>new_dist ||((-1)*maze[xx][yy]-1==new_dist && new_path<paths[xx][yy])))){
                    q.push(vector<int>{xx,yy});
                    maze[xx][yy]=-1-new_dist; 
                    paths[xx][yy]=new_path;
                }
            }
        }
    }
    return (res==INT_MAX)?"impossible":res_path;
}
