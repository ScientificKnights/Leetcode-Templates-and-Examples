/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/

int longestConsecutive(vector<int>& nums) {
    int maxlength=0;
    // map 存0.在nums中出现，并且没扫过长度
    // map 存1.已经在最长subsequence里面update了
    unordered_map<int,int> used;
    for (int num:nums)
        used[num]=0;

    for (int num:nums){
        int length=0;
        if (used.find(num)!=used.end()&& used[num]==0){
            used[num]=1;
            length++;
            int number=num;
            while(used.find(--num)!=used.end()){
                length++; used[num]=1;
            }
            num=number;
            while(used.find(++num)!=used.end()){
                length++; used[num]=1;
            }    
        }
        maxlength=max(length,maxlength);
    }
    return maxlength;
}
