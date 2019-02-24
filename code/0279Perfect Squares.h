/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
*/

int numSquares(int n) {
    //test every j*j*2<=i
    vector<int> dp(n+1,INT_MAX);
    for(int i=1;i<n+1;i++){
        if(pow(int(sqrt(i)),2)==i){
            dp[i]=1;
            continue;
        }
        for(int j=1;j*j*2<=i;j++){
            int left=i-j*j;
            dp[i]=min(dp[i],1+dp[left]);
        }
    }
    return dp[n];
}
