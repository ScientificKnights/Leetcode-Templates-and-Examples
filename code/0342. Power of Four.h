/*
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Input: 16
Output: true

Input: 5
Output: false
*/

bool isPowerOfFour(int n) {
    if(n<0) return false;
    //     1
    //   100
    // 10000
    // n&(n-1) 只有一个one | n&0x55555555 1只能在基数位
    // F = 0x55555555 = 01010101010101010101010101010101
    // T = 0x33333333 = 00110011001100110011001100110011
    // O = 0x0f0f0f0f = 00001111000011110000111100001111
    return !(n&(n-1)) && (n&0x55555555);
}
