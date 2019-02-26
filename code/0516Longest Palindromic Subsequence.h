/*
Given a string s, find the longest palindromic subsequence's length in s. 
You may assume that the maximum length of s is 1000.
Example 1:
Input:
"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
*/

int longestPalindromeSubseq(string s) {
    //可以不是连续的
    int n=s.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1,0));
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(s[i-1]!=s[s.size()-j])
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            else
                dp[i][j]=max(max(dp[i-1][j-1]+1,dp[i-1][j]),dp[i][j-1]);
        }
    }
    return dp[n][n];
}
