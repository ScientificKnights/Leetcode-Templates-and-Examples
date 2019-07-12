/*
Return the length of the shortest, non-empty, contiguous subarray of A with sum at least K.
If there is no non-empty subarray with sum at least K, return -1.

Input: A = [1], K = 1
Output: 1

Input: A = [1,2], K = 4
Output: -1

Input: A = [2,-1,2], K = 3
Output: 3

Note:

1 <= A.length <= 50000
-10 ^ 5 <= A[i] <= 10 ^ 5
1 <= K <= 10 ^ 9
*/

int shortestSubarray(vector<int>& A, int K) {
    int n=A.size(), res=INT_MAX;
    deque<int> dq;
    vector<int> sum(n+1,0);
    for(int i=0;i<n;i++)
        sum[i+1]=sum[i]+A[i];
    for(int i=0;i<n+1;i++){
        while(dq.size() && sum[i]-sum[dq.front()] >= K)
            //cur-dq里面的，当前是最短的
            res=min(res,i-dq.front()),dq.pop_front();
        while(dq.size() && sum[dq.back()] >= sum[i])
            //dq后面的-dq里面的，现在最短
            dq.pop_back();
        dq.push_back(i);
    }
    return res==INT_MAX?-1:res;
}
