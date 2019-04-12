/*
Given a binary tree, determine if it is a valid binary search tree (BST).
Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/

//20s inorder
class Solution 
{
private:
    bool valid(TreeNode* root, TreeNode* &prev)
    {
        if(!root) return true;
        if(!valid(root->left,prev)) return false;
        if(prev && root->val<=prev->val) return false;
        prev=root;
        return valid(root->right,prev);
    }
public:
    bool isValidBST(TreeNode* root)
    {
        TreeNode* prev = NULL;
        return valid(root, prev);
    }
};
/*
//range 20ms
class Solution 
{
private:
    bool valid(TreeNode* root, long mi, long ma)
    {
        if(root==NULL)  return true;
        if((root->val<=ma)&&( root->val>=mi))
            return valid(root->left,mi,(long)root->val-1) && valid(root->right,(long)root->val+1,ma);
        else
            return false;
    }
public:
    bool isValidBST(TreeNode* root)
    {
        return valid(root,INT_MIN,INT_MAX);
    }
};
*/
