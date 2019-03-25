/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
    
Note:
You can assume that you can always reach the last index.
*/

int jump(vector<int>& nums) {
    //greedy
    int n=nums.size();
    if(n<=1) return 0;
    int end=0,jump=0,next_end=0;
    for(int i=0;i<n;i++){
        next_end=max(next_end,i+nums[i]);
        if(next_end>=n-1) return jump+1;
        if(i==end){
            jump++;
            end=next_end;
        }
    }
    return jump;
}
