/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
*/

int kthSmallest(TreeNode* root, int &k) {
    if(!root) return -1;
    int res=kthSmallest(root->left,k);
    if(res!=-1) return res;
    if(!(--k)) return root->val;
    return kthSmallest(root->right,k);
}
