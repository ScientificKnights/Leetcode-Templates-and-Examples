/*
Given an array with n integers, you need to find if there are triplets (i, j, k) which satisfies following conditions:

0 < i, i + 1 < j, j + 1 < k < n - 1
Sum of subarrays (0, i - 1), (i + 1, j - 1), (j + 1, k - 1) and (k + 1, n - 1) should be equal.
where we define that subarray (L, R) represents a slice of the original array starting from the element indexed L to the element indexed R.


Input: [1,2,1,2,1,2,1]
Output: True

i = 1, j = 3, k = 5. 

1 <= n <= 2000.
Elements in the given array will be in range [-1,000,000, 1,000,000].
*/

bool splitArray(vector<int>& nums) {
    // 1 2 1 2 1 2 1
    // 1 3 4 6 7 9 10
    vector<int> sum=nums;
    int n=nums.size();
    for(int i=1;i<n;i++)
        sum[i]+=sum[i-1];
    unordered_map<int,vector<int>> m;
    for(int i=1;i<n-1;i++){
        m[sum[i-1]].push_back(i);
        if(m.count(sum[n-1]-sum[i])){
            for(auto j:m[sum[n-1]-sum[i]]){
                if(i-j>=4){
                    for(int k=j+2;k<=i-2;k++){
                        if(sum[k-1]-sum[j]==sum[i-1]-sum[k])
                            return true;
                    }
                }
            }
        }
    }
    return false;
}
