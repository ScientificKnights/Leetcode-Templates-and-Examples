/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
Note: The solution set must not contain duplicate subsets.

Input: [1,2,2]
Output:
[  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []  ]
*/
void helper(vector<vector<int>> &res, const unordered_map<int,int> &m, vector<int> &path, unordered_map<int,int>::iterator cur){
    if(cur==m.end()){
        res.push_back(path);
        return;
    }
    auto pre=cur++;
    helper(res,m,path,cur);
    //加入不同的次数
    for(int i=0;i<pre->second;i++){
        path.push_back(pre->first);
        helper(res,m,path,cur);
    }
    //backtracking
    for(int i=0;i<pre->second;i++)
        path.pop_back();
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> res;
    unordered_map<int,int> m;
    //用map变为没有重复的
    for(auto i:nums)
        m[i]++;
    vector<int> path;
    helper(res,m,path,m.begin());
    return res;
}
