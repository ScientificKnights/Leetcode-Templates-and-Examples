/*
Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. 
Write an algorithm to minimize the largest sum among these m subarrays.

Note:
If n is the length of array, assume the following constraints are satisfied:

1 ≤ n ≤ 1000
1 ≤ m ≤ min(50, n)
Examples:

Input:
nums = [7,2,5,10,8]
m = 2

Output:
18
*/

class Solution {
public:
    bool possible(vector<int>& nums,long long target,int cuts){
        //应该可以更快 如果用binary search, 内存存sum
        long long sum=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum > target){
                count++;
                if(count>cuts) return false;
                sum=nums[i];
            }
        }
        return (count<cuts)?true:false;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        vector<long long> sum(n,nums[0]);
        long long left=nums[0];
        for(int i=1;i<n;i++){
            sum[i]=sum[i-1]+nums[i];
            left=max(left,(long long)nums[i]);
        }
        if(m==1) return (int)sum[n-1];
        
        left=max(sum[n-1]/m,left);
 
        long long right=sum[n-1],mid;
        
        while(left<right){
            mid=(left+right)/2;
            if(possible(nums,mid,m))
                right=mid;
            else
                left=mid+1;
        }
        return (int)left;
    }
};
