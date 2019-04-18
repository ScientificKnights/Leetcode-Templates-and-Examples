/*
Given an array A of integers, return the length of the longest arithmetic subsequence in A.
Recall that a subsequence of A is a list A[i_1], A[i_2], ..., A[i_k] with 0 <= i_1 < i_2 < ... < i_k <= A.length - 1, 
and that a sequence B is arithmetic if B[i+1] - B[i] are all the same value (for 0 <= i < B.length - 1).

Input: [3,6,9,12]
Output: 4

Input: [9,4,7,2,10]
Output: 3
[4,7,10]

Input: [20,1,15,3,10,5,8]
Output: 4
The longest arithmetic subsequence is [20,15,10,5].
*/

int longestArithSeqLength(vector<int>& A) {
    int n=A.size();
    if(!n) return 0;
    int res=1;
    vector<unordered_map<int,int>> dp(n);
    dp[0][0]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            dp[i][A[i]-A[j]]=(dp[j].count(A[i]-A[j]))?(dp[j][A[i]-A[j]]+1):2;
            res=max(res,dp[i][A[i]-A[j]]);
        }
    }
    return res;
}
