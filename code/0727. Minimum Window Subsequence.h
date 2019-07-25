/*
Given strings S and T, find the minimum (contiguous) substring W of S, so that T is a subsequence of W.

If there is no such window in S that covers all characters in T, return the empty string "". 
If there are multiple such minimum-length windows, return the one with the left-most starting index.

Input: 
S = "abcdebdde", T = "bde"
Output: "bcde"

Note:
All the strings in the input will only contain lowercase letters.
The length of S will be in the range [1, 20000].
The length of T will be in the range [1, 100].
*/
string minWindow(string S, string T) {
    //  dbcdebde
    // 012345678
    //bxx1111555
    //dxxxx11155
    //exxxxx1115
    int n=S.size(),m=T.size(),res=INT_MAX;
    string s="";
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    for(int i=0;i<n+1;i++) dp[0][i]=i;
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(S[j-1]==T[i-1]) {
                dp[i][j]=dp[i-1][j-1];
                if(i==m && dp[i][j]!=-1 &&j-dp[i][j]<res) {
                    res=j-dp[i][j];
                    s=S.substr(dp[i][j],res);
                }
            }
            else
                dp[i][j]=dp[i][j-1];
        }
    }
    return s;
}
