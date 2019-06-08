/*
This question is about implementing a basic elimination algorithm for Candy Crush.

Given a 2D integer array board representing the grid of candy, 
different positive integers board[i][j] represent different types of candies. 
A value of board[i][j] = 0 represents that the cell at position (i, j) is empty. 
The given board represents the state of the game following the player's move. Now, 
you need to restore the board to a stable state by crushing candies according to the following rules:

If three or more candies of the same type are adjacent vertically or horizontally, 
"crush" them all at the same time - these positions become empty.

After crushing all candies simultaneously, if an empty space on the board has candies on top of itself, 
then these candies will drop until they hit a candy or bottom at the same time. (No new candies will drop outside the top boundary.)

After the above steps, there may exist more candies that can be crushed. If so, you need to repeat the above steps.
If there does not exist more candies that can be crushed (ie. the board is stable), then return the current board.
You need to perform the above rules until the board becomes stable, then return the current board.
*/

class Solution {
private:
    void flood(vector<vector<int>>& board,int row, int col, int r_dir, int c_dir){
        int n=board.size(),m=board[0].size();
        int val=board[row][col]%4000;
        while( row>=0 && col<m && board[row][col]%4000==val) {
            (board[row][col]%=4000)+=4000;
            row+=r_dir,col+=c_dir;
        }
        return;
    }
    bool dfs(vector<vector<int>>& board){
        int n=board.size(),m=board[0].size();
        bool flag=false;
        for(int i=n-1;i>=0;i--)
            for(int j=0;j<m;j++){
                if(board[i][j]){
                    int val=board[i][j]%4000;
                    if(i>=1 && (board[i-1][j]%4000 ==val ) && i+1<n && (board[i+1][j]%4000==val ) ){
                        flood(board,i+1,j,-1,0);
                        flag=true;
                    }
                    if( j>=1 && board[i][j-1]%4000==val && j+1<m && board[i][j+1]%4000==val){
                        flood(board,i,j-1,0,1);
                        flag=true;
                    }
                }
            }
        return flag;
    }
    void movedown(vector<vector<int>>& board){
        int n=board.size(),m=board[0].size();
        for(int i=0;i<m;i++){
            int start=n-1,end=n-2;
            while(end>=0){
                while(start>=0 && board[start][i]>0 && board[start][i]<=4000) start--;
                end=start-1;
                while(end>=0 && (board[end][i]==0 || board[end][i]>4000)) end--;
                if(end>=0){
                    board[start][i]=board[end][i];
                    board[end][i]=0;
                    start--,end--;
                }
            }
            while(start>=0) board[start--][i]=0;
        }
        
        return;
    }
    void print(vector<vector<int>>& board){
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        return;
    }
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        bool flag=false;     //3 same exist
        flag=dfs(board);
        //print(board);
        while(flag){
            movedown(board);
            flag=false;
            flag=dfs(board);
            //print(board);
        }
        return board;
    }
};
