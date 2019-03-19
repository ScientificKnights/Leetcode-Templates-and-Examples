/*
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. 
Return the maximum product you can get.
Input: 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
*/

int integerBreak(int n) {
    //2 1*1=1
    //3 2*1=2
    //4 2*2=4
    //5 2*3=6
    //6 3*3=9
    //只有2，3变小，不能分解，其他都可以，所以dp check -2 -3
    if(n==2) return 1;
    if(n==3) return 2;
    if(n==4) return 4;
    if(n==5) return 6;
    if(n==6) return 9;
    vector<int> dp(n+1);
    dp[2]=1;dp[3]=2;dp[4]=4;dp[5]=6;dp[6]=9;
    for(int i=7;i<n+1;i++){
        dp[i]=max(dp[i],2*dp[i-2]);
        dp[i]=max(dp[i],3*dp[i-3]);
    }
    return dp[n];
}
