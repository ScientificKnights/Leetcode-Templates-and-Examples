/*
Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[  [1, 7],  [1, 2, 5],  [2, 6],  [1, 1, 6]  ]
*/

void helper(vector<vector<int>> &res,const vector<int>& data, vector<int> &path, int target, int cur){
    if(target==0){
        res.push_back(path);
        return;
    }
    for(int i=cur;i<data.size() && data[i]<=target;i++){
        //防止重复相同的
        if(i!=cur && data[i]==data[i-1])
            continue;
        path.push_back(data[i]);
        helper(res,data,path,target-data[i],i+1);
        path.pop_back();
    }
    return;
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector<vector<int>> res;
    vector<int> path;
    helper(res, candidates, path, target, 0);
    return res;
}
