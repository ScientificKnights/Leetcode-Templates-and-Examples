/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. 
All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, 
adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were 
broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of 
money you can rob tonight without alerting the police.
*/
int rob(vector<int>& nums) {
    //公式dp1[i]=max(dp1[i-1],max(dp1[i-2],dp1[i-3])+nums[i])
    //two cases: [0]chosen; [0] not chosen;
    int n=nums.size();
    if(n==0) return 0;
    if(n==1) return nums[0];
    if(n==2) return max(nums[0],nums[1]);
    if(n==3) return max(max(nums[0],nums[1]),nums[2]);

    vector<int> dp1(n),dp2(n);
    //dp1 有nums[0],dp2 无
    dp1[0]=nums[0];
    dp1[1]=nums[0];
    dp1[2]=nums[0]+nums[2];
    dp2[1]=nums[1];
    dp2[2]=max(nums[1],nums[2]);

    for(int i=3;i<n-1;i++){
        dp1[i]=max(dp1[i-1],max(dp1[i-2],dp1[i-3])+nums[i]);
        dp2[i]=max(dp2[i-1],max(dp2[i-2],dp2[i-3])+nums[i]);
    }
    //dp1 无[n-1] dp2 有
    dp2[n-1]=max(dp2[n-2],max(dp2[n-3],dp2[n-4])+nums[n-1]);

    return max(max(dp1[n-2],dp1[n-3]),max(dp2[n-1],dp2[n-2]));
}
