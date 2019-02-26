/*
Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, 
where in each step you can delete one character in either string.

Example 1:
Input: "sea", "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
*/
int minDistance(string word1, string word2) {
    //dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1; 在这种情况不需要2d,只需要两个vector
    int n=word1.size(),m=word2.size();
    if(n==0 || m==0) return m+n;
    vector<int> prev(m+1,0);
    vector<int> cur(m+1,0);
    
    //初始化第一行
    for(int i=0;i<m+1;i++)
        prev[i]=i;

    for(int i=1;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(j==0)  //初始化第一列
                cur[j]=i;
            else{
                if(word1[i-1]==word2[j-1]) cur[j]=prev[j-1];
                else cur[j]=min(prev[j],cur[j-1])+1;
            }
        }
        prev=cur;
    }
    return prev[m];
}
