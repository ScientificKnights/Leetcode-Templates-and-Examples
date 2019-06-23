/*
Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].
You need to return the number of important reverse pairs in the given array.

Input: [1,3,2,3,1]
Output: 2

Input: [2,4,3,5,1]
Output: 3
*/

class Solution {
private:
    int mergesort(vector<int>& nums,int l,int r){
        if(r-l<=1) return 0;
        int mid=l+(r-l)/2,count=0;
        count+=mergesort(nums,l,mid);
        count+=mergesort(nums,mid,r);
        int jj=mid;
        for(int ii=l;ii<mid;ii++){
            while(jj<r && (long)nums[ii]>(long)2*(nums[jj])) jj++;
            count+=(jj-mid);
        }
        inplace_merge(nums.begin()+l,nums.begin()+mid,nums.begin()+r);
        return count;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size());
    }
};
