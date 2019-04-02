/*Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Input: n = 4, k = 2
Output:
[  [2,4],  [3,4],  [2,3],  [1,2],  [1,3],  [1,4], ]
*/

class Solution {
private:
    void dfs(vector<vector<int>> &res, vector<int> &path, int pos, int n, int k){
        if(path.size()==k)
            res.emplace_back(path);
        else if(k-path.size()<=(n-pos+1)){
            dfs(res,path,pos+1,n,k);
            path.push_back(pos);
            dfs(res,path,pos+1,n,k);
            path.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if(!n || !k) return res;
        vector<int> path;
        dfs(res,path,1,n,k);
        return res;
    }
};
