/*
Given a non-empty array of integers, every element appears three times except for one, 
which appears exactly once. Find that single one.


Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99
*/

int singleNumber(vector<int>& nums) {
    //a b num -> a b
    //0 0  0     0 0
    //0 1  0     0 1
    //1 0  0     1 0
    //0 0  1     0 1
    //0 1  1     1 0
    //1 0  1     0 0
    //a= b&c+a&~c
    //b= (~(a^b))&c+b&~c
    //加号是 |  
    //或者
    //a = a&~b&~c + ~a&b&c;
    //b = ~a&b&~c + ~a&~b&c;
    int a=0,b=0;
    for(auto i:nums){
        int temp=a;
        a= (b&i)|(a&~i);
        b= (~(temp^b)&i)|(b&~i);
    }
    return b;
}
