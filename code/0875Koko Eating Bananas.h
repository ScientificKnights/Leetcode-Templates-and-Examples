/*
Koko loves to eat bananas.  There are N piles of bananas, the i-th pile has piles[i] bananas.  
The guards have gone and will come back in H hours.

Koko can decide her bananas-per-hour eating speed of K.  Each hour, she chooses some pile of bananas, 
and eats K bananas from that pile.  If the pile has less than K bananas, she eats all of them instead, 
and won't eat any more bananas during this hour.

Koko likes to eat slowly, but still wants to finish eating all the bananas before the guards come back.

Return the minimum integer K such that she can eat all the bananas within H hours.

Input: piles = [3,6,7,11], H = 8
Output: 4

Input: piles = [30,11,23,4,20], H = 5
Output: 30

Input: piles = [30,11,23,4,20], H = 6
Output: 23
*/

int minEatingSpeed(vector<int>& piles, int H) {
    int left=1,right=10e9,mid;
    while(left<right){
        mid=left+(right-left)/2;
        int sum=0;
        for(auto i:piles){
            sum+=(i+mid-1)/mid;     //取整数的upper bound
        }
        if(sum<=H) right=mid;
        else left=mid+1;
    }
    return left;
}
