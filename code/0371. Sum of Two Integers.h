/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = -2, b = 3
Output: 1
*/

int getSum(int a, int b) {
    if(!b) return a;
    return getSum(a^b, ((a & b) & 0x7FFFFFFF) << 1);
    
    // 1    1 1110 1100 1000 0  
    //-1 1111 0010 0100 1000 0
    //负数 1111可以理解为 111减去1000, 所以 a&b 出现两个1000时一个是正的，一个是负数
    //用0x7fffffff 消掉最前面的。

    //1  0001 1111
    //-2 1110 0000
}
