/*
Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.
Here, a circular array means the end of the array connects to the beginning of the array.  
(Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

Also, a subarray may only include each element of the fixed buffer A at most once.  
(Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

Input: [1,-2,3,-2]
Output: 3

Input: [5,-3,5]
Output: 10

Input: [3,-1,2,-1]
Output: 4
Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4

Input: [3,-2,2,-3]
Output: 3

Input: [-2,-3,-1]
Output: -1
Explanation: Subarray [-1] has maximum sum -1

-30000 <= A[i] <= 30000
1 <= A.length <= 30000
*/

int maxSubarraySumCircular(vector<int>& A) {
    //最大 或者 sum-中间段（不能是全部）最小
    //全部array都在最小只会在所有element都是负数时出现
    int n=A.size(),res1=INT_MIN,res2=INT_MAX,sum=0,misum=0,masum=0;
    for(int i=0;i<n;i++){
        sum+=A[i];
        misum+=A[i];
        masum+=A[i];
        res1=max(res1,masum);
        res2=min(res2,misum);
        if(masum<0){masum=0;}
        if(misum>0){misum=0;}
    }
    return res1>0?max(res1,sum-res2):res1;
}
