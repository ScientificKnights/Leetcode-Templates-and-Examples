/*
Given an unsorted array of integers, find the number of longest increasing subsequence.

Input: [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].
*/

int findNumberOfLIS(vector<int>& nums) {
    //dp O(N^2)
    //       1 2 4 3 5 4 7 2
    //pos    1 2 3 3 4 4 5 2
    //counts 1 1 1 1 2 1 3 1
    int n=nums.size();
    vector<int> pos(n,0);
    vector<int> counts(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                if(pos[i]<pos[j]){
                    pos[i]=pos[j];
                    counts[i]=counts[j];
                }
                else if(pos[i]==pos[j])
                    counts[i]+=counts[j];
            }
        }
        pos[i]++;
        //如果是第一个
        if(pos[i]==1)
            counts[i]=1;
    }
    int length=INT_MIN,res=0;
    for(int i=0;i<n;i++){
        //更新最后一个位置
        if(pos[i]>length){
            length=pos[i];
            res=counts[i];
        }
        //并列位置是最后一个
        else if(pos[i]==length){
            res+=counts[i];
        }
    }
    return res;
}
