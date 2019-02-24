/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and 
it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money 
you can rob tonight without alerting the police.
*/

int rob(vector<int>& nums) {
    //sum[i]=max(sum[i-1], sum[i-2]+nums[i], sum[i-3]+nums[i])
    int n=nums.size();
    if(n==0)
        return 0;
    if(n==1)
        return nums[0];
    if(n==2)
        return max(nums[0],nums[1]);
    if(n==3)
        return max(nums[1],nums[0]+nums[2]);
    else{
        vector<int> result(n);
        result[0]=nums[0];
        result[1]=max(nums[0],nums[1]);
        result[2]=max(nums[1],nums[0]+nums[2]);
        for(int i=3;i<n;i++){
            //include current or not; two cases if included
            result[i]=max(max(result[i-2],result[i-3])+nums[i], result[i-1]);
        }
        return result[n-1];
    }
}

[House Robber II]()
