/*
Given a string S, find out the length of the longest repeating substring(s). Return 0 if no repeating substring exists.

Input: "abcd"
Output: 0

Input: "abbaba"
Output: 2

Input: "aabcaabdaab"
Output: 3
Explanation: The longest repeating substring is "aab", which occurs 3 times.

Input: "aaaaa"
Output: 4

The string S consists of only lowercase English letters from 'a' - 'z'.
1 <= S.length <= 1500
*/

//dp N^2
int longestRepeatingSubstring(string S) {
    int n=S.size(),res=0;
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(S[i-1]==S[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                res=max(res,dp[i][j]);
            }
        }
    }
    return res;
}
