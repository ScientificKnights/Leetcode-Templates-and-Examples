/*
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.
Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.

Given BST [1,null,2,2],
   1
    \
     2
    /
   2
return [2].
Note: If a tree has more than one mode, you can return them in any order.
Follow up: Could you do that without using any extra space? 
(Assume that the implicit stack space incurred due to recursion does not count).
*/

class Solution {
private:
    int cur_count=0;
    int max_count=0;
    void count_max(TreeNode*root, TreeNode* &prev){
        if (!root) return;
        count_max(root->left, prev);
        if(!prev)
            cur_count=max_count=1;
        else if(prev->val!=root->val){
            max_count=max(max_count,cur_count);
            cur_count=1;
        }
        else
            cur_count++;
        prev=root;
        count_max(root->right,prev);
        return;
    }
    void helper(TreeNode* root, TreeNode* &prev, vector<int> & res){
        if (!root) return;
        helper(root->left, prev, res);
        if(!prev)
            cur_count=1;
        else if(prev->val!=root->val){
            if(cur_count==max_count){res.push_back(prev->val);}
            cur_count=1;
        }
        else if(prev->val==root->val)
            cur_count++;
        prev=root;
        helper(root->right, prev, res);
        return;
    }
public:
    vector<int> findMode(TreeNode* root) {
        TreeNode* prev=NULL;
        count_max(root,prev);
        max_count=max(max_count,cur_count);         //如果最后的最大，可能没有更新
        cur_count=0;prev=NULL;
        vector<int> res;
        helper(root, prev, res);
        if(max_count && cur_count==max_count) res.push_back(prev->val);         //input []； 更新如果最后最大
        return res;
    }
};
