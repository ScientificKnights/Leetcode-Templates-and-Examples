/*
Given an array A of integers, return true if and only if we can partition the array into three non-empty parts with equal sums.

Formally, we can partition the array if we can find indexes i+1 < j with 
(A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1]) 

Input: [0,2,1,-6,6,-7,9,1,2,0,1]
Output: true

Input: [0,2,1,-6,6,7,9,-1,2,0,1]
Output: false

Input: [3,3,6,5,-2,2,5,1,-9,4]
Output: true

Note:

3 <= A.length <= 50000
-10000 <= A[i] <= 10000
*/

bool canThreePartsEqualSum(vector<int>& A) {
    int start=0,end=A.size()-1,sum=0,n=A.size(),res=0;
    for(auto i:A) sum+=i;
    if(sum%3) return false;
    sum/=3;
    while(start<n-2){
        if((res+=A[start++])==sum) break;
    }
    if(res!=sum) return false;
    res=0;
    while(start<end){
        if((res+=A[end--])==sum) break;
    }
    return res==sum;
}
