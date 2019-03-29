/*
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. 
For each integer, you should choose one from + and - as its new symbol.
Find out how many ways to assign symbols to make sum of integers equal to target S.

Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
*/

class Solution {
public:
    
    int findTargetSumWays(vector<int>& nums, int S) {
        //dp, 利用 sum smaller than 1000
        //-1000 0       1000
        //0     1000    2000
        //每次扫描2000中不是0的
        //2000*N
        
        if(S>1000) return 0;
        int n=nums.size();
        vector<int> data(2001,0);
        data[nums[0]+1000]++;
        data[(-1)*nums[0]+1000]++;
        for(int i=1;i<n;i++){
            vector<int> data_cur(2001,0);
            for(int j=0;j<2001;j++){
                if(data[j]!=0){
                    data_cur[j+nums[i]]+=data[j];
                    data_cur[j+(-1)*nums[i]]+=data[j];
                }
            }
            data=data_cur;
        }
        return data[S+1000];
        
    }   
    
    /*n*(2^n)
    int helper(vector<int>& nums,int S,int pos){
        int n=nums.size();
        if(pos==n-1) {
            if(nums[pos]==0 && S==0) return 2;
            if(nums[pos]==S || nums[pos]==S*(-1)) return 1;
            return 0;
        }
        return helper(nums,S-nums[pos],pos+1)+helper(nums,S+nums[pos],pos+1);
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        return helper(nums,S,0);
    }
    */
};
