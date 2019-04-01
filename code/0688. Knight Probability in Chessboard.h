/*
On an NxN chessboard, a knight starts at the r-th row and c-th column and attempts to make exactly K moves. 
The rows and columns are 0 indexed, so the top-left square is (0, 0), and the bottom-right square is (N-1, N-1).

A chess knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, 
then one square in an orthogonal direction.

Each time the knight is to move, it chooses one of eight possible moves uniformly at random 
(even if the piece would go off the chessboard) and moves there.

The knight continues moving until it has made exactly K moves or has moved off the chessboard. 
Return the probability that the knight remains on the board after it has stopped moving.
*/

double knightProbability(int N, int K, int r, int c) {
    //dp: N*N*8*K
    //recursive 8^K
    vector<vector<double>> dp(N,vector<double>(N,0.0));
    dp[r][c]=1.0;
    vector<vector<int>> pos={{2,-1},{2,1},{-2,1},{-2,-1},{1,-2},{1,2},{-1,2},{-1,-2}};
    for(int i=0;i<K;i++){
        vector<vector<double>> next(N,vector<double>(N,0.0));
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                if(dp[j][k]>0.0){
                    for(auto i:pos){
                        int row=j+i[0];
                        int col=k+i[1];
                        if(row>=0 && row<N && col>=0 && col<N)
                            next[row][col]+=0.125*dp[j][k];
                    }
                }
            }
        }
        dp=next;
    }
    double res=0.0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            res+=dp[i][j];
    return res;
}
