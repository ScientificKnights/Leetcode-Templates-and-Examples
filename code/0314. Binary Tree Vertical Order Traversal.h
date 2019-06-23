/*
Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).
If two nodes are in the same row and column, the order should be from left to right.
*/

class Solution {
private:
    void helper(map<int, vector<int>> &m, int pos, TreeNode* root){
        if(!root) return;
        m[pos].push_back(root->val);
        helper(m,pos-1,root->left);
        helper(m,pos+1,root->right);
    }
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        map<int, vector<int>> m;
        queue<pair<int, TreeNode*>> q;
        if(!root) return res;
        q.push({0,root});
        while(!q.empty()){
            int pos=q.front().first;
            m[pos].push_back(q.front().second->val);
            if(q.front().second->left)
                q.push(make_pair(pos-1,q.front().second->left));
            if(q.front().second->right)
                q.push(make_pair(pos+1,q.front().second->right));
            q.pop();
        }
        for(auto i:m)
            res.push_back(i.second);
        return res;
    }
};
