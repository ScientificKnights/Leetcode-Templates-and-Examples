/*
On a 2x3 board, there are 5 tiles represented by the integers 1 through 5, and an empty square represented by 0.
A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.
The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].
Given a puzzle board, return the least number of moves required so that the state of the board is solved. 
If it is impossible for the state of the board to be solved, return -1.

Input: board = [[1,2,3],[4,0,5]]
Output: 1
Explanation: Swap the 0 and the 5 in one move.
Input: board = [[1,2,3],[5,4,0]]
Output: -1
Explanation: No number of moves will make the board solved.
Input: board = [[4,1,2],[5,0,3]]
Output: 5
Explanation: 5 is the smallest number of moves that solves the board.
An example path:
After move 0: [[4,1,2],[5,0,3]]
After move 1: [[4,1,2],[0,5,3]]
After move 2: [[0,1,2],[4,5,3]]
After move 3: [[1,0,2],[4,5,3]]
After move 4: [[1,2,0],[4,5,3]]
After move 5: [[1,2,3],[4,5,0]]
*/

class Solution {
private:
    pair<int,int> find0(vector<vector<int>>& path){     //position r,c of 0
        for(int r=0;r<2;r++)
            for(int c=0;c<3;c++)
                if(!path[r][c])
                    return {r,c};
        return {-1,-1};
    }
    bool find(unordered_set<int> &visited, vector<vector<int>>& path){
        //find return true, not find, add to visited and return false;
        int num=path[1][2]+10*path[1][1]+100*path[1][0]+1000*path[0][2]+10000*path[0][1]+100000*path[0][0];
        bool res=visited.count(num);
        visited.insert(num);
        return res;
    }
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        //bfs
        int level=0;
        vector<vector<int>> tofind={{1,2,3},{4,5,0}};
        queue<vector<vector<int>>> q;
        vector<int> pos={1,0,-1,0,1};
        unordered_set<int> visited;
        find(visited,board);
        q.push(board);
        while(!q.empty()){
            int k=q.size();
            for(int i=0;i<k;i++){
                vector<vector<int>> cur=q.front();
                q.pop();
                if(cur==tofind) return level;
                pair<int,int> p=find0(cur);
                int r=p.first,c=p.second;
                for(int j=0;j<4;j++){
                    int x=r+pos[j],y=c+pos[j+1];
                    if(x>=0 && x<2 && y>=0 &&y<3){
                        swap(cur[r][c],cur[x][y]);
                        if(!find(visited,cur))
                            q.push(cur);
                        swap(cur[r][c],cur[x][y]);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
