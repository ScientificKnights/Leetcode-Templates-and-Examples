/*
Given a collection of distinct integers, return all possible permutations.

Input: [1,2,3]
Output:
[  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]  ]
*/

void helper(vector<vector<int>> &res, vector<int>& nums, int length, int cur){
    if(cur==length-1){
        res.push_back(nums);
        return;
    }
    for(int i=cur;i<length;i++){
        swap(nums[cur],nums[i]);
        helper(res,nums,length,cur+1);
        swap(nums[cur],nums[i]);  //back_tracking
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    helper(res,nums,nums.size(),0);
    return res;
}
