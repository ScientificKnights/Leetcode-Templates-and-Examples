/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
According to the definition of LCA on Wikipedia: 
“The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants 
(where we allow a node to be a descendant of itself).”
Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
*/

class Solution {
//root 的范围 l r
void helper(TreeNode* root,TreeNode* &res,TreeNode* p,TreeNode* q,int l,int r){
    if(p->val>l && q->val>l && p->val<r && q->val<r){
        res=root;
        if(root->left) helper(root->left, res, p, q, l,root->val);
        if(root->right) helper(root->right, res, p, q, root->val,r);
    }
    return;
}
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res=root;
        helper(root,res,p,q,INT_MIN,INT_MAX);
        return res;
    }
};
