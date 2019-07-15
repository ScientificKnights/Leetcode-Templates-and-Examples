/*
Return any binary tree that matches the given preorder and postorder traversals.
Values in the traversals pre and post are distinct positive integers.

Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]
 
Note:
1 <= pre.length == post.length <= 30
pre[] and post[] are both permutations of 1, 2, ..., pre.length.
It is guaranteed an answer exists. If there exists multiple answers, you can return any of them.
*/

TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    int i=0;
    stack<TreeNode*> s;
    for(int j=0;j<post.size();j++){
        while(s.empty() || s.top()->val!=post[j]){
            TreeNode* t=new TreeNode(pre[i++]);
            s.push(t);
        }
        TreeNode* temp=s.top();
        s.pop();
        if(s.empty()) return temp;
        if(!s.top()->left)
            s.top()->left=temp;
        else
            s.top()->right=temp;
    }
    return NULL;
}
