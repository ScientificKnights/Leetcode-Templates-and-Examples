/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. 
Find the two elements that appear only once.

Input:  [1,2,1,3,2,5]
Output: [3,5]

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/

vector<int> singleNumber(vector<int>& nums) {
    //a^b 不同的地方是 1
    int diff=0;
    for(auto i:nums)
        diff^=i;
    //1 0 1 0 0 0  先-1
    //1 0 0 1 1 1  ~
    //0 1 1 0 0 0  and
    //0 0 1 0 0 0
    diff &= ~(diff-1);      //找出一个不同的digit
    vector<int> res(2,0);
    for(auto i:nums){
        if(i&diff)          //有着
            res[0]^=i;
        else
            res[1]^=i;
    }
    return res;
}
