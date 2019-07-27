/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

The solution set must not contain duplicate triplets.

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    int n=nums.size();
    if (n<3)
        return result;
    sort(nums.begin(),nums.end());

    for (int i=0;i<n-2;i++){
        //重复去掉
        if(i>0 && nums[i]==nums[i-1]) continue;

        int target=0-nums[i], start=i+1, end=n-1;
        while(start<end){
            if((nums[start]+nums[end])<target)
                start++;
            else if((nums[start]+nums[end])>target)
                end--;
            else{
                result.push_back({nums[i],nums[start],nums[end]});
                //重复去掉
                while(start+1<n && nums[start]==nums[start+1])
                    start++;
                start++;
            }
        }

    }
    return result;
}
