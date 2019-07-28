/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

int threeSumClosest(vector<int>& nums, int target) {
    int result;
    int closest=INT_MAX;        //record gap
    int n=nums.size();
    if (n<3)
        return result;
    sort(nums.begin(),nums.end());

    for (int i=0;i<n-2;i++){
        //重复去掉
        if(i>0 && nums[i]==nums[i-1]) continue;

        int goal=target-nums[i],start=i+1,end=n-1,gap;
        while(start<end){
            gap=abs(target-nums[start]-nums[end]-nums[i]);
            if(gap<closest){
                result=nums[start]+nums[end]+nums[i];
                closest=gap;
            }
            if((nums[start]+nums[end])<goal)
                start++;
            else if((nums[start]+nums[end])>goal)
                end--;
            else
                return target;
        }

    }
    return result;
}
