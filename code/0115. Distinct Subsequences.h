/*
Given a string S and a string T, count the number of distinct subsequences of S which equals T.
A subsequence of a string is a new string which is formed from the original string 
by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. 
(ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
*/

int numDistinct(string s, string t) {
    //    babgbag
    //b   1 1 1
    //a    1   3 
    //g      1  4
    int m=s.size(),n=t.size();
    if(m==0 || n==0) return 0;
    vector<vector<long>> dp(n+1,vector<long>(m+1,0));
    for(int i=1;i<n+1;i++){
        int count=((i==1)?1:0);
        for(int j=1;j<m+1;j++){
            if(s[j-1]==t[i-1])
                dp[i][j]=count;
            count+=dp[i-1][j];
        }
    }
    int res=0;
    for(int i=1;i<m+1;i++)
        res+=dp[n][i];
    return res;
}
