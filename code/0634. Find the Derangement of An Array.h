/*
In combinatorial mathematics, a derangement is a permutation of the elements of a set,
such that no element appears in its original position.

There's originally an array consisting of n integers from 1 to n in ascending order,
you need to find the number of derangement it can generate.

Also, since the answer may be very large, you should return the output mod 10^9 + 7.

Input: 3
Output: 2
Explanation: The original array is [1,2,3]. The two derangements are [2,3,1] and [3,1,2].
Note:
n is in the range of [1, 10^6].
*/

int findDerangement(int n) {
    //dp[n]=(n-1)*(dp[n-2]+dp[n-1]);
    // 第一个位置n-1个选择，假设放了i
    //第i个位置放1，then dp[n-2]
    //第i个位置不放1，then 从第二个元素开始，第i个不放1，其他不放本身，dp[n-1]
    if(n<=3) return n-1;

    int M = 1000000007;
    long a1=1,a2=2;

    for(int i=4;i<=n;i++){
        int temp=a2;
        a2=(long(i-1)*(a1+a2))%M;
        a1=temp;
    }
    return (int)a2;
}
