/*
Given an array A (index starts at 1) consisting of N integers: A1, A2, ..., AN and an integer B. 
The integer B denotes that from any place (suppose the index is i) in the array A, 
you can jump to any one of the place in the array A indexed i+1, i+2, …, i+B if this place can be jumped to. Also, 
if you step on the index i, you have to pay Ai coins. If Ai is -1, it means you can’t jump to the place indexed i in the array.

Now, you start from the place indexed 1 in the array A, and your aim is to reach the place indexed N using the minimum coins. 
You need to return the path of indexes (starting from 1 to N) in the array you should take 
to get to the place indexed N using minimum coins.

If there are multiple paths with the same cost, return the lexicographically smallest such path.
If it's not possible to reach the place indexed N then you need to return an empty array.

Input: [1,2,4,-1,2], 2
Output: [1,3,5]
*/

class Solution {
public:
    //反向开始dp，最小的lexi一定能在前面
        vector<int> cheapestJump(vector<int>& A, int B) {
        int n=A.size();
        vector<int> root(n,-1);
        vector<int> dp(n,999999);
        dp[n-1]=(A[n-1]==-1)?999999:A[n-1];
        for(int i=n-2;i>=0;i--){
            if(A[i]!=-1){
                for(int j=i+1;j<min(n,i+B+1);j++){
                    if(dp[j]+A[i]<dp[i]){ 
                        root[i]=j;
                        dp[i]=dp[j]+A[i];
                    }
                }
            }
        }
        int start=0;
        vector<int> res;
        while(start!=n-1 && root[start]!=-1){
            res.push_back(start+1);
            start=root[start];
        }
        if(start==n-1){
            res.push_back(n);
            return res;
        }
        else
            return vector<int>();
    }
    /* 正向无论如何都无法解决lexi，0会出现free ride，
    vector<int> cheapestJump(vector<int>& A, int B) {
        int n=A.size();
        vector<int> root(n,-1);
        vector<int> dp(n,999999);
        dp[0]=(A[0]==-1)?999999:A[0];
        for(int i=1;i<n;i++){
            if(A[i]!=-1){
                for(int j=max(0,i-B);j<i;j++){
                    if(dp[j]+A[i]<dp[i] || (dp[j]+A[i]<=dp[i] && A[j]==0)){ 
                        root[i]=j;
                        dp[i]=dp[j]+A[i];
                    }
                }
            }
        }
        int start=n-1;
        vector<int> res;
        while(start!=0 && root[start]!=-1){
            res.push_back(start+1);
            start=root[start];
        }
        //for(auto i : root) cout<< i << " ";
        if(start==0){
            res.push_back(1);
            reverse(res.begin(),res.end());
            return res;
        }
        else
            return vector<int>();
    }
    */
};
