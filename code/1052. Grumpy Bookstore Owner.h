/*
Today, the bookstore owner has a store open for customers.length minutes.  
Every minute, some number of customers (customers[i]) enter the store, and all those customers leave after the end of that minute.

On some minutes, the bookstore owner is grumpy.  If the bookstore owner is grumpy on the i-th minute, grumpy[i] = 1, 
otherwise grumpy[i] = 0.  When the bookstore owner is grumpy, the customers of that minute are not satisfied, 
otherwise they are satisfied.

The bookstore owner knows a secret technique to keep themselves not grumpy for X minutes straight, but can only use it once.
Return the maximum number of customers that can be satisfied throughout the day.

Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], X = 3
Output: 16
*/

int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
    int n=grumpy.size();
    int max_grumpy=0,sum_grumpy=0,sum_not_grumpy=0;
    for(int i=0;i<n;i++){
        if(grumpy[i])
            sum_grumpy+=customers[i];
        else
            sum_not_grumpy+=customers[i];
        if(i>=X && grumpy[i-X])
            sum_grumpy-=customers[i-X];
        max_grumpy=max(max_grumpy,sum_grumpy);
    }
    return sum_not_grumpy+max_grumpy;
}
