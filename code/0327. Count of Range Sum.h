/*
Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.

A naive algorithm of O(n2) is trivial. You MUST do better than that.

Input: nums = [-2,5,-1], lower = -2, upper = 2,
Output: 3 
*/

class Solution {
private:
    int mergesort(vector<long>& sums, int lower, int upper,int l, int r){
        if(r-l<=1) return 0;
        int mid=l+(r-l)/2,count=0,m=mid,n=mid;
        count=count+mergesort(sums,lower,upper,l,mid)+
            mergesort(sums,lower,upper,mid,r);
        for(int i=l;i<mid;i++){
            while(m<r && sums[m]<sums[i]+lower) m++;
            while(n<r && sums[n]<=sums[i]+upper) n++;
            count+=(n-m);
        }
        inplace_merge(sums.begin()+l,sums.begin()+mid,sums.begin()+r);
        return count;
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        //sums 最前面必须是0，不然不会包括只有一个element的sub_array
        vector<long> sums(n+1,0);
        for(int i=0; i<n; i++)
            sums[i+1]=sums[i]+nums[i];
        return mergesort(sums,lower,upper,0,n+1);
    }
};
