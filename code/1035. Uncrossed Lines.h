/*
We write the integers of A and B (in the order they are given) on two separate horizontal lines.
Now, we may draw a straight line connecting two numbers A[i] and B[j] as long as A[i] == B[j], 
and the line we draw does not intersect any other connecting (non-horizontal) line.

Return the maximum number of connecting lines we can draw in this way.

Input: A = [1,4,2], B = [1,2,4]
Output: 2

Input: A = [2,5,1,2,5], B = [10,5,2,1,5,2]
Output: 3

Input: A = [1,3,7,1,7,5], B = [1,9,2,5,1]
Output: 2
*/

int maxUncrossedLines(vector<int>& A, vector<int>& B) {
    int n=A.size(),m=B.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(A[i]==B[j])
                //dp[i+1][j+1]=max(max(dp[i][j+1],dp[i+1][j]),dp[i][j]+1);
                dp[i+1][j+1]=dp[i][j]+1;
            else
                dp[i+1][j+1]=max(max(dp[i][j+1],dp[i+1][j]),dp[i][j]);
        }
    return dp[n][m];
}
