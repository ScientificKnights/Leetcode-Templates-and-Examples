/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
*/

int subarraySum(vector<int>& nums, int k) {
    //可以是负数，不能two pointer
    //在hash map 找 sum-k
    int sum=0,res=0;

    unordered_map<int, int> data;
    //data[0]=1; //从第一个开始
    for(auto i:nums){
        sum+=i;
        if(sum==k)  //或者开始加入0
            res++;
        if(data.count(sum-k))
            res+=data[sum-k];
        data[sum]++;
    }
    return res;
}
