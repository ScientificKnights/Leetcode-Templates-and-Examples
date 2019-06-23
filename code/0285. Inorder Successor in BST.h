/*
Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

The successor of a node p is the node with the smallest key greater than p.val.
*/

class Solution {
private:
    TreeNode* helper(TreeNode* root,TreeNode* &prev, TreeNode*p){
        TreeNode* res=NULL;
        if(root->val>p->val){
            if(root->left)
                res=helper(root->left,prev,p);
        }
        if(res) return res;
        if(prev==p) return root;
        prev=root;
        if(root->right)
            res=helper(root->right,prev,p);
        if(res) return res;
        return NULL;
    }
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *prev=NULL;
        return helper(root,prev,p);
    }
};
