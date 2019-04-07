/*
On an N x N board, the numbers from 1 to N*N are written boustrophedonically starting from the bottom left of the board, 
and alternating direction each row.  For example, for a 6 x 6 board, the numbers are written as follows:
https://assets.leetcode.com/uploads/2018/09/23/snakes.png

You start on square 1 of the board (which is always in the last row and first column).  Each move, starting from square x, 
consists of the following:
You choose a destination square S with number x+1, x+2, x+3, x+4, x+5, or x+6, provided this number is <= N*N.
(This choice simulates the result of a standard 6-sided die roll: ie., there are always at most 6 destinations.)
If S has a snake or ladder, you move to the destination of that snake or ladder.  Otherwise, you move to S.
A board square on row r and column c has a "snake or ladder" if board[r][c] != -1.  The destination of that snake or ladder is board[r][c].

Note that you only take a snake or ladder at most once per move: 
if the destination to a snake or ladder is the start of another snake or ladder, you do not continue moving.  
(For example, if the board is `[[4,-1],[-1,3]]`, and on the first move your destination square is `2`, 
then you finish your first move at `3`, because you do not continue moving to `4`.)

Return the least number of moves required to reach square N*N.  If it is not possible, return -1.

Input: [
[-1,-1,-1,-1,-1,-1],
[-1,-1,-1,-1,-1,-1],
[-1,-1,-1,-1,-1,-1],
[-1,35,-1,-1,13,-1],
[-1,-1,-1,-1,-1,-1],
[-1,15,-1,-1,-1,-1]]
Output: 4
*/

class Solution {
private:
    int getpos(vector<vector<int>>& board, int N,int p){
        int r=N-1-(p-1)/N;
        int c= ((p-1)/N%2)? (N-1)-(p-1)%N : (p-1)%N;
        int res=(board[r][c]==-1)?p:board[r][c];
        board[r][c]=0;
        return res;
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size(),m=board[0].size(),res=0;
        queue<int> q;
        q.push(getpos(board,n,1));
        while(!q.empty()){
            int k=q.size();
            for(int num=0;num<k;num++){
                int cur=q.front();
                if(cur==(n*n)) return res;
                q.pop();
                for(int i=1;i<=6 && cur+i<=n*n ;i++){
                    int next=getpos(board,n,cur+i);
                    if(next){
                        q.push(next);
                    }
                }
            }
            res++;
        }
        return -1;
    }
};
