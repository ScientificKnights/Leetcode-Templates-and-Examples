/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
According to the definition of LCA on Wikipedia: 
“The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants 
(where we allow a node to be a descendant of itself).”
Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //return null, return p or q, return result
        if(root==NULL || root==p || root==q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if((left == p && right ==q) || (left == q && right == p))   return root;
        return left != NULL ? left : right;     // 可能是result 可能是 p q
    }
};


/*
class Solution {
    private:
	bool backtracking(TreeNode* root,vector<TreeNode*> &path,TreeNode* p){
		if(root==p)
			return true;
		if(root->left) {
			path.push_back(root->left);
			if(backtracking(root->left, path, p))   return true;
			path.pop_back();    
        }
        if(root->right) {
			path.push_back(root->right);
			if(backtracking(root->right, path, p))  return true;
			path.pop_back(); 
        }
        return false;
	}

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //O(N)
        if(!root) return NULL;
        vector<TreeNode*> path_p={root}, path_q={root};
        backtracking(root, path_p,p);
        backtracking(root, path_q,q);
        // 1 2 3 4 6
        // 1 2 5 7
        int pos=0;
        TreeNode* res;
        while((pos+1)<path_p.size() &&(pos+1)<path_q.size() && path_p[pos+1]==path_q[pos+1])
                pos++;
        return path_q[pos];

    }
};
*/
