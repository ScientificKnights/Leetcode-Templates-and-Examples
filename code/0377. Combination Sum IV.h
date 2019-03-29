/*
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations 
that add up to a positive integer target.

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
*/

int combinationSum4(vector<int>& nums, int target)     {
    int n=nums.size();
    vector<unsigned int> dp(target+1,0);
    dp[0]=1;
    for(int i=1;i<target+1;i++)
        for(int j=0;j<n;j++)
            if(i>=nums[j])
                dp[i]+=dp[i-nums[j]];
    return dp[target];
}
