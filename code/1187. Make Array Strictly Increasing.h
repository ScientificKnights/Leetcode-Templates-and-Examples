/*
Given two integer arrays arr1 and arr2, return the minimum number of operations (possibly zero) needed to make arr1 strictly increasing.
In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].
If there is no way to make arr1 strictly increasing, return -1.

Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
Output: 1
Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].

Input: arr1 = [1,5,3,6,7], arr2 = [4,3,1]
Output: 2
Explanation: Replace 5 with 3 and then replace 3 with 4. arr1 = [1, 3, 4, 6, 7].

Input: arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
Output: -1
Explanation: You can't make arr1 strictly increasing.

Constraints:
1 <= arr1.length, arr2.length <= 2000
0 <= arr1[i], arr2[i] <= 10^9
*/

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        arr2.resize(unique(arr2.begin(),arr2.end())-arr2.begin());
        int n=arr1.size(),m=arr2.size();
        if(n==0) return 0;
/* arr2  1 3 4
 arr1\no. of changes
       0 1 2 3
     1 1 1 x x
     5 5 3 3 x
     3 x x 4 4
     6 x x 6 6
     7 x x 7 7     
     */        
        vector<vector<int>> dp(n,vector<int>(m+1,INT_MAX));
        dp[0][0]=arr1[0],dp[0][1]=arr2[0];
        for(int i=1;i<n;i++){
            if(arr1[i]>arr1[i-1]){
                dp[i][0]=arr1[i];
                if(i==n-1) return 0;
            }
            else break;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr1[i]>dp[i-1][j+1])
                    dp[i][j+1]=arr1[i];
                auto ii=upper_bound(arr2.begin(),arr2.end(),dp[i-1][j]);
                if(ii!=arr2.end()){
                    dp[i][j+1]=min(dp[i][j+1],*ii);
                }
            }
        }
        for(int i=0;i<m+1;i++)
            if(dp[n-1][i]!=INT_MAX) return i;
        return -1;
    }
};
