/*
Given a non-empty array containing only positive integers, 
find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Each of the array element will not exceed 100.
The array size will not exceed 200.

Input: [1, 5, 11, 5]
Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
*/

bool canPartition(vector<int>& nums) {
    //2^N > sum*N dfs 超时
    int sum=0;
    for(auto i:nums)
        sum+=i;
    if(sum%2==1) return false;
    sum/=2;
    vector<bool> dp(sum+1,false);
    dp[0]=true;
    for(auto i:nums){
        //从后往前**************
        for(int j=sum-i;j>=0;j--)
            if(dp[j])
                dp[j+i]=true;
        if(dp[sum]) return true;
    }
    return dp[sum];
}
