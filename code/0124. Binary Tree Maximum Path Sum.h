/*
Given a non-empty binary tree, find the maximum path sum.
For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree 
along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Input: [1,2,3]
       1
      / \
     2   3
Output: 6

Input: [-10,9,20,null,null,15,7]
   -10
   / \
  9  20
    /  \
   15   7
Output: 42
*/

class Solution {
private:
    int res=INT_MIN;
    int helper(TreeNode* root){
        if(!root) return 0;
        int l=helper(root->left),r=helper(root->right);
        int cur=max(max(l+root->val,r+root->val),root->val);
        res=max(max(res,l+root->val+r),cur);
        return cur;
    }
public:
    int maxPathSum(TreeNode* root) {
        helper(root);
        return res;
    }
};
