/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/

bool canJump(vector<int>& nums) {
    int n=nums.size();
    int maxindex=nums[0];
    for(int i=0;i<=min(n-1,maxindex);i++){
        maxindex=max(maxindex,i+nums[i]);
    }
    return (maxindex>=n-1);
}
