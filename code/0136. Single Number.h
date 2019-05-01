/*
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
*/

int singleNumber(vector<int>& nums) 
{
    int res=0;
    for(auto i:nums)
        res^=i;
    return res;
}
