/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sums to target.
The same repeated number may be chosen from candidates unlimited number of times.

Input: candidates = [2,3,5], target = 8,
A solution set is:
[  [2,2,2,2],  [2,3,3],  [3,5]  ]
*/

void helper(vector<vector<int>> &res,const vector<int>& data, vector<int> &path, int target, int cur){
    if(target==0){
        res.push_back(path);
        return;
    }
    for(int i=cur;i<data.size() && data[i]<=target;i++){
        path.push_back(data[i]);
        helper(res,data,path,target-data[i],i);
        path.pop_back();
    }
    return;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector<vector<int>> res;
    vector<int> path;
    helper(res, candidates, path, target, 0);
    return res;
}
