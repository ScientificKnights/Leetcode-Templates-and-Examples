/*
Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.


Input: dividend = 10, divisor = 3
Output: 3

Input: dividend = 7, divisor = -3
Output: -2

Note:
Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. 
For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
*/

  int divide(int A, int B) {
      //Int_min/-1
      if (A == INT_MIN && B == -1) return INT_MAX;

      long a = abs((long)A), b = abs((long)B), res = 0;
      for(int i=31;i>=0;i--){
          if( (a>>i) >= b){
              res+=(1<<i);
              a-=(b<<i);
          }
      }
      return (A > 0) == (B > 0) ? res : -res;
  }
