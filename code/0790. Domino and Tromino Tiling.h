/*
We have two types of tiles: a 2x1 domino shape, and an "L" tromino shape. These shapes may be rotated.
XX  <- domino

XX  <- "L" tromino
X
Given N, how many ways are there to tile a 2 x N board? Return your answer modulo 10^9 + 7.
(In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells
on the board such that exactly one of the tilings has both squares occupied by a tile.)

Example:
Input: 3
Output: 5
Explanation: 
The five different ways are listed below, different letters indicates different tiles:
XYZ XXZ XYY XXY XYY
XYZ YYZ XZZ XYY XXY
*/

int numTilings(int N) {
    //half fill and fill state
    //0 1 1 
    //0 0 2
    if(N<=2) return N;
    vector<vector<long>> dp(2,vector<long>(N+1,0));
    dp[0][1]=1;dp[0][2]=2;
    dp[1][2]=2; //2nd col half filled
    for(int i=3;i<N+1;i++){
        dp[0][i]=(dp[0][i-1]+dp[1][i-1]+dp[0][i-2])%1000000007;
        dp[1][i]=(dp[1][i-1]+2*dp[0][i-2])%1000000007;
    }
    return dp[0][N];
}
