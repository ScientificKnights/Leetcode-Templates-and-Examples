
[image](https://assets.leetcode.com/uploads/2018/12/14/binarytree.png)

bool backtracking(TreeNode* root,vector<TreeNode*> &path,TreeNode* p){	//dfs+backtrack 找p
	if(root==p) return true;
	//tree 过left，right； vector for loop过后面所有可能（例如698）	
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
