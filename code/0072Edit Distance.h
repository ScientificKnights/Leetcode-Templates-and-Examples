/*
Share
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
You have the following 3 operations permitted on a word:
Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
*/

int minDistance(string word1, string word2) {
    int n=word1.size(),m=word2.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i=0;i<m+1;i++)
        dp[0][i]=i;

    for(int i=0;i<n+1;i++)
        dp[i][0]=i;

    for(int i=1;i<n+1;i++)
        for(int j=1;j<m+1;j++){
            if(word1[i-1]==word2[j-1])
                //相同，直接和之前一样
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=min(dp[i-1][j]+1,min(dp[i][j-1]+1,dp[i-1][j-1]+1)); //删或者换
        }

    return dp[n][m];
}
