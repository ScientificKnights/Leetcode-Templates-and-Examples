/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Input: [1,1,2]
Output:
[  [1,1,2],
  [1,2,1],
  [2,1,1] ]
*/
void helper(vector<vector<int>> &res, vector<int>& nums, int length, int cur){
    if(cur==length-1){
        res.push_back(nums);
        return;
    }
    unordered_map<int,int> used;
    for(int i=cur;i<length;i++){
        if(used.count(nums[i])) continue;//如果swap过相同的就不swap
        used[nums[i]]++;
        swap(nums[cur],nums[i]);
        helper(res,nums,length,cur+1);
        swap(nums[cur],nums[i]);  //back_tracking
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    helper(res,nums,nums.size(),0);
    return res;
}
