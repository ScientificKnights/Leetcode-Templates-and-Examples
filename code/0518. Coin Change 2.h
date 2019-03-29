/*
You are given coins of different denominations and a total amount of money. 
Write a function to compute the number of combinations that make up that amount. 
You may assume that you have infinite number of each kind of coin.

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
*/

int change(int amount, vector<int>& coins) {
    // amount=5:1, 2, 5
    //  0 1 2 3 4 5
    //5:0 0 0 0 0 1
    //2:0 0 1 0 1 0
    //1 0 1 2 2 3 4

    //过k次amount，免去重复的。
    vector<int> dp(amount+1,0);
    dp[0]=1;
    int n=coins.size();
    for(int i=0;i<n;i++){
        //if(amount>=coins[i]) dp[coins[i]]=1;  // 通过设dp[0]=1 免去这步
        for(int j=coins[i];j<amount+1;j++)
            dp[j]+=dp[j-coins[i]];
    }
    return dp[amount];
}
