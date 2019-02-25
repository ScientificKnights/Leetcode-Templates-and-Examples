/*
Given two strings s1, s2, find the lowest ASCII sum of deleted characters to make two strings equal.
Example 2:
Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d]+101[e]+101[e] to the sum.  Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
*/

int minimumDeleteSum(string s1, string s2) {
    /*
        l   e       e           t
    d   dl  dle     dlee        dleet
    e   dle dl      dle         dlet
    l   de  dll/dee deee/dlle   deeet/dllet
    */
    //相同72. Edit Distance
    //相同dp[i][j]=dp[i-1][j-1]
    //不同 从另两个位置过来
    int n=s1.size(),m=s2.size();
    vector<vector<int>> dp(n,vector<int>(m,0));
    bool equal=true;
    if(s1[0]!=s2[0]) {dp[0][0]=s1[0]+s2[0]; equal=false;}

    for(int i=1;i<m;i++){
        if(s1[0]==s2[i] && equal==false) {dp[0][i]=dp[0][i-1]-s1[0]; equal=true;}
        else dp[0][i]=dp[0][i-1]+s2[i];
    }

    equal=(s1[0]==s2[0]);
    for(int i=1;i<n;i++){
        if(s2[0]==s1[i] && equal==false) {dp[i][0]=dp[i-1][0]-s2[0]; equal=true;}
        else dp[i][0]=dp[i-1][0]+s1[i];
    }

    for(int i=1;i<n;i++)
        for(int j=1;j<m;j++){
            if(s1[i]==s2[j])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=min(dp[i-1][j]+s1[i],dp[i][j-1]+s2[j]);
        }
    return dp[n-1][m-1];
}
