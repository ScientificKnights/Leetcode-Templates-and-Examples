/*
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Input: [0,1]
Output: 2

Input: [0,1,0]
Output: 2
*/

int findMaxLength(vector<int>& nums) {
    // 1 1 1 0 1 0 0 1
    // 1 2 3 2 3 2 1 2
    unordered_map<int, int> m;
    m[0]=-1;
    int n=nums.size(),res=0,cur=0;
    for(int i=0;i<n;i++){
        cur+=((nums[i])?1:-1);
        if(m.count(cur)) res=max(res,i-m[cur]);
        else m[cur]=i;
    }
    return res;
}
