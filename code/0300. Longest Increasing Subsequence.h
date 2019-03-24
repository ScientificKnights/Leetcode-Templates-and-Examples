/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
*/

int lengthOfLIS(vector<int>& nums) {
    int n=nums.size();
    vector<int> sorted;
    for(int i:nums){
        //binary search sorted vector, find not less than or end
        auto iter=lower_bound(sorted.begin(),sorted.end(),i);
        if(iter==sorted.end())
            sorted.push_back(i);
        else
            *iter=i;
    }
    return sorted.size();
}
