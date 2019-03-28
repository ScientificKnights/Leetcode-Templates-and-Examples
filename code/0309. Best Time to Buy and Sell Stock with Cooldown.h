/*
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
(ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)

Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]
*/

int maxProfit(vector<int>& prices) {
    //       1  2  3 0 2
    //buy   -1 -1 -1 1 1
    //sell min  1  2 2 3
    //reset  0  0  1 2 2
    int n=prices.size();
    if(n<=1) return 0;
    int buy=-prices[0];
    int sell=INT_MIN,reset=0;
    int pre_buy,pre_sell;
    //buy 要在reset后面，reset是max pre_sell, 意味着之前卖过
    //reset[i]=max(reset[i-1], buy[i-1])
    //buy[i]=max(buy[i-1], reset[i-1]-prices[i])
    for(int i=1;i<n;i++){
        pre_sell=sell;
        buy=max(buy,reset-prices[i]);
        sell=max(sell, buy+prices[i]);
        reset=max(reset,pre_sell);
    }
    return sell;
}
