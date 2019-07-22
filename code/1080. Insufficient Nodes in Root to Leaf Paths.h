/*
Given the root of a binary tree, consider all root to leaf paths: paths from the root to any leaf.  (A leaf is a node with no children.)
A node is insufficient if every such root to leaf path intersecting this node has sum strictly less than limit.
Delete all insufficient nodes simultaneously, and return the root of the resulting binary tree.

Input: root = [1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14], limit = 1
Output: [1,2,3,4,null,null,7,8,9,null,14]

Input: root = [5,4,8,11,null,17,4,7,1,null,null,5,3], limit = 22
Output: [5,4,8,11,null,17,4,7,null,null,null,5]

Input: root = [1,2,-3,-5,null,4,null], limit = -1
Output: [1,null,-3,4]

Note:
The given tree will have between 1 and 5000 nodes.
-10^5 <= node.val <= 10^5
-10^9 <= limit <= 10^9
*/

class Solution {
private:
    int helper(TreeNode* &root, int sum, int limit){
        //需要删除的情况 要处理左右再管
        sum+=root->val;
        int l=INT_MIN,r=INT_MIN;
        if(!root->left && !root->right) return sum; //先处理，之后会变左右
        if(root->left) {
            l=helper(root->left, sum,limit);
            if(l<limit)root->left=NULL;
        }
        if(root->right) {
            r=helper(root->right, sum,limit);
            if(r<limit)root->right=NULL;
        }
        return max(l,r);
    }
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        int res=helper(root,0,limit);
        if(res<limit) root=NULL;
        return root;
    }
};
