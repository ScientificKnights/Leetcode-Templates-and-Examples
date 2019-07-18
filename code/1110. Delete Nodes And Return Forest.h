/*
Given the root of a binary tree, each node in the tree has a distinct value.
After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).
Return the roots of the trees in the remaining forest.  You may return the result in any order

Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]

Constraints:

The number of nodes in the given tree is at most 1000.
Each node has a distinct value between 1 and 1000.
to_delete.length <= 1000
to_delete contains distinct values between 1 and 1000.
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
    //dfs 找需要delete的
    // helper 加root到result里
    void dfs(TreeNode* &root, unordered_set<int> &s, vector<TreeNode*> &res){
        if(!root) return;
        if(s.count(root->val)){
            helper(root->left,s,res);
            helper(root->right,s,res);
            root=NULL;
        }
        else{
            dfs(root->left,s,res);
            dfs(root->right,s,res);
        }
        return;
    }
    void helper(TreeNode* root, unordered_set<int> &s, vector<TreeNode*> &res){
        if(!root) return;
        if(s.count(root->val)){
            helper(root->left,s,res);
            helper(root->right,s,res);
        }
        else{
            dfs(root->left,s,res);
            dfs(root->right,s,res);
            res.push_back(root);
        }
        return;
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> s;
        for(auto i:to_delete) s.insert(i);
        helper(root, s, res);
        return res;
    }
};
