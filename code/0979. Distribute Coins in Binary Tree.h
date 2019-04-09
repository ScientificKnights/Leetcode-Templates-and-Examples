/*
Given the root of a binary tree with N nodes, each node in the tree has node.val coins, and there are N coins total.
In one move, we may choose two adjacent nodes and move one coin from one node to another.  
(The move may be from parent to child, or from child to parent.)

Return the number of moves required to make every node have exactly one coin.

Input: [3,0,0]
Output: 2

Input: [0,3,0]
Output: 3
*/

class Solution {
private:
    int res=0;
    int helper(TreeNode* root){  //move transfer between this node
        if(!root) return 0; 
        int l=helper(root->left),r=helper(root->right);
        res=res+abs(l)+abs(r);     //root 中多出来的只需要上移，已经计算过了
        return l+r+root->val-1;
    }
public:
    int distributeCoins(TreeNode* root) {
        helper(root);
        return res;
    }
};
