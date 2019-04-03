/*
Given a binary tree, return all root-to-leaf paths.
Note: A leaf is a node with no children.

Input:
   1
 /   \
2     3
 \
  5
Output: ["1->2->5", "1->3"]
Explanation: All root-to-leaf paths are: 1->2->5, 1->3
*/

class Solution {
private:
    void backtrack(vector<string> &res, string &path,TreeNode* root){
        path+=((!path.size())?"":"->")+to_string(root->val);
        if(!(root->left)&&!(root->right))
            res.push_back(path);
        else{ 
            if(root->left)
                backtrack(res,path,root->left);
            if(root->right)
                backtrack(res,path,root->right);
        }
        while(path.size() && path.back()>='0' && path.back()<='9') 
            path.pop_back();
        while(path.size() && (path.back()=='>' || path.back()=='-') )
            path.pop_back();
        return;
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string path="";
        if(root)
            backtrack(res,path,root);
        return res;
    }
};
