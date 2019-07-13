/*
Given an array of integers A, find the sum of min(B), where B ranges over every (contiguous) subarray of A.

Since the answer may be large, return the answer modulo 10^9 + 7.

Input: [3,1,2,4]
Output: 17
Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.  Sum is 17.
*/

int sumSubarrayMins(vector<int>& A) {
    int n=A.size(),res=0, mod = 1e9 + 7;
    vector<int> prevSmaller(n,0);
    stack<int> s1;
    //单调增
    for(int i=0;i<n;i++){
        while(!s1.empty() && A[s1.top()]>=A[i])
            s1.pop();
        prevSmaller[i]=(s1.empty()?-1:s1.top());
        s1.push(i);
    }
    vector<int> sum(n,0);
    for(int i=0;i<n;i++){
        int cur=0;
        cur=((i-prevSmaller[i])*A[i])%mod;
        if(prevSmaller[i]!=-1) cur=(cur+sum[prevSmaller[i]])%mod;
        sum[i]=cur;
        res=(res+cur)%mod;
    }
    return res;
}
