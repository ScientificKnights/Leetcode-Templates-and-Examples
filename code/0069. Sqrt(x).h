/*
Implement int sqrt(int x).
Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:
Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
*/

int mySqrt(int x){
    if(x<=1) return x;
    int start=1, end=x, mid;
    while(start<end){
        mid=start+(end-start)/2;
        if(mid>x/mid)
            end=mid;
        else
            start=mid+1;
    }
    return start-1;
}
