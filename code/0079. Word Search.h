/*
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or 
vertically neighboring. The same letter cell may not be used more than once.

board = [  ['A','B','C','E'],
           ['S','F','C','S'],
           ['A','D','E','E'] ]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/
bool backtrack(vector<vector<char>>& board, string & word, int row,int col,int pos){
    if(word[pos]!=board[row][col]) return false;
    if(pos==word.size()-1)
        return true;
        
    int n=board.size(),m=board[0].size();
    char cur=board[row][col];
    board[row][col]='*';
    vector<vector<int>> direction={{1,0},{-1,0},{0,1},{0,-1}};
    for(auto i:direction){
        int x=row+i[0],y=col+i[1];
        if(x>=0 && x<n && y>=0 && y<m && backtrack(board,word,x,y,pos+1))
            return true;
    }
    board[row][col]=cur;        //backtrack
    return false;

}
bool exist(vector<vector<char>>& board, string word) {
    for(int i=0;i<board.size();i++)
        for(int j=0;j<board[0].size();j++)
            if(backtrack(board,word,i,j,0))
                return true;
    return false;
}
