/*
Alex and Lee play a game with piles of stones.  There are an even number of piles arranged in a row, 
and each pile has a positive integer number of stones piles[i].

The objective of the game is to end with the most stones.  The total number of stones is odd, so there are no ties.

Alex and Lee take turns, with Alex starting first.  
Each turn, a player takes the entire pile of stones from either the beginning or the end of the row.  
This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alex and Lee play optimally, return True if and only if Alex wins the game.
*/

bool stoneGame(vector<int>& piles) {
    /*
    return true; //Alex can choose all odd or all even;
    */
    int n=piles.size();
    //dp是score的差值
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
        dp[i][i]=piles[i];
    for(int i=1;i<n;i++)
        for(int j=0;j<n-i;j++)
            //row:j, col: j+i
            //序列少一个，另一个人先开始，所以减
            dp[j][i+j]=max(piles[j]-dp[j+1][i+j],piles[i+j]-dp[j][i+j-1]);
    return dp[0][n-1]>0;
}
