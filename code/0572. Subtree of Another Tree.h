/*
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. 
A subtree of s is a tree consists of a node in s and all of this node's descendants. 
The tree s could also be considered as a subtree of itself.

Given tree s:
     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
*/

class Solution {
public:
    //判断是否相同
    bool helper(TreeNode* s, TreeNode* t){
        if(!s && !t)
            return true;
        if(s!=NULL && t!=NULL &&(s->val==t->val))
            return helper(s->left,t->left)&&helper(s->right,t->right);
        return false;

    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(helper(s,t)) return true;
        if((s->left) && isSubtree(s->left,t))
            return true;
        if((s->right) && isSubtree(s->right,t))
            return true;
        return false;
    }
};
