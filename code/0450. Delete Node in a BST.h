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

TreeNode* deleteNode(TreeNode* root, int key) {
    TreeNode* prev=NULL,*find=root;
    while(find && find->val!=key){
        if(find->val<key){
            prev=find;
            find=find->right;
        }
        else{
            prev=find;
            find=find->left;
        }
    }
    if(!find) return root;  //cannot find return root

    if(!find->left){
        if(!prev) return root->right;       //[0] target 0
        if(prev->left==find) prev->left=find->right;
        else prev->right=find->right;
    }
    else{
        TreeNode* next=find->left;
        prev=find;
        while(next->right){
            prev=next;
            next=next->right;

        }
        find->val=next->val;
        if(prev->left==next) prev->left=next->left;
        else prev->right=next->left;
    }
    return root;
}
