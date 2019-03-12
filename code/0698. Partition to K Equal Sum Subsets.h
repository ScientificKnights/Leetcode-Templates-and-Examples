/*
Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets 
whose sums are all equal.

Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
*/

bool backtrack(vector<int>& nums,vector<bool>& visited,int cursum,int sum, int pos, int count, int k){
    //比普通的backtracking多了 验证visited
    while(visited[pos]) pos++;
    //true stop 的条件
    if(count==k-1 && cursum+nums[pos]==sum)
        return true;
    if(nums[pos]>sum) return false;
    for(int i=pos;i<nums.size();i++){
        if(!visited[i]){
            if(cursum+nums[i]==sum){
                visited[i]=true;
                if(backtrack(nums,visited,0,sum,0,count+1,k))return true;
                visited[i]=false;   
            }
            else if(cursum+nums[i]<sum){
                visited[i]=true;
                if(backtrack(nums,visited,cursum+nums[i],sum,i+1,count,k))return true;
                visited[i]=false;  
            }
        }
    }
    return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
    //backtracking
    int sum=0;
    for(auto i:nums)
        sum+=i;
    if(sum%k!=0) return false;
    sum/=k;
    vector<bool> visited(nums.size(),false);
    return backtrack(nums,visited,0,sum,0,0,k);
}
