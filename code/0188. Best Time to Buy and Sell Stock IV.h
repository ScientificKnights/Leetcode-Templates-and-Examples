/*
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most k transactions.
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

int maxProfit(int k, vector<int>& prices) {
    //state (buy+sell)*k
    int n=prices.size();
    if(n<2 | k<1) return 0;
    //k特别大，不用那么多内存
    k=min(k,n/2);
    //买卖两种状态，k次
    vector<int> state(2*k,INT_MIN);
    state[0]=-prices[0];
    for(int i=1;i<n;i++){
        for(int j=0;j<2*k;j++){
            if(j==0)
                state[j]=max(state[j],-prices[i]);
            else if(j%2==1)
                state[j]=max(state[j],state[j-1]+prices[i]);
            else
                state[j]=max(state[j],state[j-1]-prices[i]);
        }
    }
    return max(0,state[2*k-1]);
}
