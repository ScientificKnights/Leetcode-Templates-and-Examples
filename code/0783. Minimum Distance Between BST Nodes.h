/*
Given a Binary Search Tree (BST) with the root node root, 
return the minimum difference between the values of any two different nodes in the tree.

Input: root = [4,2,6,1,3,null,null]
Output: 1
The given tree [4,2,6,1,3,null,null] is represented by the following diagram:

          4
        /   \
      2      6
     / \    
    1   3  

while the minimum difference in this tree is 1, it occurs between node 1 and node 2, also between node 3 and node 2.
The size of the BST will be between 2 and 100.
The BST is always valid, each node's value is an integer, and each node's value is different.
*/

class Solution {
private:
    long res=INT_MAX;
    void diff(TreeNode* root,TreeNode* &prev){
        if(!root) return;
        diff(root->left,prev);
        if(prev)        //not first time
            res=min(res,(long)root->val-prev->val);
        prev=root;
        diff(root->right,prev);
        return;
    }
public:
    int minDiffInBST(TreeNode* root) {
        TreeNode *prev=NULL;
        diff(root, prev);
        return (int)res;
    }
};
