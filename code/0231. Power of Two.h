/*
Given an integer, write a function to determine if it is a power of two.

Input: 1
Output: true

Input: 16
Output: true

Input: 218
Output: false
*/

bool isPowerOfTwo(int n) {
    if(n<=0) return false;
    return (n&(n-1))==0;
}
