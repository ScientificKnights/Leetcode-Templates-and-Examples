/*
We are given the head node root of a binary tree, where additionally every node's value is either a 0 or a 1.
Return the same tree where every subtree (of the given tree) not containing a 1 has been removed.
(Recall that the subtree of a node X is X, plus every node that is a descendant of X.)

Input: [1,null,0,0,1]
Output: [1,null,0,null,1]
 
Explanation: 
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.
*/
class Solution {
private:
    int helper(TreeNode* &root){
        if(!root) return 0;
        int left=helper(root->left),right=helper(root->right);
        int res=left+right+(root->val);
        if(!res) root=NULL;
        return res;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        helper(root);
        return root;
    }
};
