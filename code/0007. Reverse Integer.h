/*
Given a 32-bit signed integer, reverse digits of an integer.

Input: 123
Output: 321

Input: -123
Output: -321

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. 
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

int reverse(int x) {
    int result=0;
    while(x!=0)
    {
        if(abs(result)>INT_MAX/10) return 0;
        result=result*10+x%10;
        x/=10;
    }
    return result;
}
