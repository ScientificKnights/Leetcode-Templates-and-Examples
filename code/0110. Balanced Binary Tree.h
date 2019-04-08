/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/

class Solution {
private:
    bool res=1;
    int maxdepth(TreeNode* root)
    {
        if(!root) return 0;
        int leftdepth=maxdepth(root->left);
        int rightdepth=maxdepth(root->right);
        if(abs(leftdepth-rightdepth)>1) res=0;
        return max(leftdepth,rightdepth)+1;
    }
public:
    bool isBalanced(TreeNode* root) 
    { 
        maxdepth(root);
        return res;
    }
};
