/*
Given a binary tree, write a function to get the maximum width of the given tree. 
The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, 
but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, 
where the null nodes between the end-nodes are also counted into the length calculation.

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
*/

int widthOfBinaryTree(TreeNode* root) {
    vector<pair<TreeNode*,int>> q;
    int res=0;
    if(!root) return 0;
    q.push_back({root,0});
    while(q.size()){
        int k=q.size();
        vector<pair<TreeNode*,int>> temp;
        res=max(res,q.back().second-q.front().second);
        for(int i=0;i<k;i++){
            if(q[i].first->left)
                temp.push_back({q[i].first->left,q[i].second*2+1});
            if(q[i].first->right)
                temp.push_back({q[i].first->right,q[i].second*2+2});
        }
        q=temp;
        //如果不减小，层数很多时候会越界
        for(int i=q.size()-1;i>=0;i--)
            q[i].second-=q[0].second;
    }
    return res+1;
}
