/*
Given an integer array, your task is to find all the different possible increasing subsequences of the given array, 
and the length of an increasing subsequence should be at least 2.

Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
Note:
The length of the given array will not exceed 15.
The range of integer in the given array is [-100,100].
The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.
*/

class Solution {
private:
    void backtrack(set<vector<int>> &res, vector<int>& nums,vector<int> &path, int pos){
        int n=nums.size();
        if(pos==n){
            if(path.size()>=2){
                res.insert(path);
            }
            return;
        }
        if(path.size()==0 || path.back()<=nums[pos]){
            path.push_back(nums[pos]);
            backtrack(res,nums,path,pos+1);
            path.pop_back();
        }
        backtrack(res,nums,path,pos+1);
        return;
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> path;
        set<vector<int>> res;
        backtrack(res,nums,path,0);
        
        vector<vector<int>> newres;
        for(auto i:res)
            newres.push_back(i);

        return newres;
    }
};
