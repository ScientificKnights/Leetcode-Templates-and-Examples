/*
Given a set of distinct integers, nums, return all possible subsets (the power set).
Note: The solution set must not contain duplicate subsets.

Input: nums = [1,2,3]
Output:
[  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []  ]
*/

void helper(vector<vector<int>> &res, vector<int> &nums, vector<int> &path, int cur){
    if(cur==nums.size()){
        res.push_back(path);
        return;
    }
    helper(res,nums,path,cur+1);
    path.push_back(nums[cur]);
    helper(res,nums,path,cur+1);
    path.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> path;
    helper(res,nums,path,0);
    return res;
}
