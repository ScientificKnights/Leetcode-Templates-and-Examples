/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
*/

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> s;
    //curr val和左右都没处理；stack 左侧处理，val和右侧没有处理
    //不停的将curr加stack，指向left,
    //没有指向的后，stack pop, 指向右侧
    TreeNode* curr=root;
    while(curr!=NULL || !s.empty()){
        if(curr!=NULL){
            s.push(curr);
            curr=curr->left;
        }
        else{
            res.push_back(s.top()->val);
            curr=s.top()->right;
            s.pop();
        }

    }
    return res;
}
