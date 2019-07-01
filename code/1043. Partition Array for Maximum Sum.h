/*
Given an integer array A, you partition the array into (contiguous) subarrays of length at most K.  
After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning.

Input: A = [1,15,7,9,2,5,10], K = 3
Output: 84
*/

int maxSumAfterPartitioning(vector<int>& A, int K) {
    int n=A.size();
    vector<int> dp(n,0);
    for(int i=0;i<n;i++){
        int ma=0;
        for(int j=1;j<=K && i+1-j>=0;j++){
            ma=max(ma,A[i+1-j]);
            dp[i]=max(dp[i], ((i-j<0)?0:dp[i-j])+ma*j);
        }
    }
    return dp[n-1];
}
