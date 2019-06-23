/*
Given a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only 1 right child.

Example 1:
Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]

       5
      / \
    3    6
   / \    \
  2   4    8
 /        / \ 
1        7   9

Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
            \
             7
              \
               8
                \
                 9  
Note:

The number of nodes in the given tree will be between 1 and 100.
Each node will have a unique integer value from 0 to 1000.
*/
class Solution {
private:
    void helper(TreeNode*root, TreeNode* &prev, TreeNode* & res){
        if(root->left)  helper(root->left,prev,res);
        if(!prev){
            res=root;
        }
        else{
            prev->left=NULL;
            prev->right=root;
        }
        prev=root;
        if(root->right) helper(root->right,prev,res);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *prev=NULL, *res=NULL;
        if(!root) return NULL;
        helper(root,prev,res);
        //最后的节点下面要清空
        prev->left=prev->right=NULL;
        return res;
    }
};
