/*
Given a rooted binary tree, return the lowest common ancestor of its deepest leaves.

Recall that:

The node of a binary tree is a leaf if and only if it has no children
The depth of the root of the tree is 0, and if the depth of a node is d, the depth of each of its children is d+1.
The lowest common ancestor of a set S of nodes is the node A with the largest depth such that every node in S is in the subtree with root A.

Input: root = [1,2,3]
Output: [1,2,3]

Input: root = [1,2,3,4]
Output: [4]

Input: root = [1,2,3,4,5]
Output: [2,4,5]
 
Constraints:

The given tree will have between 1 and 1000 nodes.
Each node of the tree will have a distinct value between 1 and 1000.
*/

class Solution {
private:
    pair<TreeNode*,int> helper(TreeNode* root){
        if(!root) return {NULL,0};
        auto l=helper(root->left),r=helper(root->right);
        if(l.second==r.second)
            return {root,l.second+1};
        else if(l.second>r.second)
            return {l.first,l.second+1};
        return{r.first, r.second+1};
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return helper(root).first;
    }
};
