/*
In LeetCode Store, there are some kinds of items to sell. Each item has a price.
However, there are some special offers, and a special offer consists of one or more different kinds of items with a sale price.
You are given the each item's price, a set of special offers, and the number we need to buy for each item.
The job is to output the lowest price you have to pay for exactly certain items as given, 
where you could make optimal use of the special offers.
Each special offer is represented in the form of an array, the last number represents the price you need to pay for this special offer, 
other numbers represents how many specific items you could get if you buy this offer.
You could use any of special offers as many times as you want.

Input: [2,5], [[3,0,5],[1,2,10]], [3,2]
Output: 14
Explanation: 
There are two kinds of items, A and B. Their prices are $2 and $5 respectively. 
In special offer 1, you can pay $5 for 3A and 0B
In special offer 2, you can pay $10 for 1A and 2B. 
You need to buy 3A and 2B, so you may pay $10 for 1A and 2B (special offer #2), and $4 for 2A.

Example 2:
Input: [2,3,4], [[1,1,0,4],[2,2,1,9]], [1,2,1]
Output: 11
Explanation: 
The price of A is $2, and $3 for B, $4 for C. 
You may pay $4 for 1A and 1B, and $9 for 2A ,2B and 1C. 
You need to buy 1A ,2B and 1C, so you may pay $4 for 1A and 1B (special offer #1), and $3 for 1B, $4 for 1C. 
You cannot add more items, though only $9 for 2A ,2B and 1C.
*/

class Solution {
private:
    int multi(vector<int>& a, vector<int>& b){
        int n=a.size(),res=0;
        for(int i=0;i<n;i++)
            res+=(a[i]*b[i]);
        return res;
    }
    void minus(vector<int>& a, vector<int>& b){
        int n=a.size();
        for(int i=0;i<n;i++)
            a[i]-=b[i];
        return;
    }
    void add(vector<int>& a, vector<int>& b){
        int n=a.size();
        for(int i=0;i<n;i++)
            a[i]+=b[i];
        return;
    }
    bool negative(vector<int>& a){
        for(auto i:a)
            if(i<0)
                return true;
        return false;
    }
    
    void backtrack(vector<int>&price, vector<vector<int>>& special, vector<int>& needs, int pos, int cur_total, int &res){
        if(negative(needs) || cur_total>=res)
            return;
        res=min(res,cur_total+multi(needs,price));  //重要，不能只到最后算，每个路径都要算
        
        for(int i=pos;i<special.size();i++){
            minus(needs,special[i]);
            backtrack(price,special,needs,i,cur_total+special[i].back(),res);
            add(needs,special[i]);
        }
        return;
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        //backtracking
        int res=INT_MAX, pos=0, cur_total=0;
        backtrack(price,special,needs,pos,cur_total,res);
        return res;
    }
};
