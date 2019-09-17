/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
*/

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int dist=n+m-1; //last element in nums1 need to move
    int i=m-1,j=n-1;
    while(j>=0){
        //注意最后i指到-1
        //003000000   3   -1，11123  6
        if(i<0 || nums2[j]>nums1[i]){
            nums1[dist--]=nums2[j--];
        }
        else{
            nums1[dist--]=nums1[i--];
        }
    }
}
