/*
Given an array nums of integers, you can perform operations on the array.
In each operation, you pick any nums[i] and delete it to earn nums[i] points. 
After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.

You start with 0 points. Return the maximum number of points you can earn by applying such operations.

Input: nums = [3, 4, 2]
Output: 6
Explanation: 
Delete 4 to earn 4 points, consequently 3 is also deleted.
Then, delete 2 to earn 2 points. 6 total points are earned.
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        //错了，是must not delete any
        int n=nums.size();
        vector<int> result(n);
        result[1]=nums[1];
        result[2]=max(nums[1],nums[2]);
        for(int i=3;i<n;i++){
            //include current or not; two cases if included
            result[i]=max(max(result[i-2],result[i-3])+nums[i], result[i-1]);
        }
        return result[n-1];
    }
    int deleteAndEarn(vector<int>& nums) {
        vector<int> sum(10001,0);
        for(auto i:nums)
            sum[i]+=i;
        return rob(sum);
    }
};
