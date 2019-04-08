/*
Given an n-ary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
*/
vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> res;
    int level=0;
    queue<Node*> q;
    if(root) q.push(root);
    while(!q.empty()){
        int k=q.size();
        res.push_back({});
        for(int i=0;i<k;i++){
            Node* cur=q.front();
            q.pop();
            res[level].push_back(cur->val);
            for(auto i: cur->children)
                if(i)
                    q.push(i);
        }
        level++;
    }
    return res;
}
