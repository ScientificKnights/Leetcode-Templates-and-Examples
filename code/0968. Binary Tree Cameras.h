/*
Given a binary tree, we install cameras on the nodes of the tree. 
Each camera at a node can monitor its parent, itself, and its immediate children.
Calculate the minimum number of cameras needed to monitor all nodes of the tree.

Input: [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.

Input: [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.
*/

class Solution {
private:
    vector<int> helper(TreeNode*root){  //{包含个数，child包含个数,parent包含个数}
        if(!root) return {1,0,0};
        vector<int> l=helper(root->left),r=helper(root->right);
        int i=1+min(l[0],min(l[1],l[2]))+min(r[0],min(r[1],r[2]));
        int j=min(l[0]+min(r[0],r[1]),r[0]+min(l[0],l[1]));
        int k=min(l[0],l[1])+min(r[0],r[1]);
        return {i,j,k};
    }
public:
    int minCameraCover(TreeNode* root) {
        vector<int> res=helper(root);
        return min(res[0],res[1]);
    }
};
