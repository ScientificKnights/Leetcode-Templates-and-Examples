/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
Note: A leaf is a node with no children.


Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:
[   [5,4,11,2],   [5,8,4,5] ]
*/

class Solution {
private:
    void backtrack(vector<vector<int>> &res, vector<int> &path,TreeNode* root,int sum, int target){
        //如果是root且相等
        if(!root->left && !root->right){
            if(root->val+sum==target){
                path.push_back(root->val);
                res.push_back(path);
                //找到了不要忘记pop_back
                path.pop_back();
            }
            return;
        }
        path.push_back(root->val);
        if(root->left)
            backtrack(res,path,root->left,sum+root->val,target);
        if(root->right)
            backtrack(res,path,root->right,sum+root->val,target);
        path.pop_back();
        return;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        if(root)
            backtrack(res,path, root, 0, sum);
        return res;
    }
};
