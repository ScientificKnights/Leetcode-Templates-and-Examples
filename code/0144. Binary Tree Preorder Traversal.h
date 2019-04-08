/*
Given a binary tree, return the preorder traversal of its nodes' values.

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> s;
    //先打印root
    //打印curr值 然后将curr的右加入stack, curr指向左侧
    //没有指向的后，指向stack top,pop
    TreeNode* curr=root;
    while(curr!=NULL || !s.empty()){
        if(curr!=NULL){
            res.push_back(curr->val);
            if(curr->right)  s.push(curr->right);
            curr=curr->left;
        }
        else{
            curr=s.top();
            s.pop();
        }

    }
    return res;
}
