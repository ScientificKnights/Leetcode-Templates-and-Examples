/*
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. 
You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. 
Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:

You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
Example:
Input: [3,1,5,8]
Output: 167 
Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
             coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
*/

int maxCoins(vector<int>& nums) {
    /*
    1   3   1   5   8   1
    ---------------------
    0   0   0   0   0   0
    0   3   0   0   0   0
    0   0   15  0   0   0
    0   0   0   40  0   0
    0   0   0   0   40  0
    0   0   0   0   0   0
    ---------------------
        3   3+5,15+15
            15  15+120,40+24
                40  40+8,40+5
                    40       
    ---------------------
        3   30  1*3*8+135, 1*1*8+3+40,30+1*5*8
            15  135 48+3*1*1, 15+40+3*5*1, 135+3*8*1
                40  48
                    40         
    ---------------------
        3   30  159 159+1*8*1
            15  135 159
                40  48
                    40            
    */
        int n=nums.size();
        vector<int> data(1,1);
        for(auto i:nums)
            if(i!=0)
                data.push_back(i);
        data.push_back(1);
        n=data.size();

        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int right=1;right<n-1;right++){
            for(int left=right;left>=1;left--){
                for(int k=left;k<=right;k++){
                    // dp[left][right]从 left 到 right都出去后得到的值，k是最后一步的数值。
                    dp[left][right]=max(dp[left][right],data[left-1]*data[k]*data[right+1]+dp[left][k-1]+dp[k+1][right]);
                }

            }
        }
        return dp[1][n-2];
        
    }
