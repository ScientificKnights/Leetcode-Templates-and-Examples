/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Input: [3,0,1]
Output: 2
Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/

int missingNumber(vector<int>& nums) {
    int n=nums.size(),res=0;
    for(int i=0;i<n;i++){
        res^=i;
        res^=nums[i];
    }
    return res^n;
}

/*
int missingNumber(vector<int>& nums) {
    int n=nums.size();
    int sum=0;
    for(auto i:nums)
        sum+=i;
    return n*(n+1)/2-sum;
}
*/
