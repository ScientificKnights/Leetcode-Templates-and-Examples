/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
You may assume that next() call will always be valid, that is, 
there will be at least a next smallest number in the BST when next() is called.
*/

class BSTIterator {
private:
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode* root) {
        getmin(root);
    }
    
    /** @return the next smallest number */
    int next() {
        int res=s.top()->val;
        TreeNode* p=s.top();
        s.pop();
        getmin(p->right);
        return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
    
    void getmin(TreeNode* root){
        TreeNode* p=root;
        while(p) {
            s.push(p);
            p=p->left;
        }
        return;
    }
};
