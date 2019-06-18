/*
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences.  
If multiple answers exist, you may return any of them.

(A string S is a subsequence of string T if deleting some number of characters from T 
(possibly 0, and the characters are chosen anywhere from T) results in the string S.)

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
*/

string shortestCommonSupersequence(string str1, string str2) {
    int n=str1.size(),m=str2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(str1[i]==str2[j])
                dp[i+1][j+1]=max(max(dp[i][j]+1,dp[i][j+1]),dp[i+1][j]);
            else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
        }
    }

    string res="";
    int i=n,j=m;
    for( ; i>0 || j>0;){
        if(i>0 && dp[i][j]==dp[i-1][j]){
            res+=str1[i-1];
            i--;
        }
        else if(j>0 && dp[i][j]==dp[i][j-1]){
            res+=str2[j-1];
            j--;
        }
        else{
            res+=str2[j-1];
            i--;j--;
        }
    }

    reverse(res.begin(),res.end());
    return res;
}
