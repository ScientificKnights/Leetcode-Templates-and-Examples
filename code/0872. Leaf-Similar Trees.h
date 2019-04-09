/*
Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.
For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).
Two binary trees are considered leaf-similar if their leaf value sequence is the same.
Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.
 */
 
class Solution {
private:
    int dfs(stack<TreeNode*> &s){
        while(true){
            TreeNode* t=s.top();
            s.pop();
            if(t->right) s.push(t->right);
            if(t->left) s.push(t->left);
            if(!t->left && !t->right) return t->val;
        }
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        //如果直接比较array，space O(N), use stack log(N)
        stack<TreeNode*> s1,s2;
        s1.push(root1);
        s2.push(root2);
        while(!s1.empty() && !s2.empty())
            if(dfs(s1)!=dfs(s2))
                return false;
        return s1.empty()&&s2.empty();
    }
};
