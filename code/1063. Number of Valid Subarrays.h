/*
Given an array A of integers, return the number of non-empty continuous subarrays that satisfy the following condition:
The leftmost element of the subarray is not larger than other elements in the subarray.

Input: [1,4,2,5,3]
Output: 11

Input: [3,2,1]
Output: 3

Input: [2,2,2]
Output: 6

1 <= A.length <= 50000
0 <= A[i] <= 100000
*/

int validSubarrays(vector<int>& nums) {
    //Maintain monotonically increased values in a stack. 
    //The size of the stack is the number of valid subarrays between the first and last element in the stack.
    vector<int> s;
    int res=0;
    for (auto n : nums) {
        while (!s.empty() && n < s.back()) s.pop_back();
        s.push_back(n);
        res += s.size();
    }
    return res;
}
