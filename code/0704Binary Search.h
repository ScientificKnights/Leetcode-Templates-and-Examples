/*
Given a sorted (in ascending order) integer array nums of n elements and a target value, 
write a function to search target in nums. If target exists, then return its index, otherwise return -1.
*/

int search(vector<int>& nums, int target) {
    int n=nums.size();
    int left=0,right=n,mid;
    while(left<right){
        mid=left+(right-left)/2;
        if(nums[mid]==target)
            return mid;
        else if(nums[mid]>target)
            right=mid;
        else
            left=mid+1;
    }
    return -1;
}
