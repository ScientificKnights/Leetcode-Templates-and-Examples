/*
Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.

Input: "aab"
Output: 1
*/

int minCut(string s) {
    int n=s.size();
    if(n==0) return 0;
    vector<int> count(n+1);     //存0到i需要几次partition
    for(int i=0;i<n+1;i++)
        count[i]=i-1;           //0的位置是-1，因为aa的话是 1+count[0]
    vector<vector<int>> dp(n,vector<int>(n,0)); //s[i to j] 是否palindrome
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            //dp[i-j][i]
            if(s[i]==s[i-j] && (j<2 || dp[i-j+1][i-1])){
                dp[i-j][i]=1;
                count[i+1]=min(count[i+1],1+count[i-j]);
            }
        }
    }
    return count[n];
}
