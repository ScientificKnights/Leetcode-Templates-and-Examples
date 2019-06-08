/*
A conveyor belt has packages that must be shipped from one port to another within D days.

The i-th package on the conveyor belt has a weight of weights[i].  
Each day, we load the ship with packages on the conveyor belt (in the order given by weights). 
We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within D days.

Input: weights = [1,2,3,4,5,6,7,8,9,10], D = 5
Output: 15

Input: weights = [3,2,2,4,1,4], D = 3
Output: 6

Input: weights = [1,2,3,1,1], D = 4
Output: 3
*/

class Solution {
private:
    int helper(vector<int>& weights, int vol){
        int res=0,cur=0;
        for(int i=0;i<weights.size();i++){
            cur+=weights[i];
            if(cur>vol){
                res++;
                cur=weights[i];
            }
        }
        return res+1;
    }
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int r=0,l=0,mid;
        for(auto i:weights){
            r+=i;
            if(i>l) l=i;
        } 
        if(D==1) return r;
        
        while(l<r){
            mid=(r-l)/2+l;
            int time=helper(weights,mid);
            //cout<<l<<" "<<r<<" "<<time<<endl;
            if(time<=D) r=mid;
            else l=mid+1;
        }
        return l;
    }
};
