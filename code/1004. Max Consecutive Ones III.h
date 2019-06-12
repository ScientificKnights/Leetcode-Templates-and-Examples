/*
Given an array A of 0s and 1s, we may change up to K values from 0 to 1.

Return the length of the longest (contiguous) subarray that contains only 1s. 

 

Example 1:

Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
Output: 6
*/

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        //sliding windows
        int n=A.size(), res=0, cur=0, pos=0;
        for(int i=0;i<n;i++){
            if(!A[i]){
                cur++;
                if(cur>K){
                    while(pos<n && A[pos]) pos++; 
                    pos++;      //只去掉第一个0
                }
                
            }
            res=max(res,i-pos+1);
        }
        return res;
    }
    /*
    int longestOnes(vector<int>& A, int K) {
        //dp O(K*N) 超时
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
    }*/
};
