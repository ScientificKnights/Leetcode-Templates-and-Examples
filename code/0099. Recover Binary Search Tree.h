/*
Two elements of a binary search tree (BST) are swapped by mistake.
Recover the tree without changing its structure.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void tranversal(TreeNode *root, TreeNode* &prev, TreeNode* &find1,TreeNode* &find2){
        if(!root) return;
        tranversal(root->left,prev,find1,find2);
        if(prev && prev->val>root->val){
            if(!find1) find1=prev;
            find2=root;
        } 
        prev=root;
        tranversal(root->right,prev,find1,find2);
    }
public:
    void recoverTree(TreeNode* root) {
        //4,2,3,1
        //3,2,1
        //1,3,2,4
        TreeNode *find1=NULL, *find2=NULL, *prev=NULL;
        tranversal(root, prev,find1,find2);
        swap(find1->val,find2->val);
        return;
    }
};
