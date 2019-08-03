/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

The solution set must not contain duplicate quadruplets.

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n=nums.size();
    vector<vector<int>> res;
    if(n<=3) return res;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n-3;i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j=i+1;j<n-2;j++){
            if(j>i+1 && nums[j]==nums[j-1]) continue;
            int left=j+1;
            int right=n-1;
            int sub_target=target-nums[i]-nums[j];
            while(left<right){
                if(nums[left]+nums[right]>sub_target) right--;
                else if(nums[left]+nums[right]<sub_target) left++;
                else{
                    res.push_back({nums[i],nums[j],nums[left],nums[right]});
                    do{left++;}
                    while(left<right && nums[left]==nums[left-1]);
                    do{right--;}
                    while(left<right && nums[right]==nums[right+1]);
                }
            }
        }
    }
    return res;
}
