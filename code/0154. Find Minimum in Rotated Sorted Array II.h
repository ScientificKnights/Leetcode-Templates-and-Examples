/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
Find the minimum element.
The array may contain duplicates.


Input: [1,3,5]
Output: 1

Input: [2,2,2,0,1]
Output: 0
Note:

This is a follow up problem to Find Minimum in Rotated Sorted Array.
Would allow duplicates affect the run-time complexity? How and why?
*/

int findMin(vector<int>& nums) {
    int len=nums.size();
    if(len==1)  return nums[0];

    int start=0,end=len-1;
    while (start<end) {
        int mid = start+(end-start)/2;
        if(nums[mid]==nums[start]&&nums[start]==nums[end]){
            start++;    // 11011111  1111111011
        }
        else if (nums[mid]<=nums[end]) {
            end = mid;
        }
        else {
            start = mid+1;
        } 
    }

    return nums[start];

}
