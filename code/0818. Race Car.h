/*
Your car starts at position 0 and speed +1 on an infinite number line.  (Your car can go into negative positions.)
Your car drives automatically according to a sequence of instructions A (accelerate) and R (reverse).
When you get an instruction "A", your car does the following: position += speed, speed *= 2.
When you get an instruction "R", your car does the following: if your speed is positive then speed = -1 , otherwise speed = 1.  
(Your position stays the same.)

For example, after commands "AAR", your car goes to positions 0->1->3->3, and your speed goes to 1->2->4->-1.
Now for some target position, say the length of the shortest sequence of instructions to get there.

Input: 
target = 3
Output: 2
The shortest instruction sequence is "AA".

Input: 
target = 6
Output: 5
The shortest instruction sequence is "AAARA".
*/

class Solution {
    //1 + 2^1 + 2 ^n = 2^(n+1)-1
    //use 1<<n, shift优先级小于加减法
    /*
Note that to apply the definition of T(i) to subproblems, the car has to start with speed of 1. 
Also we need to make sure the direction of the initial speed when applying T(i) is pointing towards the final target position.
However, we don't really know how many accelerate instructions there should be before the reverse instruction, 
so theoretically we need to try all possible cases: zero A, one A, two A, three A, ... and so on. 
    */
private:
    int dp[10001];
public:
    int racecar(int t) {
        if(dp[t]>0) return dp[t];
        
        int n = (int)log2(t+1);
        if(t== (1<<n)-1) {dp[t]=n; return n;}
        //先走到大于t的位置，然后dp往回zou
        dp[t]= (n+1)+ 1 + racecar( (1<<(n+1)) -1-t);
        //先走到2^n-1, 往回走 2^i-1, i<n, 然后dp
        for(int i=0;i<n;i++)
            dp[t]=min(dp[t], n+1+i+1+racecar( t- ( (1<<n)-(1<<i) ) ) );

        return dp[t];
    }
};
