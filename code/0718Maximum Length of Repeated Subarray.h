/*
Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:
Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation: 
The repeated subarray with maximum length is [3, 2, 1].
*/
int findLength(vector<int>& A, vector<int>& B) {
    //dp,dp[i+1][j+1]=dp[i][j]+1;
    //must be continuous, because 0 if not equal
    int n=A.size(),m=B.size();
    int res=0;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(A[i]==B[j]){
                dp[i+1][j+1]=dp[i][j]+1;
                res=max(res,dp[i+1][j+1]);
            }
        }
    return res;
}
