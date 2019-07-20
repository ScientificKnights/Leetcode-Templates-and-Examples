/*
Given a sorted array A of unique numbers, find the K-th missing number starting from the leftmost number of the array.

Input: A = [4,7,9,10], K = 1
Output: 5

Input: A = [4,7,9,10], K = 3
Output: 8

Input: A = [1,2,4], K = 3
Output: 6

1 <= A.length <= 50000
1 <= A[i] <= 1e7
1 <= K <= 1e8
*/

int missingElement(vector<int>& nums, int K) {
    int start=nums[0], toFind=start+K;
    auto ii=upper_bound(nums.begin(),nums.end(),toFind);
    while(ii-nums.begin()-1>toFind-start-K){
        toFind=start+K+(ii-nums.begin())-1;
        ii=upper_bound(nums.begin(),nums.end(),toFind);
    }
    return toFind;
}
