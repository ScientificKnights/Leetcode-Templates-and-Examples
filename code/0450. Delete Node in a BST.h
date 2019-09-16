/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST. 
Return the root node reference (possibly updated) of the BST.
Basically, the deletion can be divided into two stages:
Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).

root = [5,3,6,2,4,null,7]
key = 3
    5
   / \
  3   6
 / \   \
2   4   7
Given key to delete is 3. So we find the node with value 3 and delete it.
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

TreeNode* deleteNode(TreeNode* root, int key) {
    TreeNode* prev=NULL, *find=root;
    while(find && find->val!=key){
        prev=find;
        if(find->val<key)
            find=find->right;
        else
            find=find->left;
    }
    if(!find) return root;  //cannot find return root

    if(!find->left){
        if(!prev) return root->right;       //[0] target 0
        if(prev->left==find) prev->left=find->right;
        else prev->right=find->right;
    }
    else if(!find->right){
        if(!prev) return root->left;
        if(prev->left==find) prev->left=find->left;
        else prev->right=find->left;
    }
    else{
        TreeNode* temp=find->right;
        while(temp->left) temp=temp->left;
        temp->left=find->left;

        if(!prev) return root->right;
        if(prev->left==find) prev->left=find->right;
        else prev->right=find->right;
    }
    return root;
}
