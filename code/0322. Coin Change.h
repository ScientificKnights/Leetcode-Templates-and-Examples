/*
You are given coins of different denominations and a total amount of money amount. 
Write a function to compute the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1
*/

//8ms
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Sort coins in desending order
        sort(coins.rbegin(), coins.rend());
        int ans = INT_MAX;
        coinChange(coins, 0, amount, 0, ans);
        return ans == INT_MAX ? -1 : ans;
    }
private:
    void coinChange(const vector<int>& coins, int s, int amount, int count, int& ans) {
    //s position to search, count is result of current path 
        if (amount == 0) {
            ans = min(ans, count);
            return;
        }
        if (s == coins.size()) return;
        
        const int coin = coins[s];                
        for (int k = amount / coin; k >= 0 && count + k < ans; k--)
            coinChange(coins, s + 1, amount - k * coin, count + k, ans);
    }    
};
/*
//dp O(amount*k) 60ms
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //DP
        if(amount==0) return 0;
        vector<int> data(amount+1,INT_MAX);
        data[0]=0;
        for(int i=1;i<amount+1;i++){
            for(int j=0; j<coins.size();j++)    //coin太大停, 不能在for loop 如果coin不是sort的
                if(i-coins[j]>=0 && data[i-coins[j]]!=INT_MAX){
                    data[i]=min(data[i],data[i-coins[j]]+1);
                }
        }
        return data[amount]==INT_MAX ? -1:data[amount];
    }
};

//dp memory 748ms
class Solution {
private: 
    unordered_map<int,int> m;
    int helper(vector<int>& coins, int amount){
        if(m.count(amount)!=0) 
            return m[amount];
        m[amount]=INT_MAX;
        for(int i=0;i<coins.size() && coins[i]<=amount;i++){
            int count=helper(coins,amount-coins[i]);
            if(count!=-1)
                m[amount]=min(m[amount],count+1);
                              
        }
        if(m[amount]==INT_MAX) m[amount]=-1;
        return m[amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        m[0]=0;
        sort(coins.begin(),coins.end());
        return helper(coins,amount);
    }
};
*/
