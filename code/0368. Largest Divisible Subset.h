/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:
Si % Sj = 0 or Sj % Si = 0.
If there are multiple solutions, return any subset is fine.
*/

vector<int> largestDivisibleSubset(vector<int>& nums) {
    //dp 存set个数，dp存截至该元素set最大的数目，整数倍前面值时update
    sort(nums.begin(),nums.end());
    int n=nums.size();
    vector<int> res;
    if(n==0) return res;
    int max_element=0,max_count=1;

    vector<int> path(n,-1);
    vector<int> dp(n,1);
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(nums[i]%nums[j]==0 && dp[j]+1>dp[i]){
                dp[i]=dp[j]+1;
                path[i]=j;
            }
        }
        if(dp[i]>max_count){
            max_count=dp[i];max_element=i;
        }
    }
    for(int i=max_element;i>=0;){
        res.push_back(nums[i]);
        i=path[i];
    }
    return res;
}
