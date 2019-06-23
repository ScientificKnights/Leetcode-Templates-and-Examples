/*
Given an array A of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.

Input: A = [4,5,0,-2,-3,1], K = 5
Output: 7
*/

int subarraysDivByK(vector<int>& A, int K) {
    int n=A.size(),res=0;
    vector<int> num(n+1,0);
    unordered_map<int,int> m;
    m[0]=1;
    for(int i=0;i<n;i++){
        num[i+1]=((num[i]+A[i])%K+K)%K; //余数是负数
        m[num[i+1]]++;
    }
    for(auto i:m)
        res+=((i.second-1)*i.second/2);
    return res;
}
