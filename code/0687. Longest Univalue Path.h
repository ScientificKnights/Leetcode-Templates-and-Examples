/*
Given a binary tree, find the length of the longest path where each node in the path has the same value.
This path may or may not pass through the root.

Note: The length of path between two nodes is represented by the number of edges between them.

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output:
2
Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output:
2
*/

class Solution {
private:
	int max_res=0;
public:
	//one direction IMPORTANT
    int longest(TreeNode* root){
        int len_left=0,len_right=0;
        if(root->left){
            len_left=longest(root->left);
            len_left=(root->left->val==root->val)?len_left+1:0;
        }
        if(root->right){
            len_right=longest(root->right);
            len_right=(root->right->val==root->val)?len_right+1:0;
        }
        //update TWO directions
        max_res=max(max_res,len_left+len_right);
        //return one direction
        return max(len_left,len_right);
    }
    
    int longestUnivaluePath(TreeNode* root) {
        if(!root)	return 0;
	      longest(root);
        return max_res;
    }
};
