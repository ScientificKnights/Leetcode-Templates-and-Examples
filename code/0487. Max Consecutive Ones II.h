/*
Given a binary array, find the maximum number of consecutive 1s in this array if you can flip at most one 0.

Input: [1,0,1,1,0]
Output: 4

Follow up:
What if the input numbers come in one by one as an infinite stream? In other words, 
you can't store all numbers coming from the stream as it's too large to hold in memory. 
Could you solve it efficiently?
*/

int findMaxConsecutiveOnes(vector<int>& A) {
    int K=1; 
    vector<int> res(K+1,0);
    int n=A.size(),ma=0;
    if(K>=n) return n;
    for(int i=0;i<n;i++){
        if(A[i]){
            for(int j=0;j<K+1;j++)
                res[j]++;
        }
        else{
            for(int j=K;j>=1;j--)
                res[j]=res[j-1]+1;
            res[0]=0;
        }
        ma=max(ma,res[K]);
    }
    return ma;
}
