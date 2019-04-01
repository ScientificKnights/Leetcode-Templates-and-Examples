/*
We partition a row of numbers A into at most K adjacent (non-empty) groups, then our score is the sum of the average of each group. 
What is the largest score we can achieve?
Note that our partition must use every number in A, and that scores are not necessarily integers.

A = [9,1,2,3,9]
K = 3
Output: 20
Explanation: 
The best choice is to partition A into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
We could have also partitioned A into [9, 1], [2], [3, 9], for example.
That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.
*/
double largestSumOfAverages(vector<int>& A, int K) {
    //dp[k][n] A 中0到n分成K份
    int n=A.size();
    vector<double> sum(n,A[0]*1.0);
    for(int i=1;i<n;i++)
        sum[i]=sum[i-1]+A[i];
    vector<vector<double>> dp(K+1,vector<double>(n,INT_MIN*1.0));
    for(int i=0;i<n;i++)
        dp[1][i]=sum[i]/(i+1);
    for(int i=2;i<K+1;i++){
        for(int j=i-1;j<n;j++){
            for(int k=i-2;k<j;k++)
                dp[i][j]=max(dp[i][j],dp[i-1][k]+(sum[j]-sum[k])/(j-k));
        }
    }
    return dp[K][n-1];
}
