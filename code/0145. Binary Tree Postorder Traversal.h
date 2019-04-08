/*
Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> s;
    //先打印root，只比preorder, 最后reverse
    //打印curr值 然后将curr的左加入stack, curr指向右侧
    //没有指向的后，指向stack top,pop
    TreeNode* curr=root;
    while(curr!=NULL || !s.empty()){
        if(curr!=NULL){
            res.push_back(curr->val);
            if(curr->left)  s.push(curr->left);
            curr=curr->right;
        }
        else{
            curr=s.top();
            s.pop();
        }

    }
    reverse(res.begin(),res.end());
    return res;
}
